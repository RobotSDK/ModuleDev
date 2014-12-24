//You need to modify this file.

#ifndef VISUALIZATIONMONO_ALGORITHM_SEGMENTATION_VELODYNE_VARS_H
#define VISUALIZATIONMONO_ALGORITHM_SEGMENTATION_VELODYNE_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Algorithm_Segmentation_Velodyne_Vars VisualizationMono_Algorithm_Segmentation_Velodyne_Vars
	\ingroup VisualizationMono_Algorithm_Segmentation_Velodyne
	\brief VisualizationMono_Algorithm_Segmentation_Velodyne_Vars defines the Vars in VisualizationMono_Algorithm_Segmentation_Velodyne.
*/

/*! \addtogroup VisualizationMono_Algorithm_Segmentation_Velodyne_Vars
	@{
*/

/*! \file VisualizationMono_Algorithm_Segmentation_Velodyne_Vars.h
	 Defines the Vars of VisualizationMono_Algorithm_Segmentation_Velodyne
*/

//*******************Please add other headers below*******************
#include<glviewer.h>

//The Vars is defined as below
/*! \class VisualizationMono_Algorithm_Segmentation_Velodyne_Vars 
	\brief The Vars of VisualizationMono_Algorithm_Segmentation_Velodyne.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Algorithm_Segmentation_Velodyne_Vars 
{
public:
	/*! \fn VisualizationMono_Algorithm_Segmentation_Velodyne_Vars()
		\brief The constructor of VisualizationMono_Algorithm_Segmentation_Velodyne_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Algorithm_Segmentation_Velodyne_Vars() 
	{
        viewer=new GLViewer;
        tabwidget=new QTabWidget;
        tabwidget->addTab(viewer,"TimeStamp");
	}
	/*! \fn ~VisualizationMono_Algorithm_Segmentation_Velodyne_Vars()
		\brief The destructor of VisualizationMono_Algorithm_Segmentation_Velodyne_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Algorithm_Segmentation_Velodyne_Vars() 
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
    GLViewer * viewer;
    GLuint velodynelist;
    GLuint segmentlist;
    GLuint linklist;
};

/*! @}*/ 

#endif
