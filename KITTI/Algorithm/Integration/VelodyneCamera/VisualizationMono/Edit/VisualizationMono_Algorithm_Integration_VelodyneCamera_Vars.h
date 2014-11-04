//You need to modify this file.

#ifndef VISUALIZATIONMONO_ALGORITHM_INTEGRATION_VELODYNECAMERA_VARS_H
#define VISUALIZATIONMONO_ALGORITHM_INTEGRATION_VELODYNECAMERA_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Algorithm_Integration_VelodyneCamera_Vars VisualizationMono_Algorithm_Integration_VelodyneCamera_Vars
	\ingroup VisualizationMono_Algorithm_Integration_VelodyneCamera
	\brief VisualizationMono_Algorithm_Integration_VelodyneCamera_Vars defines the Vars in VisualizationMono_Algorithm_Integration_VelodyneCamera.
*/

/*! \addtogroup VisualizationMono_Algorithm_Integration_VelodyneCamera_Vars
	@{
*/

/*! \file VisualizationMono_Algorithm_Integration_VelodyneCamera_Vars.h
	 Defines the Vars of VisualizationMono_Algorithm_Integration_VelodyneCamera
*/

//*******************Please add other headers below*******************
#include<glviewer.h>
#include<opencv2/opencv.hpp>

//The Vars is defined as below
/*! \class VisualizationMono_Algorithm_Integration_VelodyneCamera_Vars 
	\brief The Vars of VisualizationMono_Algorithm_Integration_VelodyneCamera.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Algorithm_Integration_VelodyneCamera_Vars 
{
public:
	/*! \fn VisualizationMono_Algorithm_Integration_VelodyneCamera_Vars()
		\brief The constructor of VisualizationMono_Algorithm_Integration_VelodyneCamera_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Algorithm_Integration_VelodyneCamera_Vars() 
	{
		image=new QLabel;
		image->setAlignment(Qt::AlignCenter);
		int i;
		for (i=0; i<256; i++)
		{
            colorTable.push_back(qRgb(i,i,i));
		}
		viewer=new GLViewer;
	}
	/*! \fn ~VisualizationMono_Algorithm_Integration_VelodyneCamera_Vars()
		\brief The destructor of VisualizationMono_Algorithm_Integration_VelodyneCamera_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Algorithm_Integration_VelodyneCamera_Vars() 
	{
		if(image->parent()==NULL)
		{
			delete image;
			image=NULL;
		}
		if(viewer->parent()==NULL)
		{
			delete viewer;
			viewer=NULL;
		}
	}
public:
	//*******************Please add variables below*******************
	QLabel * image;
	QVector<QRgb> colorTable;
	GLViewer *viewer;
	GLuint displaylist;
};

/*! @}*/ 

#endif
