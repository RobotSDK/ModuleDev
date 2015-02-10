//You need to modify this file.

#ifndef VISUALIZATIONMULTI_ALGORITHM_INTEGRATION_VIRTUALSCANCAMERADPM_VARS_H
#define VISUALIZATIONMULTI_ALGORITHM_INTEGRATION_VIRTUALSCANCAMERADPM_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Vars VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Vars
	\ingroup VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM
	\brief VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Vars defines the Vars in VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM.
*/

/*! \addtogroup VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Vars
	@{
*/

/*! \file VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Vars.h
	 Defines the Vars of VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM
*/

//*******************Please add other headers below*******************
#include<datasync.h>

#include "VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_ParamsData.h"

//The Vars is defined as below
/*! \class VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Vars 
	\brief The Vars of VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Vars 
{
public:
	/*! \fn VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Vars()
		\brief The constructor of VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Vars() 
	{
        viewer=new QLabel("Image");
        viewer->setAlignment(Qt::AlignCenter);
        QScrollArea * scroll=new QScrollArea;
        scroll->setWidget(viewer);
        tabwidget=new QTabWidget;
        tabwidget->addTab(scroll,"TimeStamp");

        cv::Mat greymat=cv::Mat(1,256,CV_8UC1);
        int i;
        for (i=0; i<256; i++)
        {
            colorTable.push_back(qRgb(i,i,i));
            greymat.at<uchar>(i)=i;
        }
        cv::applyColorMap(greymat,colormap,cv::COLORMAP_RAINBOW);
	}
	/*! \fn ~VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Vars()
		\brief The destructor of VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMulti_Algorithm_Integration_VirtualScanCameraDPM_Vars() 
	{
        if(tabwidget->parent()==NULL)
        {
            delete tabwidget;
            tabwidget=NULL;
        }
	}
public:
	//*******************Please add variables below*******************
    QTabWidget * tabwidget;
    QLabel * viewer;
    QVector<QRgb> colorTable;
    DataSync<ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Data, SensorInternalEvent_Algorithm_Detection_DPM_Data> datasync;
    cv::Mat colormap;
};

/*! @}*/ 

#endif
