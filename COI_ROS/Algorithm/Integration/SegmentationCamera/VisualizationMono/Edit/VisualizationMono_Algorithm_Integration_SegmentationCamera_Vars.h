//You need to modify this file.

#ifndef VISUALIZATIONMONO_ALGORITHM_INTEGRATION_SEGMENTATIONCAMERA_VARS_H
#define VISUALIZATIONMONO_ALGORITHM_INTEGRATION_SEGMENTATIONCAMERA_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Algorithm_Integration_SegmentationCamera_Vars VisualizationMono_Algorithm_Integration_SegmentationCamera_Vars
	\ingroup VisualizationMono_Algorithm_Integration_SegmentationCamera
	\brief VisualizationMono_Algorithm_Integration_SegmentationCamera_Vars defines the Vars in VisualizationMono_Algorithm_Integration_SegmentationCamera.
*/

/*! \addtogroup VisualizationMono_Algorithm_Integration_SegmentationCamera_Vars
	@{
*/

/*! \file VisualizationMono_Algorithm_Integration_SegmentationCamera_Vars.h
	 Defines the Vars of VisualizationMono_Algorithm_Integration_SegmentationCamera
*/

//*******************Please add other headers below*******************
#include<opencv2/opencv.hpp>

//The Vars is defined as below
/*! \class VisualizationMono_Algorithm_Integration_SegmentationCamera_Vars 
	\brief The Vars of VisualizationMono_Algorithm_Integration_SegmentationCamera.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Algorithm_Integration_SegmentationCamera_Vars 
{
public:
	/*! \fn VisualizationMono_Algorithm_Integration_SegmentationCamera_Vars()
		\brief The constructor of VisualizationMono_Algorithm_Integration_SegmentationCamera_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Algorithm_Integration_SegmentationCamera_Vars() 
	{
        cameraviewer=new QLabel("Image");
        QScrollArea * scroll=new QScrollArea;
        scroll->setWidget(cameraviewer);
        tabwidget=new QTabWidget;
        tabwidget->addTab(scroll,"TimeStamp");

        int i;
        for(i=0;i<256;i++)
        {
            colorTable.push_back(qRgb(i,i,i));
        }

        cv::Mat greymat=cv::Mat(256,1,CV_8UC1);
        for(i=0;i<256;i++)
        {
            greymat.at<uchar>(i)=i;
        }
        cv::applyColorMap(greymat,colormap,cv::COLORMAP_RAINBOW);
	}
	/*! \fn ~VisualizationMono_Algorithm_Integration_SegmentationCamera_Vars()
		\brief The destructor of VisualizationMono_Algorithm_Integration_SegmentationCamera_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Algorithm_Integration_SegmentationCamera_Vars() 
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
    QLabel * cameraviewer;
    QVector<QRgb> colorTable;
    cv::Mat colormap;
};

/*! @}*/ 

#endif
