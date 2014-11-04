//You need to program this file.

#include "../NoEdit/Simulator_Sensor_Velodyne_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

#include<qdebug.h>

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	Simulator_Sensor_Velodyne_Params * params=(Simulator_Sensor_Velodyne_Params *)paramsPtr;
	Simulator_Sensor_Velodyne_Vars * vars=(Simulator_Sensor_Velodyne_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
	
    GetParamValue(xmlloader,params,velodynecalibfile);
    GetParamValue(xmlloader,vars,datadir);

    QFile file;
    QDir dir;

    file.setFileName(params->velodynecalibfile);
    if(!file.exists()||!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return 0;
    }
    while(!file.atEnd())
    {
        QString tmpstr=file.readLine();
        int tmpindex=tmpstr.indexOf(":");
        if(tmpindex<0)
        {
            continue;
        }
        QString prefix=tmpstr.left(tmpindex).trimmed();
        QString suffix=tmpstr.mid(tmpindex+1).trimmed();
        QStringList values=suffix.split(QChar(' '),QString::SkipEmptyParts);

        if(prefix.startsWith(QString("R")))
        {
            int i,n=values.size();
            for(i=0;i<n;i++)
            {
                int row=i/3;
                int col=i%3;
                params->calib2camera(row,col)=values[i].toFloat();
            }
        }
        else if(prefix.startsWith(QString("T")))
        {
            int i,n=values.size();
            for(i=0;i<n;i++)
            {
                params->calib2camera(i,3)=values[i].toFloat();
            }
        }
    }
    file.close();

    dir.setPath(vars->datadir);
    if(!dir.exists())
    {
        return 0;
    }

    file.setFileName(QString("%1/velodyne_points/timestamps.txt").arg(vars->datadir));
    if(!file.exists()||!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return 0;
    }
    vars->timestamps.clear();
    while(!file.atEnd())
    {
        QString tmpstr=file.readLine();
        int tmpindex=tmpstr.indexOf(" ");
        QStringList tmpqls=tmpstr.mid(tmpindex+1).split(":");
        if(tmpqls.size()<3)
        {
            continue;
        }
        int h=tmpqls.at(0).toInt();
        int m=tmpqls.at(1).toInt();
        int tmpi=int(tmpqls.at(2).toDouble()*1000+0.5);
        int s=tmpi/1000;
        int ms=tmpi%1000;
        vars->timestamps.push_back(QTime(h,m,s,ms));
    }
    file.close();
    if(vars->timestamps.size()==0)
    {
        return 0;
    }

    file.setFileName(QString("%1/velodyne_points/timestamps_start.txt").arg(vars->datadir));
    if(!file.exists()||!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return 0;
    }
    vars->starttimes.clear();
    while(!file.atEnd())
    {
        QString tmpstr=file.readLine();
        int tmpindex=tmpstr.indexOf(" ");
        QStringList tmpqls=tmpstr.mid(tmpindex+1).split(":");
        if(tmpqls.size()<3)
        {
            continue;
        }
        int h=tmpqls.at(0).toInt();
        int m=tmpqls.at(1).toInt();
        int tmpi=int(tmpqls.at(2).toDouble()*1000+0.5);
        int s=tmpi/1000;
        int ms=tmpi%1000;
        vars->starttimes.push_back(QTime(h,m,s,ms));
    }
    file.close();
    if(vars->starttimes.size()!=vars->timestamps.size())
    {
        return 0;
    }


    file.setFileName(QString("%1/velodyne_points/timestamps_end.txt").arg(vars->datadir));
    if(!file.exists()||!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return 0;
    }
    vars->endtimes.clear();
    while(!file.atEnd())
    {
        QString tmpstr=file.readLine();
        int tmpindex=tmpstr.indexOf(" ");
        QStringList tmpqls=tmpstr.mid(tmpindex+1).split(":");
        if(tmpqls.size()<3)
        {
            continue;
        }
        int h=tmpqls.at(0).toInt();
        int m=tmpqls.at(1).toInt();
        int tmpi=int(tmpqls.at(2).toDouble()*1000+0.5);
        int s=tmpi/1000;
        int ms=tmpi%1000;
        vars->endtimes.push_back(QTime(h,m,s,ms));
    }
    file.close();
    if(vars->endtimes.size()!=vars->timestamps.size())
    {
        return 0;
    }

    dir.setPath(QString("%1/velodyne_points/data").arg(vars->datadir));
    vars->velodynefilelist=dir.entryInfoList(QDir::Files | QDir::Hidden | QDir::NoSymLinks);

    if(vars->velodynefilelist.size()!=vars->timestamps.size())
    {
        return 0;
    }

    vars->fileindex=0;

	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	Simulator_Sensor_Velodyne_Params * params=(Simulator_Sensor_Velodyne_Params *)paramsPtr;
	Simulator_Sensor_Velodyne_Vars * vars=(Simulator_Sensor_Velodyne_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->timestamps.clear();
    vars->starttimes.clear();
    vars->endtimes.clear();
    vars->velodynefilelist.clear();
    vars->fileindex=-1;
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	Simulator_Sensor_Velodyne_Params * params=(Simulator_Sensor_Velodyne_Params *)paramsPtr;
	Simulator_Sensor_Velodyne_Vars * vars=(Simulator_Sensor_Velodyne_Vars *)varsPtr;
	internalTrigger=NULL;
	internalTriggerSignal=QString();
	/*======Occasionally Program above======*/
	/*
	Function: get internal trigger [defined in vars] for node.
	You need to program here when you need internal trigger (internalTrigger + internalTriggerSignal) for node.
	E.g.
	internalTrigger=&(vars->trigger);
	internalTriggerSignal=QString(SIGNAL(triggerSignal()));
	*/
}

void DECOFUNC(initializeOutputData)(void * paramsPtr, void * varsPtr, boost::shared_ptr<void> & outputDataPtr)
{
	Simulator_Sensor_Velodyne_Params * params=(Simulator_Sensor_Velodyne_Params *)paramsPtr;
	Simulator_Sensor_Velodyne_Vars * vars=(Simulator_Sensor_Velodyne_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new Simulator_Sensor_Velodyne_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/

}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
	Simulator_Sensor_Velodyne_Params * params=(Simulator_Sensor_Velodyne_Params *)paramsPtr;
	Simulator_Sensor_Velodyne_Vars * vars=(Simulator_Sensor_Velodyne_Vars *)varsPtr;
	Simulator_Sensor_Velodyne_Data * outputdata=(Simulator_Sensor_Velodyne_Data *)outputData;
	outputPortIndex=QList<int>();
	timeStamp=QTime();
	/*======Please Program below======*/
	/*
	Step 1: fill outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	Step 3: set the timeStamp for Simulator.
    */
    if(vars->fileindex>=vars->timestamps.size())
    {
        return 0;
    }
    outputdata->timestamp=vars->timestamps.at(vars->fileindex);
    outputdata->starttime=vars->starttimes.at(vars->fileindex);
    outputdata->endtime=vars->endtimes.at(vars->fileindex);

    QFile file(vars->velodynefilelist.at(vars->fileindex).absoluteFilePath());
    if(!file.open(QIODevice::ReadOnly))
    {
        return 0;
    }


    int filesize=file.size();
    int pointnum=filesize/(4*sizeof(float));
    outputdata->cloud->resize(pointnum);
    memcpy((char *)(outputdata->cloud->points.data()),file.readAll().data(),filesize);
    file.close();

    timeStamp=outputdata->timestamp;
    vars->fileindex++;
	return 1;
}

