//You need to program this file.

#include "../NoEdit/VisualizationMulti_Visualization_Integration_GroundObjectsDBM_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Params * params=(VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Params *)paramsPtr;
	VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Vars * vars=(VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader,vars,radius);
    GetParamValue(xmlloader,vars,thickness);
    GetParamValue(xmlloader,vars,range);
    vars->image->setText("Open");
    vars->init=1;
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Params * params=(VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Params *)paramsPtr;
	VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Vars * vars=(VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->image->setText("Closed");
    vars->init=0;
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Params * params=(VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Params *)paramsPtr;
	VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Vars * vars=(VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Vars *)varsPtr;
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

void DECOFUNC(getMultiDrainDataSize)(void * paramsPtr, void * varsPtr, QList<int> & drainDataSize)
{
	VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Params * params=(VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Params *)paramsPtr;
	VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Vars * vars=(VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Vars *)varsPtr;
    drainDataSize=QList<int>()<<-1<<-1;
	/*======Please Program above======*/
	/*
	Function: get drain data size to be grabbed from buffer.
	Rules:
	drainDataSize=0: grab and remove all data from buffer.
	drainDataSize>0: grab drainDataSize latest data from buffer.
	drainDataSize<0: grab and remove drainDataSize ancient data from buffer.
	E.g.
	drainDataSize=QList<int>()<<0<<1<<-1...;
	*/
}

//Input Port #0: Buffer_Size = 0, Params_Type = ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params, Data_Type = ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Data
//Input Port #1: Buffer_Size = 0, Params_Type = ProcessorMono_Algorithm_Detection_Camera_DBM_Params, Data_Type = ProcessorMono_Algorithm_Detection_Camera_DBM_Data
bool DECOFUNC(processMultiDrainData)(void * paramsPtr, void * varsPtr, QVector<QVector<void *> > drainParams, QVector<QVector<void *> > drainData)
{
	VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Params * params=(VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Params *)paramsPtr;
	VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Vars * vars=(VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Vars *)varsPtr;
	QVector<ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params *> drainparams_0; copyQVector(drainparams_0,drainParams[0]);
	QVector<ProcessorMono_Algorithm_Detection_Camera_DBM_Params *> drainparams_1; copyQVector(drainparams_1,drainParams[1]);
	QVector<ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Data *> draindata_0; copyQVector(draindata_0,drainData[0]);
	QVector<ProcessorMono_Algorithm_Detection_Camera_DBM_Data *> draindata_1; copyQVector(draindata_1,drainData[1]);
	if(draindata_0.size()==0){return 0;}
	if(draindata_1.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata_index.
	*/
    if(vars->init)
    {
        cv::Mat T=cv::Mat::eye(4,4,CV_32F);

        int i,j;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                T.at<float>(i,j)=drainparams_0[0]->calib2camera(i,j);
            }
        }

        cv::Mat R=drainparams_1[0]->refcamrectrot;
        cv::Mat P=drainparams_1[0]->rectprojection;

        vars->FP=P*R*T;
        vars->init=0;
    }

    int pointnum=draindata_0[0]->ground->size();
    cv::Mat veldata=cv::Mat(pointnum,4,CV_32F,draindata_0[0]->ground->points.data(),sizeof(pcl::PointXYZ));
    cv::Mat velpoints=cv::Mat::ones(pointnum,4,CV_32F);
    cv::Mat tmppoints=velpoints(cv::Rect(0,0,3,pointnum));
    veldata(cv::Rect(0,0,3,pointnum)).copyTo(tmppoints);
    cv::Mat groundimgpoint=velpoints*vars->FP.t();

    cv::Rect rectimage=cv::Rect(0,0,drainparams_1[0]->rectsize.width-1,drainparams_1[0]->rectsize.height-1);
    cv::Mat image=draindata_1[0]->image.clone();

    int i,n=groundimgpoint.rows;
    float maxscale=0;
    for(i=0;i<n;i++)
    {
        if(maxscale<groundimgpoint.at<float>(i,2))
        {
            maxscale=groundimgpoint.at<float>(i,2);
        }
    }

    for(i=0;i<n;i++)
    {
        float scale=groundimgpoint.at<float>(i,2);
        if(scale>0)
        {
            int tmpi=int(scale/maxscale*255.0);
            uchar r=vars->groundcolormap.at<cv::Vec3b>(tmpi/16,tmpi%16)[0];
            uchar g=vars->groundcolormap.at<cv::Vec3b>(tmpi/16,tmpi%16)[1];
            uchar b=vars->groundcolormap.at<cv::Vec3b>(tmpi/16,tmpi%16)[2];
            cv::Point2f drawpoint=cv::Point2f(groundimgpoint.at<float>(i,0)/scale,groundimgpoint.at<float>(i,1)/scale);
            if(drawpoint.inside(rectimage))
            {
                switch(image.channels())
                {
                case 1:
                    cv::circle(image,drawpoint,vars->radius,cv::Scalar(r),-1);
                case 3:
                    cv::circle(image,drawpoint,vars->radius,cv::Scalar(r,g,b),-1);
                default:
                    continue;
                }
            }
        }
    }

    pointnum=draindata_0[0]->objects->size();
    veldata=cv::Mat(pointnum,4,CV_32F,draindata_0[0]->objects->points.data(),sizeof(pcl::PointXYZ));
    velpoints=cv::Mat::ones(pointnum,4,CV_32F);
    tmppoints=velpoints(cv::Rect(0,0,3,pointnum));
    veldata(cv::Rect(0,0,3,pointnum)).copyTo(tmppoints);
    cv::Mat objectsimgpoint=velpoints*vars->FP.t();

    n=objectsimgpoint.rows;    
    maxscale=0;
    for(i=0;i<n;i++)
    {
        if(maxscale<objectsimgpoint.at<float>(i,2))
        {
            maxscale=objectsimgpoint.at<float>(i,2);
        }
    }

    for(i=0;i<n;i++)
    {
        float scale=objectsimgpoint.at<float>(i,2);
        if(scale>0)
        {
            int tmpi=int(scale/maxscale*255.0);
            uchar r=vars->objectcolormap.at<cv::Vec3b>(tmpi/16,tmpi%16)[0];
            uchar g=vars->objectcolormap.at<cv::Vec3b>(tmpi/16,tmpi%16)[1];
            uchar b=vars->objectcolormap.at<cv::Vec3b>(tmpi/16,tmpi%16)[2];
            cv::Point2f drawpoint=cv::Point2f(objectsimgpoint.at<float>(i,0)/scale,objectsimgpoint.at<float>(i,1)/scale);
            if(drawpoint.inside(rectimage))
            {
                switch(image.channels())
                {
                case 1:
                    cv::circle(image,drawpoint,vars->radius,cv::Scalar(r),-1);
                case 3:
                    cv::circle(image,drawpoint,vars->radius,cv::Scalar(r,g,b),-1);
                default:
                    continue;
                }
            }
        }
    }

    if(image.type()==CV_8UC1)
    {
        QImage img(image.data, image.cols, image.rows, image.step, QImage::Format_Indexed8);
        img.setColorTable(vars->colorTable);
        vars->image->setPixmap(QPixmap::fromImage(img));
    }
    else if(image.type()==CV_8UC3)
    {
        QImage img(image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);
        img=img.rgbSwapped();
        vars->image->setPixmap(QPixmap::fromImage(img));
    }
    else
    {
        vars->image->setText("Not Supported");
        return 0;
    }

    if(image.type()==CV_8UC1)
    {
        int i,n=draindata_1.front()->objects.size();
        for(i=0;i<n;i++)
        {
            cv::rectangle(image,draindata_1.front()->objects[i].rect,cv::Scalar(255),vars->thickness);
        }
        QImage img(image.data, image.cols, image.rows, image.step, QImage::Format_Indexed8);
        img.setColorTable(vars->colorTable);
        vars->image->setPixmap(QPixmap::fromImage(img));

        return 1;
    }
    else if(image.type()==CV_8UC3)
    {
        int i,n=draindata_1.front()->objects.size();
        for(i=0;i<n;i++)
        {
            int colorindex=draindata_1.front()->objects[i].classID % 6;
            cv::rectangle(image,draindata_1.front()->objects[i].rect,vars->boxcolors[colorindex],vars->thickness);
            cv::line(image,cv::Point(draindata_1.front()->objects[i].rect.x,draindata_1.front()->objects[i].rect.y)
                ,cv::Point(draindata_1.front()->objects[i].rect.x+draindata_1.front()->objects[i].rect.width,draindata_1.front()->objects[i].rect.y+draindata_1.front()->objects[i].rect.height)
                ,vars->boxcolors[colorindex],vars->thickness);
            cv::line(image,cv::Point(draindata_1.front()->objects[i].rect.x+draindata_1.front()->objects[i].rect.width,draindata_1.front()->objects[i].rect.y)
                ,cv::Point(draindata_1.front()->objects[i].rect.x,draindata_1.front()->objects[i].rect.y+draindata_1.front()->objects[i].rect.height)
                ,vars->boxcolors[colorindex],vars->thickness);
        }
        QImage img(image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);
        img=img.rgbSwapped();
        vars->image->setPixmap(QPixmap::fromImage(img));
        return 1;
    }
    else
    {
        vars->image->setText("Not Supported");
        return 0;
    }

	return 1;
}

void DECOFUNC(visualizationWidgets)(void * paramsPtr, void * varsPtr, QList<QWidget *> & widgets)
{
	VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Params * params=(VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Params *)paramsPtr;
	VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Vars * vars=(VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Vars *)varsPtr;
    widgets=QList<QWidget *>()<<vars->image;
	/*======Please Program above======*/
	/*
	Function: get visualization widgets [defined in vars].
	You need to program here when you need visualization widgets.
	E.g.
	widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
	*/
}

