//You need to modify this file.

#ifndef VISUALIZATIONMONO_ALGORITHM_INTEGRATION_VIRTUALSCANNDT3D_VARS_H
#define VISUALIZATIONMONO_ALGORITHM_INTEGRATION_VIRTUALSCANNDT3D_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Vars VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Vars
	\ingroup VisualizationMono_Algorithm_Integration_VirtualScanNDT3D
	\brief VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Vars defines the Vars in VisualizationMono_Algorithm_Integration_VirtualScanNDT3D.
*/

/*! \addtogroup VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Vars
	@{
*/

/*! \file VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Vars.h
	 Defines the Vars of VisualizationMono_Algorithm_Integration_VirtualScanNDT3D
*/

//*******************Please add other headers below*******************
#include<opencv2/opencv.hpp>

//The Vars is defined as below
/*! \class VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Vars 
	\brief The Vars of VisualizationMono_Algorithm_Integration_VirtualScanNDT3D.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Vars 
{
public:
	/*! \fn VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Vars()
		\brief The constructor of VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Vars() 
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
	/*! \fn ~VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Vars()
		\brief The destructor of VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Vars() 
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
    QQueue<cv::Mat> transforms;
    QQueue<cv::Mat> points;
    cv::Mat colortable;
};

/*! @}*/ 

#endif
