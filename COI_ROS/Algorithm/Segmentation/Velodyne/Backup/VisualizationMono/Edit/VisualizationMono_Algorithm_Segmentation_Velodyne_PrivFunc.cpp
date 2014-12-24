//You need to program this file.

#include "../NoEdit/VisualizationMono_Algorithm_Segmentation_Velodyne_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	VisualizationMono_Algorithm_Segmentation_Velodyne_Params * params=(VisualizationMono_Algorithm_Segmentation_Velodyne_Params *)paramsPtr;
	VisualizationMono_Algorithm_Segmentation_Velodyne_Vars * vars=(VisualizationMono_Algorithm_Segmentation_Velodyne_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    vars->viewer->makeCurrent();
    vars->velodynelist=glGenLists(1);
    vars->viewer->addDisplayList(vars->velodynelist);
    vars->segmentlist=glGenLists(1);
    vars->viewer->addDisplayList(vars->segmentlist);
    vars->linklist=glGenLists(1);
    vars->viewer->addDisplayList(vars->linklist);
    Eigen::Matrix4d camerapose=Eigen::Matrix4d::Identity();
    camerapose(2,3)=10;
    vars->viewer->setCameraPose(camerapose);
    vars->viewer->update();
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	VisualizationMono_Algorithm_Segmentation_Velodyne_Params * params=(VisualizationMono_Algorithm_Segmentation_Velodyne_Params *)paramsPtr;
	VisualizationMono_Algorithm_Segmentation_Velodyne_Vars * vars=(VisualizationMono_Algorithm_Segmentation_Velodyne_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->viewer->makeCurrent();
    vars->viewer->deleteDisplayList(vars->velodynelist);
    glDeleteLists(vars->velodynelist,1);
    vars->viewer->deleteDisplayList(vars->segmentlist);
    glDeleteLists(vars->segmentlist,1);
    vars->viewer->deleteDisplayList(vars->linklist);
    glDeleteLists(vars->linklist,1);
    Eigen::Matrix4d camerapose=Eigen::Matrix4d::Identity();
    camerapose(2,3)=10;
    vars->viewer->setCameraPose(camerapose);
    vars->viewer->update();
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	VisualizationMono_Algorithm_Segmentation_Velodyne_Params * params=(VisualizationMono_Algorithm_Segmentation_Velodyne_Params *)paramsPtr;
	VisualizationMono_Algorithm_Segmentation_Velodyne_Vars * vars=(VisualizationMono_Algorithm_Segmentation_Velodyne_Vars *)varsPtr;
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
	VisualizationMono_Algorithm_Segmentation_Velodyne_Params * params=(VisualizationMono_Algorithm_Segmentation_Velodyne_Params *)paramsPtr;
	VisualizationMono_Algorithm_Segmentation_Velodyne_Vars * vars=(VisualizationMono_Algorithm_Segmentation_Velodyne_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 0, Params_Type = ProcessorMono_Algorithm_Segmentation_Velodyne_Params, Data_Type = ProcessorMono_Algorithm_Segmentation_Velodyne_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
	VisualizationMono_Algorithm_Segmentation_Velodyne_Params * params=(VisualizationMono_Algorithm_Segmentation_Velodyne_Params *)paramsPtr;
	VisualizationMono_Algorithm_Segmentation_Velodyne_Vars * vars=(VisualizationMono_Algorithm_Segmentation_Velodyne_Vars *)varsPtr;
	QVector<ProcessorMono_Algorithm_Segmentation_Velodyne_Params *> drainparams; copyQVector(drainparams,drainParams);
	QVector<ProcessorMono_Algorithm_Segmentation_Velodyne_Data *> draindata; copyQVector(draindata,drainData);
	if(draindata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata.
	*/
    vars->tabwidget->setTabText(0,draindata[0]->timestamp.toString("HH:mm:ss:zzz"));

    vars->viewer->makeCurrent();

//    {
//        glEnableClientState(GL_VERTEX_ARRAY);
//        glEnableClientState(GL_COLOR_ARRAY);

//        void * pointsptr=(void *)(draindata[0]->pclpoints->points.data());
//        glVertexPointer(3,GL_FLOAT,sizeof(pcl::PointXYZI),pointsptr);

//        void * colorsptr=pointsptr+sizeof(pcl::PointXYZ)+sizeof(float);
//        glColorPointer(3,GL_FLOAT,sizeof(pcl::PointXYZI),colorsptr);

//        glNewList(vars->velodynelist,GL_COMPILE);

//        int pointsnum=draindata[0]->pclpoints->size();
//        glDrawArrays(GL_POINTS,0,pointsnum);

//        glEndList();

//        glDisableClientState(GL_VERTEX_ARRAY);
//        glDisableClientState(GL_COLOR_ARRAY);
//    }

    {
        float color[6][3]={{1.0,0.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{1.0,1.0,0.0},{1.0,0.0,1.0},{0.0,1.0,1.0}};
        int i,n=draindata[0]->segments.size();
        glNewList(vars->segmentlist,GL_COMPILE);
        for(i=0;i<n;i++)
        {
            int colorid=i%6;
            glColor3f(color[colorid][0],color[colorid][1],color[colorid][2]);

            glEnableClientState(GL_VERTEX_ARRAY);

            void * pointsptr=(void *)(draindata[0]->segments[i]->points.data());
            glVertexPointer(3,GL_FLOAT,sizeof(pcl::PointXYZI),pointsptr);

            int pointsnum=draindata[0]->segments[i]->points.size();
            glDrawArrays(GL_POINTS,0,pointsnum);

            glDisableClientState(GL_VERTEX_ARRAY);
        }
        glEndList();
    }

//    {
//        glNewList(vars->linklist,GL_COMPILE);

//        glBegin(GL_POINTS);
//        int i,n=draindata[0]->graph.size();
//        glColor3f(1.0,1.0,1.0);
//        for(i=0;i<n;i++)
//        {
//            glVertex3f(draindata[0]->graph[i].point.at<float>(0),draindata[0]->graph[i].point.at<float>(1),draindata[0]->graph[i].point.at<float>(2));
//        }
//        glEnd();

//        glBegin(GL_LINES);
//        glColor3f(1.0,0.0,0.0);
//        for(i=0;i<n;i++)
//        {
//            if(draindata[0]->graph[i].valid)
//            {
//                int k;
//                for(k=0;k<4;k++)
//                {
//                    int id=draindata[0]->graph[i].connect[k];
//                    if(id>=0)
//                    {
//                        glVertex3f(draindata[0]->graph[i].point.at<float>(0),draindata[0]->graph[i].point.at<float>(1),draindata[0]->graph[i].point.at<float>(2));
//                        glVertex3f(draindata[0]->graph[id].point.at<float>(0),draindata[0]->graph[id].point.at<float>(1),draindata[0]->graph[id].point.at<float>(2));
//                    }
//                }
//            }
//        }
//        glEnd();

//        glEndList();
//    }

//    {
//        glNewList(vars->velodynelist,GL_COMPILE);

//        glBegin(GL_LINES);
//        int i,n=draindata[0]->graph.size();
//        glColor3f(0.0,1.0,0.0);
//        for(i=0;i<n;i++)
//        {
//            if(draindata[0]->graph[i].valid)
//            {
//                glVertex3f(draindata[0]->graph[i].point.at<float>(0),draindata[0]->graph[i].point.at<float>(1),draindata[0]->graph[i].point.at<float>(2));
//                glVertex3f(draindata[0]->graph[i].point.at<float>(0)+draindata[0]->graph[i].normal.at<float>(0)
//                        ,draindata[0]->graph[i].point.at<float>(1)+draindata[0]->graph[i].normal.at<float>(1)
//                        ,draindata[0]->graph[i].point.at<float>(2)+draindata[0]->graph[i].normal.at<float>(2));
//            }
//        }
//        glEnd();

//        glEndList();
//    }
    vars->viewer->update();

	return 1;
}

void DECOFUNC(visualizationWidgets)(void * paramsPtr, void * varsPtr, QList<QWidget *> & widgets)
{
	VisualizationMono_Algorithm_Segmentation_Velodyne_Params * params=(VisualizationMono_Algorithm_Segmentation_Velodyne_Params *)paramsPtr;
	VisualizationMono_Algorithm_Segmentation_Velodyne_Vars * vars=(VisualizationMono_Algorithm_Segmentation_Velodyne_Vars *)varsPtr;
    widgets=QList<QWidget *>()<<(vars->tabwidget);
	/*======Please Program above======*/
	/*
	Function: get visualization widgets [defined in vars].
	You need to program here when you need visualization widgets.
	E.g.
	widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
	*/
}

