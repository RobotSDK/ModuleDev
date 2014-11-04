//You need to program this file.

#include "../NoEdit/Simulator_Sensor_Camera_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

inline void DECOFUNC(loadParams)(cv::Mat & mat, QStringList & values)
{
    int i,j;
    for(i=0;i<mat.rows;i++)
    {
        for(j=0;j<mat.cols;j++)
        {
            mat.at<float>(i,j)=values.at(i*mat.cols+j).toFloat();
        }
    }
}

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	Simulator_Sensor_Camera_Params * params=(Simulator_Sensor_Camera_Params *)paramsPtr;
	Simulator_Sensor_Camera_Vars * vars=(Simulator_Sensor_Camera_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader,vars,cameracalibfile);
    GetParamValue(xmlloader,vars,datadir);
    GetParamValue(xmlloader,params,cameraid);

    QFile file;
    QDir dir;

    file.setFileName(vars->cameracalibfile);
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

        if(prefix.startsWith(QString("S_%1").arg(params->cameraid,2,10,QChar('0'))))
        {
            params->size.width=int(values.at(0).toDouble());
            params->size.height=int(values.at(1).toDouble());
        }
        else if(prefix.startsWith(QString("K_%1").arg(params->cameraid,2,10,QChar('0'))))
        {
            DECOFUNC(loadParams)(params->calibmat,values);
        }
        else if(prefix.startsWith(QString("D_%1").arg(params->cameraid,2,10,QChar('0'))))
        {
            DECOFUNC(loadParams)(params->distcoef,values);
        }
        else if(prefix.startsWith(QString("R_%1").arg(params->cameraid,2,10,QChar('0'))))
        {
            DECOFUNC(loadParams)(params->rotation,values);
        }
        else if(prefix.startsWith(QString("T_%1").arg(params->cameraid,2,10,QChar('0'))))
        {
            DECOFUNC(loadParams)(params->translation,values);
        }
        else if(prefix.startsWith(QString("S_rect_%1").arg(params->cameraid,2,10,QChar('0'))))
        {
            params->rectsize.width=int(values.at(0).toDouble());
            params->rectsize.height=int(values.at(1).toDouble());
        }
        else if(prefix.startsWith(QString("R_rect_%1").arg(params->cameraid,2,10,QChar('0'))))
        {
            if(params->cameraid==0)
            {
                params->refcamrectrot=cv::Mat::eye(4,4,CV_32F);
                params->rectrotation=params->refcamrectrot(cv::Rect(0,0,3,3));
            }
            DECOFUNC(loadParams)(params->rectrotation,values);
        }
        else if(prefix.startsWith(QString("P_rect_%1").arg(params->cameraid,2,10,QChar('0'))))
        {
            DECOFUNC(loadParams)(params->rectprojection,values);
        }
        else if(prefix.startsWith("R_rect_00"))
        {
            params->refcamrectrot=cv::Mat::eye(4,4,CV_32F);
            cv::Mat rectrotation=params->refcamrectrot(cv::Rect(0,0,3,3));
            DECOFUNC(loadParams)(rectrotation,values);
        }
    }
    file.close();

    dir.setPath(vars->datadir);
    if(!dir.exists())
    {
        return 0;
    }

    file.setFileName(QString("%1/image_%2/timestamps.txt").arg(vars->datadir).arg(params->cameraid,2,10,QChar('0')));
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

    dir.setPath(QString("%1/image_%2/data").arg(vars->datadir).arg(params->cameraid,2,10,QChar('0')));
    vars->imagefilelist=dir.entryInfoList(QDir::Files | QDir::Hidden | QDir::NoSymLinks);

    if(vars->timestamps.size()!=vars->imagefilelist.size())
    {
        return 0;
    }

    vars->fileindex=0;
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	Simulator_Sensor_Camera_Params * params=(Simulator_Sensor_Camera_Params *)paramsPtr;
	Simulator_Sensor_Camera_Vars * vars=(Simulator_Sensor_Camera_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->timestamps.clear();
    vars->imagefilelist.clear();
    vars->fileindex=-1;
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	Simulator_Sensor_Camera_Params * params=(Simulator_Sensor_Camera_Params *)paramsPtr;
	Simulator_Sensor_Camera_Vars * vars=(Simulator_Sensor_Camera_Vars *)varsPtr;
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
	Simulator_Sensor_Camera_Params * params=(Simulator_Sensor_Camera_Params *)paramsPtr;
	Simulator_Sensor_Camera_Vars * vars=(Simulator_Sensor_Camera_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new Simulator_Sensor_Camera_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
	Simulator_Sensor_Camera_Params * params=(Simulator_Sensor_Camera_Params *)paramsPtr;
	Simulator_Sensor_Camera_Vars * vars=(Simulator_Sensor_Camera_Vars *)varsPtr;
	Simulator_Sensor_Camera_Data * outputdata=(Simulator_Sensor_Camera_Data *)outputData;
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
    outputdata->image=cv::imread(vars->imagefilelist.at(vars->fileindex).absoluteFilePath().toStdString());
    timeStamp=outputdata->timestamp;
    vars->fileindex++;
	return 1;
}

