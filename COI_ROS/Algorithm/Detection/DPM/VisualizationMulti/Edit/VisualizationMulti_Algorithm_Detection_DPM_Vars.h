//You need to modify this file.

#ifndef VISUALIZATIONMULTI_ALGORITHM_DETECTION_DPM_VARS_H
#define VISUALIZATIONMULTI_ALGORITHM_DETECTION_DPM_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMulti_Algorithm_Detection_DPM_Vars VisualizationMulti_Algorithm_Detection_DPM_Vars
	\ingroup VisualizationMulti_Algorithm_Detection_DPM
	\brief VisualizationMulti_Algorithm_Detection_DPM_Vars defines the Vars in VisualizationMulti_Algorithm_Detection_DPM.
*/

/*! \addtogroup VisualizationMulti_Algorithm_Detection_DPM_Vars
	@{
*/

/*! \file VisualizationMulti_Algorithm_Detection_DPM_Vars.h
	 Defines the Vars of VisualizationMulti_Algorithm_Detection_DPM
*/

//*******************Please add other headers below*******************


//The Vars is defined as below
/*! \class VisualizationMulti_Algorithm_Detection_DPM_Vars 
	\brief The Vars of VisualizationMulti_Algorithm_Detection_DPM.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMulti_Algorithm_Detection_DPM_Vars 
{
public:
	/*! \fn VisualizationMulti_Algorithm_Detection_DPM_Vars()
		\brief The constructor of VisualizationMulti_Algorithm_Detection_DPM_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMulti_Algorithm_Detection_DPM_Vars() 
	{
        viewer=new QLabel("Image");
        viewer->setAlignment(Qt::AlignCenter);
        QScrollArea * scroll=new QScrollArea;
        scroll->setWidget(viewer);
        tabwidget=new QTabWidget;
        tabwidget->addTab(scroll,"TimeStamp");

        int i;
        for (i=0; i<256; i++)
        {
            colorTable.push_back(qRgb(i,i,i));
        }
	}
	/*! \fn ~VisualizationMulti_Algorithm_Detection_DPM_Vars()
		\brief The destructor of VisualizationMulti_Algorithm_Detection_DPM_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMulti_Algorithm_Detection_DPM_Vars() 
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
    struct CameraBufferData
    {
        QTime timestamp;
        cv::Mat cvimage;
    };
    struct DPMBufferData
    {
        QTime timestamp;
        QVector<cv::Rect> cvdetection;
    };
    QVector<CameraBufferData> camerabuffer;
    QVector<DPMBufferData> dpmbuffer;
};

/*! @}*/ 

#endif
