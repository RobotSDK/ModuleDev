//You need to modify this file.

#ifndef VISUALIZATIONMULTI_VISUALIZATION_INTEGRATION_GROUNDOBJECTSDBM_VARS_H
#define VISUALIZATIONMULTI_VISUALIZATION_INTEGRATION_GROUNDOBJECTSDBM_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Vars VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Vars
	\ingroup VisualizationMulti_Visualization_Integration_GroundObjectsDBM
	\brief VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Vars defines the Vars in VisualizationMulti_Visualization_Integration_GroundObjectsDBM.
*/

/*! \addtogroup VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Vars
	@{
*/

/*! \file VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Vars.h
	 Defines the Vars of VisualizationMulti_Visualization_Integration_GroundObjectsDBM
*/

//*******************Please add other headers below*******************
#include<opencv2/opencv.hpp>

//The Vars is defined as below
/*! \class VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Vars 
	\brief The Vars of VisualizationMulti_Visualization_Integration_GroundObjectsDBM.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Vars 
{
public:
	/*! \fn VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Vars()
		\brief The constructor of VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Vars() 
	{
        image=new QLabel;
        image->setAlignment(Qt::AlignCenter);
        int i,j;
        for (i=0; i<256; i++)
        {
            colorTable.push_back(qRgb(i,i,i));
        }
        radius=1;
        boxcolors[0]=cv::Scalar(0,0,255);
        boxcolors[1]=cv::Scalar(0,255,0);
        boxcolors[2]=cv::Scalar(0,255,255);
        boxcolors[3]=cv::Scalar(255,0,0);
        boxcolors[4]=cv::Scalar(255,0,255);
        boxcolors[5]=cv::Scalar(255,255,0);
        thickness=2;
        range=40;

        cv::Mat gray(16,16,CV_8U);
        for(i=0;i<16;i++)
        {
            for(j=0;j<16;j++)
            {
                gray.at<uchar>(i,j)=uchar(i*16+j);
            }
        }
        cv::applyColorMap(gray,groundcolormap,cv::COLORMAP_HOT);
        cv::applyColorMap(gray,objectcolormap,cv::COLORMAP_JET);
	}
	/*! \fn ~VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Vars()
		\brief The destructor of VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Vars() 
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
    bool init;
    cv::Mat FP;
    int radius;
    cv::Scalar boxcolors[6];
    int thickness;
    float range;
    cv::Mat groundcolormap;
    cv::Mat objectcolormap;
};

/*! @}*/ 

#endif
