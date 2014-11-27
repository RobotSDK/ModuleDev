//You need to program this file.

#include "../NoEdit/VisualizationMono_ROS_Sensor_Camera_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	VisualizationMono_ROS_Sensor_Camera_Params * params=(VisualizationMono_ROS_Sensor_Camera_Params *)paramsPtr;
	VisualizationMono_ROS_Sensor_Camera_Vars * vars=(VisualizationMono_ROS_Sensor_Camera_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader,params,compressrate);

    vars->image->setText("Open");
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	VisualizationMono_ROS_Sensor_Camera_Params * params=(VisualizationMono_ROS_Sensor_Camera_Params *)paramsPtr;
	VisualizationMono_ROS_Sensor_Camera_Vars * vars=(VisualizationMono_ROS_Sensor_Camera_Vars *)varsPtr;
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
	VisualizationMono_ROS_Sensor_Camera_Params * params=(VisualizationMono_ROS_Sensor_Camera_Params *)paramsPtr;
	VisualizationMono_ROS_Sensor_Camera_Vars * vars=(VisualizationMono_ROS_Sensor_Camera_Vars *)varsPtr;
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
	VisualizationMono_ROS_Sensor_Camera_Params * params=(VisualizationMono_ROS_Sensor_Camera_Params *)paramsPtr;
	VisualizationMono_ROS_Sensor_Camera_Vars * vars=(VisualizationMono_ROS_Sensor_Camera_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 0, Params_Type = SensorInternalEvent_ROS_Sensor_Camera_Params, Data_Type = SensorInternalEvent_ROS_Sensor_Camera_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
	VisualizationMono_ROS_Sensor_Camera_Params * params=(VisualizationMono_ROS_Sensor_Camera_Params *)paramsPtr;
	VisualizationMono_ROS_Sensor_Camera_Vars * vars=(VisualizationMono_ROS_Sensor_Camera_Vars *)varsPtr;
	QVector<SensorInternalEvent_ROS_Sensor_Camera_Params *> drainparams; copyQVector(drainparams,drainParams);
	QVector<SensorInternalEvent_ROS_Sensor_Camera_Data *> draindata; copyQVector(draindata,drainData);
	if(draindata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata.
	*/
    cv::Mat image;
    cv::Size size=draindata.front()->image.size();
    size.width*=params->compressrate;
    size.height*=params->compressrate;
    cv::resize(draindata.front()->image,image,size);
    QFont font("times",24);
    QFontMetrics fm(font);
    int height=fm.height();
    QPainter painter;
    QPen pen(QColor(0,0,0,128));
    if(image.type()==CV_8UC1)
    {
        QImage img(image.data, image.cols, image.rows, image.step, QImage::Format_Indexed8);
        img.setColorTable(vars->colorTable);
        painter.begin(&img);
        painter.setPen(pen);
        painter.drawText(0,1*height,QString("Camera %1").arg(drainparams.front()->cameraid));
        painter.drawText(0,2*height,draindata.front()->timestamp.toString("HH:mm:ss:zzz"));
        painter.end();
        vars->image->setPixmap(QPixmap::fromImage(img));
        return 1;
    }
    else if(image.type()==CV_8UC3)
    {
        QImage img(image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);
        img=img.rgbSwapped();
        painter.begin(&img);
        painter.setPen(pen);
        painter.drawText(0,height,draindata.front()->timestamp.toString("HH:mm:ss:zzz"));
        painter.end();
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
	VisualizationMono_ROS_Sensor_Camera_Params * params=(VisualizationMono_ROS_Sensor_Camera_Params *)paramsPtr;
	VisualizationMono_ROS_Sensor_Camera_Vars * vars=(VisualizationMono_ROS_Sensor_Camera_Vars *)varsPtr;
    widgets=QList<QWidget *>()<<vars->image;
	/*======Please Program above======*/
	/*
	Function: get visualization widgets [defined in vars].
	You need to program here when you need visualization widgets.
	E.g.
	widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
	*/
}

