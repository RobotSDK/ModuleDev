//You need to modify this file.

#ifndef VISUALIZATIONMONO_SENSOR_CAMERA_VARS_H
#define VISUALIZATIONMONO_SENSOR_CAMERA_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Sensor_Camera_Vars VisualizationMono_Sensor_Camera_Vars
	\ingroup VisualizationMono_Sensor_Camera
	\brief VisualizationMono_Sensor_Camera_Vars defines the Vars in VisualizationMono_Sensor_Camera.
*/

/*! \addtogroup VisualizationMono_Sensor_Camera_Vars
	@{
*/

/*! \file VisualizationMono_Sensor_Camera_Vars.h
	 Defines the Vars of VisualizationMono_Sensor_Camera
*/

//*******************Please add other headers below*******************


//The Vars is defined as below
/*! \class VisualizationMono_Sensor_Camera_Vars 
	\brief The Vars of VisualizationMono_Sensor_Camera.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Sensor_Camera_Vars 
{
public:
	/*! \fn VisualizationMono_Sensor_Camera_Vars()
		\brief The constructor of VisualizationMono_Sensor_Camera_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Sensor_Camera_Vars() 
	{
        image=new QLabel;
        image->setAlignment(Qt::AlignCenter);
        int i;
        for (i=0; i<256; i++)
        {
            colorTable.push_back(qRgb(i,i,i));
        }
	}
	/*! \fn ~VisualizationMono_Sensor_Camera_Vars()
		\brief The destructor of VisualizationMono_Sensor_Camera_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Sensor_Camera_Vars() 
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
