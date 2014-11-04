//You need to program this file.

#include "../NoEdit/VisualizationMono_Algorithm_Detection_Camera_DBM_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	VisualizationMono_Algorithm_Detection_Camera_DBM_Params * params=(VisualizationMono_Algorithm_Detection_Camera_DBM_Params *)paramsPtr;
	VisualizationMono_Algorithm_Detection_Camera_DBM_Vars * vars=(VisualizationMono_Algorithm_Detection_Camera_DBM_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader,vars,thickness);
    vars->image->setText("Open");
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	VisualizationMono_Algorithm_Detection_Camera_DBM_Params * params=(VisualizationMono_Algorithm_Detection_Camera_DBM_Params *)paramsPtr;
	VisualizationMono_Algorithm_Detection_Camera_DBM_Vars * vars=(VisualizationMono_Algorithm_Detection_Camera_DBM_Vars *)varsPtr;
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
	VisualizationMono_Algorithm_Detection_Camera_DBM_Params * params=(VisualizationMono_Algorithm_Detection_Camera_DBM_Params *)paramsPtr;
	VisualizationMono_Algorithm_Detection_Camera_DBM_Vars * vars=(VisualizationMono_Algorithm_Detection_Camera_DBM_Vars *)varsPtr;
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
	VisualizationMono_Algorithm_Detection_Camera_DBM_Params * params=(VisualizationMono_Algorithm_Detection_Camera_DBM_Params *)paramsPtr;
	VisualizationMono_Algorithm_Detection_Camera_DBM_Vars * vars=(VisualizationMono_Algorithm_Detection_Camera_DBM_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 0, Params_Type = ProcessorMono_Algorithm_Detection_Camera_DBM_Params, Data_Type = ProcessorMono_Algorithm_Detection_Camera_DBM_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
	VisualizationMono_Algorithm_Detection_Camera_DBM_Params * params=(VisualizationMono_Algorithm_Detection_Camera_DBM_Params *)paramsPtr;
	VisualizationMono_Algorithm_Detection_Camera_DBM_Vars * vars=(VisualizationMono_Algorithm_Detection_Camera_DBM_Vars *)varsPtr;
	QVector<ProcessorMono_Algorithm_Detection_Camera_DBM_Params *> drainparams; copyQVector(drainparams,drainParams);
	QVector<ProcessorMono_Algorithm_Detection_Camera_DBM_Data *> draindata; copyQVector(draindata,drainData);
	if(draindata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata.
	*/
    cv::Mat image;
    draindata.front()->image.copyTo(image);
    //CvFont font = cv::fontQt("Times");
    if(image.type()==CV_8UC1)
    {
        int i,n=draindata.front()->objects.size();
        for(i=0;i<n;i++)
        {
            cv::rectangle(image,draindata.front()->objects[i].rect,cv::Scalar(1.0),vars->thickness);
        }
        QImage img(image.data, image.cols, image.rows, image.step, QImage::Format_Indexed8);
        img.setColorTable(vars->colorTable);
        vars->image->setPixmap(QPixmap::fromImage(img));

        return 1;
    }
    else if(image.type()==CV_8UC3)
    {
        int i,n=draindata.front()->objects.size();
        for(i=0;i<n;i++)
        {
            int colorindex=draindata.front()->objects[i].classID % 6;
            cv::rectangle(image,draindata.front()->objects[i].rect,vars->boxcolors[colorindex],vars->thickness);
            cv::line(image,cv::Point(draindata.front()->objects[i].rect.x,draindata.front()->objects[i].rect.y)
                ,cv::Point(draindata.front()->objects[i].rect.x+draindata.front()->objects[i].rect.width,draindata.front()->objects[i].rect.y+draindata.front()->objects[i].rect.height)
                ,vars->boxcolors[colorindex],vars->thickness);
            cv::line(image,cv::Point(draindata.front()->objects[i].rect.x+draindata.front()->objects[i].rect.width,draindata.front()->objects[i].rect.y)
                ,cv::Point(draindata.front()->objects[i].rect.x,draindata.front()->objects[i].rect.y+draindata.front()->objects[i].rect.height)
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
	VisualizationMono_Algorithm_Detection_Camera_DBM_Params * params=(VisualizationMono_Algorithm_Detection_Camera_DBM_Params *)paramsPtr;
	VisualizationMono_Algorithm_Detection_Camera_DBM_Vars * vars=(VisualizationMono_Algorithm_Detection_Camera_DBM_Vars *)varsPtr;
    widgets=QList<QWidget *>()<<vars->image;
	/*======Please Program above======*/
	/*
	Function: get visualization widgets [defined in vars].
	You need to program here when you need visualization widgets.
	E.g.
	widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
	*/
}

