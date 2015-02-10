//You need to program this file.

#include "../NoEdit/VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Params * params=(VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Params *)paramsPtr;
	VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Vars * vars=(VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
	
    vars->viewer->setText("Open");

	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Params * params=(VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Params *)paramsPtr;
	VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Vars * vars=(VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->viewer->setText("Closed");
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Params * params=(VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Params *)paramsPtr;
	VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Vars * vars=(VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Vars *)varsPtr;
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
	VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Params * params=(VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Params *)paramsPtr;
	VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Vars * vars=(VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 0, Params_Type = ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Params, Data_Type = ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Data
//Input Port #1: Buffer_Size = 0, Params_Type = SensorInternalEvent_Algorithm_Detection_DPM_Params, Data_Type = SensorInternalEvent_Algorithm_Detection_DPM_Data
bool DECOFUNC(processMultiDrainData)(void * paramsPtr, void * varsPtr, QVector<QVector<void *> > drainParams, QVector<QVector<void *> > drainData)
{
	VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Params * params=(VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Params *)paramsPtr;
	VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Vars * vars=(VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Vars *)varsPtr;
	QVector<ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Params *> drainparams_0; copyQVector(drainparams_0,drainParams[0]);
	QVector<SensorInternalEvent_Algorithm_Detection_DPM_Params *> drainparams_1; copyQVector(drainparams_1,drainParams[1]);
	QVector<ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Data *> draindata_0; copyQVector(draindata_0,drainData[0]);
	QVector<SensorInternalEvent_Algorithm_Detection_DPM_Data *> draindata_1; copyQVector(draindata_1,drainData[1]);
    //if(draindata_0.size()==0){return 0;}
    //if(draindata_1.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata_index.
	*/
    int i,n=draindata_0.size();
    for(i=n-1;i>=0;i--)
    {
        vars->datasync.addData1((*draindata_0[i]),draindata_0[i]->cameratimestamp);
    }
    int j,m=draindata_1.size();
    for(j=m-1;j>=0;j--)
    {
        vars->datasync.addData2((*draindata_1[j]),draindata_1[j]->timestamp);
    }

    ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Data data1;
    SensorInternalEvent_Algorithm_Detection_DPM_Data data2;

    if(!vars->datasync.getSyncData(data1,data2))
    {
        return 0;
    }

    vars->tabwidget->setTabText(0,data1.cameratimestamp.toString("HH:mm:ss:zzz")+QString(" - ")+data2.timestamp.toString("HH:mm:ss:zzz"));

    cv::Mat image=data1.cvimage;

    if(image.type()==CV_8UC3)
    {
        cv::Mat tmpimage=image.clone();
        int i,n=data1.imagepoint.size();
        for(i=0;i<n;i++)
        {
            cv::Point center=cv::Point(data1.imagepoint[i].x(),data1.imagepoint[i].y());
            int colorid=int(double(data1.label[i])/double(data1.labelcount)*256);
            cv::Vec3b color=vars->colormap.at<cv::Vec3b>(colorid);
            cv::circle(tmpimage,center,2,cv::Scalar(color[0],color[1],color[2]));
        }

        int k,l=data2.cvdetection.size();
        for(k=0;k<l;k++)
        {
            cv::rectangle(tmpimage,data2.cvdetection[k],cv::Scalar(255,0,0),2);
        }

        QImage img(tmpimage.data,tmpimage.cols,tmpimage.rows,tmpimage.step,QImage::Format_RGB888);
        vars->viewer->setPixmap(QPixmap::fromImage(img));
        vars->viewer->resize(img.size());
    }
    else if(image.type()==CV_8UC1)
    {
        int k,l=data2.cvdetection.size();
        for(k=0;k<l;k++)
        {
            cv::rectangle(image,data2.cvdetection[k],cv::Scalar(255),2);
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

	return 1;
}

void DECOFUNC(visualizationWidgets)(void * paramsPtr, void * varsPtr, QList<QWidget *> & widgets)
{
	VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Params * params=(VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Params *)paramsPtr;
	VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Vars * vars=(VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Vars *)varsPtr;
    widgets=QList<QWidget *>()<<vars->tabwidget;
	/*======Please Program above======*/
	/*
	Function: get visualization widgets [defined in vars].
	You need to program here when you need visualization widgets.
	E.g.
	widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
	*/
}

