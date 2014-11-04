//You need to program this file.

#include "../NoEdit/VisualizationMono_Algorithm_Integration_VelodyneCameraGPSIMU_PrivFunc.h"

//*******************Please add static libraries below*******************

#pragma comment(lib,"Kernel.lib")

#ifdef _DEBUG

#else

#endif

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	VisualizationMono_Algorithm_Integration_VelodyneCameraGPSIMU_Params * params=(VisualizationMono_Algorithm_Integration_VelodyneCameraGPSIMU_Params *)paramsPtr;
	VisualizationMono_Algorithm_Integration_VelodyneCameraGPSIMU_Vars * vars=(VisualizationMono_Algorithm_Integration_VelodyneCameraGPSIMU_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
	GetParamValue(xmlloader,params,historylength);

	vars->viewer->makeCurrent();
	vars->displaylist=glGenLists(params->historylength+1);
	
	GLuint i;
	for(i=0;i<=params->historylength;i++)
	{
		vars->viewer->addDisplayList(vars->displaylist+i);
	}
	

	Eigen::Matrix4d campos=Eigen::Matrix4d::Identity();
	double pi=3.1415926535897932384626433832795;
	campos.block<3,3>(0,0)=(Eigen::AngleAxisd(-0.4*pi,Eigen::Vector3d::UnitY())*Eigen::AngleAxisd(-0.5*pi,Eigen::Vector3d::UnitZ())).toRotationMatrix();
	campos(0,3)=-5.0;
	campos(2,3)=5.0;
	vars->viewer->setCameraPose(campos);

	vars->viewer->update();

	vars->poses.clear();

	vars->lastpose=Eigen::Matrix4d::Identity();

	vars->index=0;
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	VisualizationMono_Algorithm_Integration_VelodyneCameraGPSIMU_Params * params=(VisualizationMono_Algorithm_Integration_VelodyneCameraGPSIMU_Params *)paramsPtr;
	VisualizationMono_Algorithm_Integration_VelodyneCameraGPSIMU_Vars * vars=(VisualizationMono_Algorithm_Integration_VelodyneCameraGPSIMU_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
	vars->viewer->makeCurrent();
	vars->viewer->clearDisplayList();
	glDeleteLists(vars->displaylist,params->historylength+1);
	vars->displaylist=0;
	vars->viewer->update();
	vars->poses.clear();
	vars->lastpose=Eigen::Matrix4d::Identity();
	vars->index=0;
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	VisualizationMono_Algorithm_Integration_VelodyneCameraGPSIMU_Params * params=(VisualizationMono_Algorithm_Integration_VelodyneCameraGPSIMU_Params *)paramsPtr;
	VisualizationMono_Algorithm_Integration_VelodyneCameraGPSIMU_Vars * vars=(VisualizationMono_Algorithm_Integration_VelodyneCameraGPSIMU_Vars *)varsPtr;
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

void DECOFUNC(getMonoDrainDataSize)(void * paramsPtr, void * varsPtr, int & drainDataSize)
{
	VisualizationMono_Algorithm_Integration_VelodyneCameraGPSIMU_Params * params=(VisualizationMono_Algorithm_Integration_VelodyneCameraGPSIMU_Params *)paramsPtr;
	VisualizationMono_Algorithm_Integration_VelodyneCameraGPSIMU_Vars * vars=(VisualizationMono_Algorithm_Integration_VelodyneCameraGPSIMU_Vars *)varsPtr;
	drainDataSize=0;
	/*======Please Program above======*/
	/*
	Function: get drain data size to be grabbed from buffer.
	Rules:
	drainDataSize=0: grab and remove all data from buffer.
	drainDataSize>0: grab drainDataSize latest data from buffer.
	drainDataSize<0: grab and remove drainDataSize ancient data from buffer.
	*/
}

//Input Port #0: Buffer_Size = 10, Params_Type = ProcessorMulti_Algorithm_Integration_VelodyneCameraGPSIMU_Params, Data_Type = ProcessorMulti_Algorithm_Integration_VelodyneCameraGPSIMU_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
	VisualizationMono_Algorithm_Integration_VelodyneCameraGPSIMU_Params * params=(VisualizationMono_Algorithm_Integration_VelodyneCameraGPSIMU_Params *)paramsPtr;
	VisualizationMono_Algorithm_Integration_VelodyneCameraGPSIMU_Vars * vars=(VisualizationMono_Algorithm_Integration_VelodyneCameraGPSIMU_Vars *)varsPtr;
	QVector<ProcessorMulti_Algorithm_Integration_VelodyneCameraGPSIMU_Params *> drainparams; copyQVector(drainparams,drainParams);
	QVector<ProcessorMulti_Algorithm_Integration_VelodyneCameraGPSIMU_Data *> draindata; copyQVector(draindata,drainData);
	if(draindata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata.
	*/
	if(draindata.size()>params->historylength)
	{
		draindata.resize(params->historylength);
	}
	vars->viewer->makeCurrent();
	int i,n=draindata.size();
	for(i=n-1;i>=0;i--)
	{	
		vars->poses.push_back(draindata[i]->pose);
		if(vars->poses.size()>params->historylength)
		{
			vars->poses.pop_front();
		}

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);

		glVertexPointer(3,GL_FLOAT,sizeof(VelodynePoint),draindata[i]->points.data());
		glColorPointer(3,GL_FLOAT,sizeof(VelodyneColor),draindata[i]->colors.data());
		
		glNewList(vars->displaylist+vars->index,GL_COMPILE);

		glDrawArrays(GL_POINTS,0,draindata[i]->points.size());

		glEndList();
		
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);

		vars->index=(vars->index+1)%(params->historylength);
	}
	glNewList(vars->displaylist+params->historylength,GL_COMPILE);

	glBegin(GL_LINE_STRIP);

	glColor3f(1.0,1.0,1.0);
	n=vars->poses.size();
	for(i=0;i<n;i++)
	{
		glVertex3f(vars->poses[i](0,3),vars->poses[i](1,3),vars->poses[i](2,3));
	}

	glEnd();

	Eigen::Matrix4d ends=Eigen::Matrix4d::Identity();
	ends(3,0)=1;ends(3,1)=1;ends(3,2)=1;
	ends=vars->poses.back()*ends;

	glBegin(GL_LINES);
	glColor3f(1.0,0.0,0.0);
	glVertex3d(ends(0,3),ends(1,3),ends(2,3));
	glVertex3d(ends(0,0),ends(1,0),ends(2,0));
	glColor3f(0.0,1.0,0.0);
	glVertex3d(ends(0,3),ends(1,3),ends(2,3));
	glVertex3d(ends(0,1),ends(1,1),ends(2,1));
	glColor3f(0.0,0.0,1.0);
	glVertex3d(ends(0,3),ends(1,3),ends(2,3));
	glVertex3d(ends(0,2),ends(1,2),ends(2,2));
	glEnd();

	glEndList();

	Eigen::Matrix4d camtrans=vars->poses.back()*vars->lastpose.inverse();
	Eigen::Matrix4d campose=camtrans*vars->viewer->getCameraPose();
	vars->viewer->setCameraPose(campose);
	vars->lastpose=vars->poses.back();

	vars->viewer->update();
	return 1;
}

void DECOFUNC(visualizationWidgets)(void * paramsPtr, void * varsPtr, QList<QWidget *> & widgets)
{
	VisualizationMono_Algorithm_Integration_VelodyneCameraGPSIMU_Params * params=(VisualizationMono_Algorithm_Integration_VelodyneCameraGPSIMU_Params *)paramsPtr;
	VisualizationMono_Algorithm_Integration_VelodyneCameraGPSIMU_Vars * vars=(VisualizationMono_Algorithm_Integration_VelodyneCameraGPSIMU_Vars *)varsPtr;
	widgets=QList<QWidget *>()<<vars->viewer;
	/*======Please Program above======*/
	/*
	Function: get visualization widgets [defined in vars].
	You need to program here when you need visualization widgets.
	E.g.
	widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
	*/
}

