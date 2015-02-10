//You need to modify this file.

#ifndef VISUALIZATIONMONO_ALGORITHM_INTEGRATION_VIRTUALSCANCAMERA_VARS_H
#define VISUALIZATIONMONO_ALGORITHM_INTEGRATION_VIRTUALSCANCAMERA_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Algorithm_Integration_VirtualScanCamera_Vars VisualizationMono_Algorithm_Integration_VirtualScanCamera_Vars
	\ingroup VisualizationMono_Algorithm_Integration_VirtualScanCamera
	\brief VisualizationMono_Algorithm_Integration_VirtualScanCamera_Vars defines the Vars in VisualizationMono_Algorithm_Integration_VirtualScanCamera.
*/

/*! \addtogroup VisualizationMono_Algorithm_Integration_VirtualScanCamera_Vars
	@{
*/

/*! \file VisualizationMono_Algorithm_Integration_VirtualScanCamera_Vars.h
	 Defines the Vars of VisualizationMono_Algorithm_Integration_VirtualScanCamera
*/

//*******************Please add other headers below*******************
#include<opencv2/opencv.hpp>

//The Vars is defined as below
/*! \class VisualizationMono_Algorithm_Integration_VirtualScanCamera_Vars 
	\brief The Vars of VisualizationMono_Algorithm_Integration_VirtualScanCamera.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Algorithm_Integration_VirtualScanCamera_Vars 
{
public:
	/*! \fn VisualizationMono_Algorithm_Integration_VirtualScanCamera_Vars()
		\brief The constructor of VisualizationMono_Algorithm_Integration_VirtualScanCamera_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Algorithm_Integration_VirtualScanCamera_Vars() 
	{
        viewer=new QLabel("Image");
        viewer->setAlignment(Qt::AlignCenter);
        QScrollArea * scroll=new QScrollArea;
        scroll->setWidget(viewer);
        tabwidget=new QTabWidget;
        tabwidget->addTab(scroll,"TimeStamp");

        cv::Mat grayscale(256,1,CV_8UC1);

        int i;
        for (i=0; i<256; i++)
        {
            colorTable.push_back(qRgb(i,i,i));
            grayscale.at<uchar>(i)=i;
        }
        cv::applyColorMap(grayscale,colormap,cv::COLORMAP_RAINBOW);
	}
	/*! \fn ~VisualizationMono_Algorithm_Integration_VirtualScanCamera_Vars()
		\brief The destructor of VisualizationMono_Algorithm_Integration_VirtualScanCamera_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Algorithm_Integration_VirtualScanCamera_Vars() 
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
    cv::Mat colormap;
};

/*! @}*/ 

#endif
