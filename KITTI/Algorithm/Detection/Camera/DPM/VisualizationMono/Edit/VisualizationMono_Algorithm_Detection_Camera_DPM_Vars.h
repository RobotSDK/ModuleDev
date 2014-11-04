//You need to modify this file.

#ifndef VISUALIZATIONMONO_ALGORITHM_DETECTION_CAMERA_DPM_VARS_H
#define VISUALIZATIONMONO_ALGORITHM_DETECTION_CAMERA_DPM_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Algorithm_Detection_Camera_DPM_Vars VisualizationMono_Algorithm_Detection_Camera_DPM_Vars
	\ingroup VisualizationMono_Algorithm_Detection_Camera_DPM
	\brief VisualizationMono_Algorithm_Detection_Camera_DPM_Vars defines the Vars in VisualizationMono_Algorithm_Detection_Camera_DPM.
*/

/*! \addtogroup VisualizationMono_Algorithm_Detection_Camera_DPM_Vars
	@{
*/

/*! \file VisualizationMono_Algorithm_Detection_Camera_DPM_Vars.h
	 Defines the Vars of VisualizationMono_Algorithm_Detection_Camera_DPM
*/

//*******************Please add other headers below*******************
#include<opencv2/opencv.hpp>

//The Vars is defined as below
/*! \class VisualizationMono_Algorithm_Detection_Camera_DPM_Vars 
	\brief The Vars of VisualizationMono_Algorithm_Detection_Camera_DPM.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Algorithm_Detection_Camera_DPM_Vars 
{
public:
	/*! \fn VisualizationMono_Algorithm_Detection_Camera_DPM_Vars()
		\brief The constructor of VisualizationMono_Algorithm_Detection_Camera_DPM_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Algorithm_Detection_Camera_DPM_Vars() 
	{
		image=new QLabel;
		image->setAlignment(Qt::AlignCenter);
		int i;
		for (i=0; i<256; i++)
		{
            colorTable.push_back(qRgb(i,i,i));
		}
		boxcolors[0]=cv::Scalar(0,0,255);
		boxcolors[1]=cv::Scalar(0,255,0);
		boxcolors[2]=cv::Scalar(0,255,255);
		boxcolors[3]=cv::Scalar(255,0,0);
		boxcolors[4]=cv::Scalar(255,0,255);
		boxcolors[5]=cv::Scalar(255,255,0);
		thickness=2;
	}
	/*! \fn ~VisualizationMono_Algorithm_Detection_Camera_DPM_Vars()
		\brief The destructor of VisualizationMono_Algorithm_Detection_Camera_DPM_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Algorithm_Detection_Camera_DPM_Vars() 
	{
		if(image->parent()==NULL)
		{
			delete image;
			image=NULL;
		}		
	}
public:
	//*******************Please add variables below*******************
	QLabel * image;
	QVector<QRgb> colorTable;
	cv::Scalar boxcolors[6];
	int thickness;
};

/*! @}*/ 

#endif
