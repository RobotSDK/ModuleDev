//You need to program this file.

#include "../NoEdit/VisualizationMono_Sensor_VirtualScan_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	VisualizationMono_Sensor_VirtualScan_Params * params=(VisualizationMono_Sensor_VirtualScan_Params *)paramsPtr;
	VisualizationMono_Sensor_VirtualScan_Vars * vars=(VisualizationMono_Sensor_VirtualScan_Vars *)varsPtr;
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
    vars->image->setText("Open");
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	VisualizationMono_Sensor_VirtualScan_Params * params=(VisualizationMono_Sensor_VirtualScan_Params *)paramsPtr;
	VisualizationMono_Sensor_VirtualScan_Vars * vars=(VisualizationMono_Sensor_VirtualScan_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->image->setText("Closed");
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	VisualizationMono_Sensor_VirtualScan_Params * params=(VisualizationMono_Sensor_VirtualScan_Params *)paramsPtr;
	VisualizationMono_Sensor_VirtualScan_Vars * vars=(VisualizationMono_Sensor_VirtualScan_Vars *)varsPtr;
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
	VisualizationMono_Sensor_VirtualScan_Params * params=(VisualizationMono_Sensor_VirtualScan_Params *)paramsPtr;
	VisualizationMono_Sensor_VirtualScan_Vars * vars=(VisualizationMono_Sensor_VirtualScan_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 0, Params_Type = SensorInternalEvent_Sensor_VirtualScan_Params, Data_Type = SensorInternalEvent_Sensor_VirtualScan_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
	VisualizationMono_Sensor_VirtualScan_Params * params=(VisualizationMono_Sensor_VirtualScan_Params *)paramsPtr;
	VisualizationMono_Sensor_VirtualScan_Vars * vars=(VisualizationMono_Sensor_VirtualScan_Vars *)varsPtr;
	QVector<SensorInternalEvent_Sensor_VirtualScan_Params *> drainparams; copyQVector(drainparams,drainParams);
	QVector<SensorInternalEvent_Sensor_VirtualScan_Data *> draindata; copyQVector(draindata,drainData);
	if(draindata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata.
	*/
    QImage image(params->imagesize,params->imagesize,QImage::Format_RGB888);
    image.fill(QColor(255,255,255));
    double ratio=double(params->imagesize)/double(2*params->maxrange);
    double PI=3.141592654;

    QVector<double> virtualscan=draindata.front()->virtualscan;
    QVector<int> label=draindata.front()->label;
    int labelcount=draindata.front()->labelcount;
    int beamnum=virtualscan.size();
    double density=2*PI/beamnum;

    QPainter painter;
    painter.begin(&image);

    int i;
    for(i=0;i<labelcount;i++)
    {
        int colorid=int(255*(double(i)/double(labelcount))+0.5);
        cv::Vec3b color=vars->colortable.at<cv::Vec3b>(colorid);
        painter.setPen(QColor(color[0],color[1],color[2]));
        QVector<QPoint> points;
        int j;
        for(j=0;j<beamnum;j++)
        {
            if(label[j]==i)
            {
                double theta=j*density+PI/2;
                int x=int((params->maxrange+virtualscan[j]*cos(theta))*ratio+0.5);
                int y=int((params->maxrange+virtualscan[j]*sin(theta))*ratio+0.5);
                x=params->imagesize-x;
                points.push_back(QPoint(x,y));
            }
        }
        int m=points.size();
        painter.drawPolyline(points.data(),m);
        for(j=0;j<m;j++)
        {
            painter.drawEllipse(points[j],1,1);
        }
    }

    painter.setPen(QColor(0,0,0));
    for(i=0;i<beamnum;i++)
    {
        if(label[i]==-2)
        {
            double theta=i*density+PI/2;
            int x=int((params->maxrange+virtualscan[i]*cos(theta))*ratio+0.5);
            int y=int((params->maxrange+virtualscan[i]*sin(theta))*ratio+0.5);
            x=params->imagesize-x;
            painter.drawEllipse(QPoint(x,y),1,1);
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
	VisualizationMono_Sensor_VirtualScan_Params * params=(VisualizationMono_Sensor_VirtualScan_Params *)paramsPtr;
	VisualizationMono_Sensor_VirtualScan_Vars * vars=(VisualizationMono_Sensor_VirtualScan_Vars *)varsPtr;
    widgets=QList<QWidget *>()<<vars->image;
	/*======Please Program above======*/
	/*
	Function: get visualization widgets [defined in vars].
	You need to program here when you need visualization widgets.
	E.g.
	widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
	*/
}

