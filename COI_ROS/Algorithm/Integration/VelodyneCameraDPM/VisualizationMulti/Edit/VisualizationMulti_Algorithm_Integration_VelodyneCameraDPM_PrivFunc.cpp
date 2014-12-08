//You need to program this file.

#include "../NoEdit/VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Params * params=(VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Params *)paramsPtr;
	VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Vars * vars=(VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader,vars,maxrange);
    GetParamValue(xmlloader,vars,minrange);

    vars->viewer->setText("Open");
    vars->velodynecamerabuffer.clear();
    vars->dpmbuffer.clear();
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Params * params=(VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Params *)paramsPtr;
	VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Vars * vars=(VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->viewer->setText("Closed");
    vars->velodynecamerabuffer.clear();
    vars->dpmbuffer.clear();
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Params * params=(VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Params *)paramsPtr;
	VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Vars * vars=(VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Vars *)varsPtr;
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
	VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Params * params=(VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Params *)paramsPtr;
	VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Vars * vars=(VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Vars *)varsPtr;
    drainDataSize=QList<int>()<<0<<0;
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

//Input Port #0: Buffer_Size = 0, Params_Type = ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params, Data_Type = ProcessorMulti_Algorithm_Integration_VelodyneCamera_Data
//Input Port #1: Buffer_Size = 0, Params_Type = SensorInternalEvent_Algorithm_Detection_DPM_Params, Data_Type = SensorInternalEvent_Algorithm_Detection_DPM_Data
bool DECOFUNC(processMultiDrainData)(void * paramsPtr, void * varsPtr, QVector<QVector<void *> > drainParams, QVector<QVector<void *> > drainData)
{
	VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Params * params=(VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Params *)paramsPtr;
	VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Vars * vars=(VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Vars *)varsPtr;
	QVector<ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params *> drainparams_0; copyQVector(drainparams_0,drainParams[0]);
	QVector<SensorInternalEvent_Algorithm_Detection_DPM_Params *> drainparams_1; copyQVector(drainparams_1,drainParams[1]);
	QVector<ProcessorMulti_Algorithm_Integration_VelodyneCamera_Data *> draindata_0; copyQVector(draindata_0,drainData[0]);
	QVector<SensorInternalEvent_Algorithm_Detection_DPM_Data *> draindata_1; copyQVector(draindata_1,drainData[1]);
//	if(draindata_0.size()==0){return 0;}
//	if(draindata_1.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata_index.
	*/
    int i,n=draindata_0.size();
    for(i=n-1;i>=0;i--)
    {
        VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Vars::VelodyneCameraBufferData data;
        data.cameratimestamp=draindata_0[i]->cameratimestamp;
        data.cvimage=draindata_0[i]->cvimage.clone();
        data.ranges=draindata_0[i]->ranges;
        vars->velodynecamerabuffer.push_back(data);
    }

    int j,m=draindata_1.size();
    for(j=m-1;j>=0;j--)
    {
        VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Vars::DPMBufferData data;
        data.timestamp=draindata_1[j]->timestamp;
        data.cvdetection=draindata_1[j]->cvdetection;
        vars->dpmbuffer.push_back(data);
    }

    i=0;n=vars->velodynecamerabuffer.size();
    j=0;m=vars->dpmbuffer.size();
    if(n==0||m==0)
    {
        return 0;
    }
    int delta=0;
    while(i<n&&j<m)
    {
        QTime cameratimestamp=vars->velodynecamerabuffer[i].cameratimestamp;
        QTime dpmtimestamp=vars->dpmbuffer[j].timestamp;
        int tmpdelta=cameratimestamp.msecsTo(dpmtimestamp);
        if(tmpdelta!=0)
        {
            if(delta==0)
            {
                delta=tmpdelta;
                if(tmpdelta>0)
                {
                    i++;
                }
                else
                {
                    j++;
                }
            }
            else
            {
                if(abs(tmpdelta)<abs(delta))
                {
                    delta=tmpdelta;
                    if(tmpdelta>0)
                    {
                        i++;
                    }
                    else
                    {
                        j++;
                    }
                }
                else
                {
                    if(delta>0)
                    {
                        i--;
                    }
                    else
                    {
                        j--;
                    }
                    break;
                }
            }
        }
        else
        {
            break;
        }
    }
    if(i==n)
    {
        vars->velodynecamerabuffer.erase(vars->velodynecamerabuffer.begin(),vars->velodynecamerabuffer.begin()+i-1);
        vars->dpmbuffer.erase(vars->dpmbuffer.begin(),vars->dpmbuffer.begin()+j);
        return 0;
    }
    if(j==m)
    {
        vars->velodynecamerabuffer.erase(vars->velodynecamerabuffer.begin(),vars->velodynecamerabuffer.begin()+i);
        vars->dpmbuffer.erase(vars->dpmbuffer.begin(),vars->dpmbuffer.begin()+j-1);
        return 0;
    }

    vars->tabwidget->setTabText(0,vars->velodynecamerabuffer[i].cameratimestamp.toString("HH:mm:ss:zzz"));

    cv::Mat image=vars->velodynecamerabuffer[i].cvimage;

    if(image.type()==CV_8UC3)
    {
        int row,col;
        for(row=0;row<image.rows;row++)
        {
            for(col=0;col<image.cols;col++)
            {
                int id=row*image.cols+col;
                if(vars->velodynecamerabuffer[i].ranges[id]>vars->minrange&&vars->velodynecamerabuffer[i].ranges[id]<=vars->maxrange)
                {
                    int colorid=int((vars->velodynecamerabuffer[i].ranges[id]-vars->minrange)/(vars->maxrange-vars->minrange)*255+0.5);
                    cv::Vec3b color=vars->colormap.at<cv::Vec3b>(colorid);
                    cv::circle(image,cv::Point2i(col,row),1,cv::Scalar(color.val[0],color.val[1],color.val[2]));
                }
            }
        }
        int k,l=vars->dpmbuffer[j].cvdetection.size();
        for(k=0;k<l;k++)
        {
            cv::rectangle(image,vars->dpmbuffer[j].cvdetection[k],cv::Scalar(255,0,0),2);
        }
        QImage img(image.data,image.cols,image.rows,image.step,QImage::Format_RGB888);
        vars->viewer->setPixmap(QPixmap::fromImage(img));
        vars->viewer->resize(img.size());
    }
    else if(image.type()==CV_8UC1)
    {
        int row,col;
        for(row=0;row<image.rows;row++)
        {
            for(col=0;col<image.cols;col++)
            {
                int id=row*image.cols+col;
                if(vars->velodynecamerabuffer[i].ranges[id]>vars->minrange&&vars->velodynecamerabuffer[i].ranges[id]<=vars->maxrange)
                {
                    int colorid=int((vars->velodynecamerabuffer[i].ranges[id]-vars->minrange)/(vars->maxrange-vars->minrange)*255+0.5);
                    cv::circle(image,cv::Point2i(col,row),1,cv::Scalar(colorid));
                }
            }
        }
        int k,l=vars->dpmbuffer[j].cvdetection.size();
        for(k=0;k<l;k++)
        {
            cv::rectangle(image,vars->dpmbuffer[j].cvdetection[k],cv::Scalar(255),2);
        }
        QImage img(image.data,image.cols,image.rows,image.step,QImage::Format_Indexed8);
        img.setColorTable(vars->colorTable);
        vars->viewer->setPixmap(QPixmap::fromImage(img));
        vars->viewer->resize(img.size());
    }
    else
    {
        vars->viewer->setText("Not Supported");
        return 0;
    }

    vars->velodynecamerabuffer.erase(vars->velodynecamerabuffer.begin(),vars->velodynecamerabuffer.begin()+i+1);
    vars->dpmbuffer.erase(vars->dpmbuffer.begin(),vars->dpmbuffer.begin()+j+1);
	return 1;
}

void DECOFUNC(visualizationWidgets)(void * paramsPtr, void * varsPtr, QList<QWidget *> & widgets)
{
	VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Params * params=(VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Params *)paramsPtr;
	VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Vars * vars=(VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Vars *)varsPtr;
    widgets=QList<QWidget *>()<<(vars->tabwidget);
	/*======Please Program above======*/
	/*
	Function: get visualization widgets [defined in vars].
	You need to program here when you need visualization widgets.
	E.g.
	widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
	*/
}

