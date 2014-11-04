//You need to modify this file.

#ifndef VISUALIZATIONMONO_ALGORITHM_CONVERSION_VELODYNE_RANGEIMAGE_VARS_H
#define VISUALIZATIONMONO_ALGORITHM_CONVERSION_VELODYNE_RANGEIMAGE_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_Vars VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_Vars
	\ingroup VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage
	\brief VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_Vars defines the Vars in VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage.
*/

/*! \addtogroup VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_Vars
	@{
*/

/*! \file VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_Vars.h
	 Defines the Vars of VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage
*/

//*******************Please add other headers below*******************


//The Vars is defined as below
#include<COI/Sensor/Velodyne/VisualizationMono/Edit/VisualizationMono_Sensor_Velodyne_Vars.h>

/*! \class VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_Vars : public Simulator_Sensor_Velodyne_Vars 
	\brief The Vars of VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_Vars : public VisualizationMono_Sensor_Velodyne_Vars
{
public:
	/*! \fn VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_Vars()
		\brief The constructor of VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_Vars() 
	{
        image=new QLabel;
        image->setAlignment(Qt::AlignCenter);
        int i;
        for (i=0; i<256; i++)
        {
            colorTable.push_back(qRgb(i,i,i));
        }
	}
	/*! \fn ~VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_Vars()
		\brief The destructor of VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_Vars() 
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
};

/*! @}*/ 

#endif
