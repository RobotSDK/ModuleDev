//You need to program this file.

#include "../NoEdit/VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Params * params=(VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Params *)paramsPtr;
	VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Vars * vars=(VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader,params,maxrange);
    GetParamValue(xmlloader,params,gridsize);
    GetParamValue(xmlloader,params,imagesize);
    GetParamValue(xmlloader,params,frames);
    GetParamValue(xmlloader,params,baseframe);
    vars->image->setText("Open");
    vars->points.clear();
    vars->transforms.clear();
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Params * params=(VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Params *)paramsPtr;
	VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Vars * vars=(VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->image->setText("Closed");
    vars->points.clear();
    vars->transforms.clear();
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Params * params=(VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Params *)paramsPtr;
	VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Vars * vars=(VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Vars *)varsPtr;
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
	VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Params * params=(VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Params *)paramsPtr;
	VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Vars * vars=(VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Vars *)varsPtr;
    drainDataSize=-1;
	/*======Please Program above======*/
	/*
	Function: get drain data size to be grabbed from buffer.
	Rules:
	drainDataSize=0: grab and remove all data from buffer.
	drainDataSize>0: grab drainDataSize latest data from buffer.
	drainDataSize<0: grab and remove drainDataSize ancient data from buffer.
	*/
}

//Input Port #0: Buffer_Size = 0, Params_Type = ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Params, Data_Type = ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
	VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Params * params=(VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Params *)paramsPtr;
	VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Vars * vars=(VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Vars *)varsPtr;
	QVector<ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Params *> drainparams; copyQVector(drainparams,drainParams);
	QVector<ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Data *> draindata; copyQVector(draindata,drainData);
	if(draindata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata.
	*/
    vars->points.push_back(draindata.front()->points);
    vars->transforms.push_back(draindata.front()->cvtransform);
    if(vars->points.size()<params->frames)
    {
        return 0;
    }
    if(vars->points.size()>params->frames)
    {
        vars->points.pop_front();
        vars->transforms.pop_front();
    }
    QImage image(params->imagesize,params->imagesize,QImage::Format_RGB888);
    image.fill(QColor(255,255,255));
    double ratio=double(params->imagesize)/double(2*params->maxrange);

    QPainter painter;
    painter.begin(&image);

    cv::Mat basemat=vars->transforms[params->baseframe].inv();
    int i;
    for(i=0;i<params->frames;i++)
    {
        cv::Mat points=vars->points[i]*basemat.t();
        int id=double(i)/double(params->frames)*255;
        cv::Vec3b color=vars->colortable.at<cv::Vec3b>(id);
        painter.setPen(QColor(color[0],color[1],color[2]));
        int j,beamnum=points.rows;
        for(j=0;j<beamnum;j++)
        {
            double x=points.at<double>(j,0);
            double y=points.at<double>(j,1);
            double distance=sqrt(x*x+y*y);
            if(distance>0)
            {
                int py=int((params->maxrange+x)*ratio+0.5);
                int px=int((params->maxrange+y)*ratio+0.5);
                px=params->imagesize-px;
                py=params->imagesize-py;
                painter.drawEllipse(QPoint(px,py),1,1);
            }
        }
    }

    painter.setPen(QColor(128,128,128));
    QPoint center(params->imagesize/2,params->imagesize/2);
    for(i=params->gridsize;i<=params->maxrange;i+=params->gridsize)
    {
        painter.drawEllipse(center,i*ratio,i*ratio);
    }

    painter.end();

    vars->image->setPixmap(QPixmap::fromImage(image));
	return 1;
}

void DECOFUNC(visualizationWidgets)(void * paramsPtr, void * varsPtr, QList<QWidget *> & widgets)
{
	VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Params * params=(VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Params *)paramsPtr;
	VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Vars * vars=(VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Vars *)varsPtr;
    widgets=QList<QWidget *>()<<vars->image;
	/*======Please Program above======*/
	/*
	Function: get visualization widgets [defined in vars].
	You need to program here when you need visualization widgets.
	E.g.
	widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
	*/
}

