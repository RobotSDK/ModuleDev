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
    GetParamValue(xmlloader,params,imageheight);
    GetParamValue(xmlloader,params,imagewidth);
    GetParamValue(xmlloader,params,frames);
    GetParamValue(xmlloader,params,baseframe);
    GetParamValue(xmlloader,params,showbeam);

    params->imagesize=params->imageheight>params->imagewidth?params->imageheight:params->imagewidth;

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
    vars->points.push_front(draindata.front()->points);
    vars->transforms.push_front(draindata.front()->cvtransform);
//    if(vars->points.size()<params->frames)
//    {
//        return 0;
//    }
    if(vars->points.size()>params->frames)
    {
        vars->points.pop_back();
        vars->transforms.pop_back();
    }
    QImage image(params->imagewidth,params->imageheight,QImage::Format_RGB888);
    image.fill(QColor(255,255,255));
    double ratio=double(params->imagesize)/double(2*params->maxrange);

    QPainter painter;
    painter.begin(&image);

    cv::Mat basemat;
    if(params->baseframe>=0&&params->baseframe<vars->points.size())
    {
        basemat=vars->transforms[params->baseframe].inv();
    }
    else
    {
        basemat=vars->transforms.front().inv();
    }
    int i;
    for(i=vars->points.size()-1;i>=0;i--)
    {
        cv::Mat points=vars->points[i]*basemat.t();
        int j,beamnum=points.rows;
        for(j=0;j<beamnum;j++)
        {
            double x=points.at<double>(j,0);
            double y=points.at<double>(j,1);
            double distance=sqrt(x*x+y*y);
            if(distance>0)
            {
                int py=int(x*ratio+params->imageheight/2.0+0.5);
                int px=int(y*ratio+params->imagewidth/2.0+0.5);
                px=params->imagewidth-px;
                py=params->imageheight-py;
                if(params->frames>1)
                {
                    int id=255-int(double(i)/double(params->frames)*255);
                    cv::Vec3b color=vars->colortable.at<cv::Vec3b>(id);
                    painter.setPen(QColor(color[0],color[1],color[2]));
                    painter.setBrush(QColor(color[0],color[1],color[2]));
                }
                else
                {
                    painter.setPen(QColor(255,0,0));
                    painter.setBrush(QColor(255,0,0));
                }
                painter.drawEllipse(QPoint(px,py),1,1);
                painter.setBrush(QBrush());
                if(params->showbeam)
                {
                    painter.setPen(QColor(196,196,196));
                    painter.drawLine(params->imagewidth/2,params->imageheight/2,px,py);
                }
            }
        }
    }

    painter.setPen(QColor(128,128,128));
    QPoint center(params->imagewidth/2,params->imageheight/2);
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

