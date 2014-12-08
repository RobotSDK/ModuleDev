//You need to modify this file.

#ifndef VISUALIZATIONMULTI_ALGORITHM_INTEGRATION_VELODYNECAMERADPM_VARS_H
#define VISUALIZATIONMULTI_ALGORITHM_INTEGRATION_VELODYNECAMERADPM_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Vars VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Vars
	\ingroup VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM
	\brief VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Vars defines the Vars in VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM.
*/

/*! \addtogroup VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Vars
	@{
*/

/*! \file VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Vars.h
	 Defines the Vars of VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM
*/

//*******************Please add other headers below*******************
#include<pcl/point_cloud.h>
#include<pcl/point_types.h>
#include<opencv2/opencv.hpp>

//The Vars is defined as below
/*! \class VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Vars 
	\brief The Vars of VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Vars 
{
public:
	/*! \fn VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Vars()
		\brief The constructor of VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Vars() 
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

        cv::Mat greymat=cv::Mat(1,256,CV_8UC1);
        for(i=0;i<256;i++)
        {
            greymat.at<uchar>(i)=i;
        }
        cv::applyColorMap(greymat,colormap,cv::COLORMAP_JET);

        maxrange=30;
        minrange=0;
    }
	/*! \fn ~VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Vars()
		\brief The destructor of VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Vars() 
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
    struct VelodyneCameraBufferData
    {
        QTime cameratimestamp;
        cv::Mat cvimage;
        QVector<double>ranges;
    };
    struct DPMBufferData
    {
        QTime timestamp;
        QVector<cv::Rect> cvdetection;
    };
    QVector<VelodyneCameraBufferData> velodynecamerabuffer;
    QVector<DPMBufferData> dpmbuffer;
    cv::Mat colormap;
    double maxrange;
    double minrange;
};

/*! @}*/ 

#endif
