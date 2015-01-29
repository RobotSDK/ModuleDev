//You need to modify this file.

#ifndef VISUALIZATIONMONO_SENSOR_VIRTUALSCAN_VARS_H
#define VISUALIZATIONMONO_SENSOR_VIRTUALSCAN_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Sensor_VirtualScan_Vars VisualizationMono_Sensor_VirtualScan_Vars
	\ingroup VisualizationMono_Sensor_VirtualScan
	\brief VisualizationMono_Sensor_VirtualScan_Vars defines the Vars in VisualizationMono_Sensor_VirtualScan.
*/

/*! \addtogroup VisualizationMono_Sensor_VirtualScan_Vars
	@{
*/

/*! \file VisualizationMono_Sensor_VirtualScan_Vars.h
	 Defines the Vars of VisualizationMono_Sensor_VirtualScan
*/

//*******************Please add other headers below*******************
#include<opencv2/opencv.hpp>

//The Vars is defined as below
/*! \class VisualizationMono_Sensor_VirtualScan_Vars 
	\brief The Vars of VisualizationMono_Sensor_VirtualScan.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Sensor_VirtualScan_Vars 
{
public:
	/*! \fn VisualizationMono_Sensor_VirtualScan_Vars()
		\brief The constructor of VisualizationMono_Sensor_VirtualScan_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Sensor_VirtualScan_Vars() 
	{
        image=new QLabel("Virtual Scan");
        image->setAlignment(Qt::AlignCenter);
        cv::Mat grayscale(1,256,CV_8U);
        int i;
        for(i=0;i<256;i++)
        {
            grayscale.at<uchar>(i)=i;
        }
        cv::applyColorMap(grayscale,colortable,cv::COLORMAP_RAINBOW);
	}
	/*! \fn ~VisualizationMono_Sensor_VirtualScan_Vars()
		\brief The destructor of VisualizationMono_Sensor_VirtualScan_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Sensor_VirtualScan_Vars() 
	{
        if(image!=NULL&&image->parent()==NULL)
        {
            delete image;
            image=NULL;
        }
	}
public:
	//*******************Please add variables below*******************
    QLabel * image;
    cv::Mat colortable;
};

/*! @}*/ 

#endif
