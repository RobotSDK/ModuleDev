//You need to program this file.

#include "../NoEdit/Simulator_Algorithm_SLAM_Velodyne_ScanMatching_PrivFunc.h"

//*******************Please add static libraries below*******************

#pragma comment(lib,"Kernel.lib")

#ifdef _DEBUG

#else

#endif

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
	Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Params * params=(Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Params *)paramsPtr;
	Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Vars * vars=(Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
	GetParamValue(xmlloader,vars,calibfile);
	GetParamValue(xmlloader,vars,datadir);

	QFile file;
	QDir dir;

	file.setFileName(vars->calibfile);
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
			DECOFUNC(loadParams)(params->rotation,values);
		}
		else if(prefix.startsWith(QString("T")))
		{
			DECOFUNC(loadParams)(params->translation,values);
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

	file.setFileName(QString("%1/velodyne_points/pos/pos").arg(vars->datadir));
	if(!file.exists()||!file.open(QIODevice::ReadOnly|QIODevice::Text))
	{
		return 0;
	}
	vars->poses.clear();
	QTextStream stream(&file);
	while(!stream.atEnd())
	{
		SLAMPOSE pose;
		stream>>pose.x>>pose.y>>pose.z;
		stream>>pose.roll>>pose.pitch>>pose.yaw;
		vars->poses.push_back(pose);
	}
	file.close();
	if(vars->poses.size()==0)
	{
		return 0;
	}

	vars->index=0;
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Params * params=(Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Params *)paramsPtr;
	Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Vars * vars=(Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
	
	vars->timestamps.clear();
	vars->poses.clear();
	vars->index=-1;
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Params * params=(Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Params *)paramsPtr;
	Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Vars * vars=(Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Vars *)varsPtr;
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
	Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Params * params=(Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Params *)paramsPtr;
	Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Vars * vars=(Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
	Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Params * params=(Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Params *)paramsPtr;
	Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Vars * vars=(Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Vars *)varsPtr;
	Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Data * outputdata=(Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Data *)outputData;
	outputPortIndex=QList<int>();
	timeStamp=QTime();
	/*======Please Program below======*/
	/*
	Step 1: fill outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	Step 3: set the timeStamp for Simulator.
	*/
	if(vars->index>=vars->timestamps.size())
	{
		return 0;
	}

	outputdata->timestamp=vars->timestamps.at(vars->index);
	outputdata->x=vars->poses.at(vars->index).x;
	outputdata->y=vars->poses.at(vars->index).y;
	outputdata->z=vars->poses.at(vars->index).z;
	outputdata->roll=vars->poses.at(vars->index).roll;
	outputdata->pitch=vars->poses.at(vars->index).pitch;
	outputdata->yaw=vars->poses.at(vars->index).yaw;

	outputdata->pose=Eigen::Matrix4d::Identity();
	outputdata->pose(0,3)=outputdata->x;
	outputdata->pose(1,3)=outputdata->y;
	outputdata->pose(2,3)=outputdata->z;
	outputdata->pose.block<3,3>(0,0) = (Eigen::AngleAxisd(outputdata->yaw, Eigen::Vector3d::UnitZ())
		*Eigen::AngleAxisd(outputdata->pitch,  Eigen::Vector3d::UnitY())
		*Eigen::AngleAxisd(outputdata->roll, Eigen::Vector3d::UnitX())).toRotationMatrix();

	timeStamp=outputdata->timestamp;
	vars->index++;
	return 1;
}

