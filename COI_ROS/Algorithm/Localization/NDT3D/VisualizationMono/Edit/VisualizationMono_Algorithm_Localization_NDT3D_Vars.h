//You need to modify this file.

#ifndef VISUALIZATIONMONO_ALGORITHM_LOCALIZATION_NDT3D_VARS_H
#define VISUALIZATIONMONO_ALGORITHM_LOCALIZATION_NDT3D_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Algorithm_Localization_NDT3D_Vars VisualizationMono_Algorithm_Localization_NDT3D_Vars
	\ingroup VisualizationMono_Algorithm_Localization_NDT3D
	\brief VisualizationMono_Algorithm_Localization_NDT3D_Vars defines the Vars in VisualizationMono_Algorithm_Localization_NDT3D.
*/

/*! \addtogroup VisualizationMono_Algorithm_Localization_NDT3D_Vars
	@{
*/

/*! \file VisualizationMono_Algorithm_Localization_NDT3D_Vars.h
	 Defines the Vars of VisualizationMono_Algorithm_Localization_NDT3D
*/

//*******************Please add other headers below*******************
#include<glviewer.h>

//The Vars is defined as below
/*! \class VisualizationMono_Algorithm_Localization_NDT3D_Vars 
	\brief The Vars of VisualizationMono_Algorithm_Localization_NDT3D.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Algorithm_Localization_NDT3D_Vars 
{
public:
	/*! \fn VisualizationMono_Algorithm_Localization_NDT3D_Vars()
		\brief The constructor of VisualizationMono_Algorithm_Localization_NDT3D_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Algorithm_Localization_NDT3D_Vars() 
	{
        viewer=new GLViewer;
        tabwidget=new QTabWidget;
        tabwidget->addTab(viewer,"TimeStamp");
        localflag=0;
	}
	/*! \fn ~VisualizationMono_Algorithm_Localization_NDT3D_Vars()
		\brief The destructor of VisualizationMono_Algorithm_Localization_NDT3D_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Algorithm_Localization_NDT3D_Vars() 
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
    GLuint ndt3dlist;
    QVector<double> positions;
    bool localflag;
};

/*! @}*/ 

#endif
