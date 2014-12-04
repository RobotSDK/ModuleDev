//You need to modify this file.

#ifndef SENSORINTERNALEVENT_ALGORITHM_DETECTION_DPM_VARS_H
#define SENSORINTERNALEVENT_ALGORITHM_DETECTION_DPM_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorInternalEvent_Algorithm_Detection_DPM_Vars SensorInternalEvent_Algorithm_Detection_DPM_Vars
	\ingroup SensorInternalEvent_Algorithm_Detection_DPM
	\brief SensorInternalEvent_Algorithm_Detection_DPM_Vars defines the Vars in SensorInternalEvent_Algorithm_Detection_DPM.
*/

/*! \addtogroup SensorInternalEvent_Algorithm_Detection_DPM_Vars
	@{
*/

/*! \file SensorInternalEvent_Algorithm_Detection_DPM_Vars.h
	 Defines the Vars of SensorInternalEvent_Algorithm_Detection_DPM
*/

//*******************Please add other headers below*******************
#include<rosinterface.h>
#include<dpm/ImageObjects.h>

//The Vars is defined as below
/*! \class SensorInternalEvent_Algorithm_Detection_DPM_Vars 
	\brief The Vars of SensorInternalEvent_Algorithm_Detection_DPM.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_Algorithm_Detection_DPM_Vars 
{
public:
	/*! \fn SensorInternalEvent_Algorithm_Detection_DPM_Vars()
		\brief The constructor of SensorInternalEvent_Algorithm_Detection_DPM_Vars. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_Algorithm_Detection_DPM_Vars() 
	{
        topic="car_pos_xy";
        queuesize=1000;
        queryinterval=10;
        dpmsub=new ROSSub<dpm::ImageObjectsConstPtr>(topic,queuesize,queryinterval);
	}
	/*! \fn ~SensorInternalEvent_Algorithm_Detection_DPM_Vars()
		\brief The destructor of SensorInternalEvent_Algorithm_Detection_DPM_Vars. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_Algorithm_Detection_DPM_Vars() 
	{
        if(dpmsub!=NULL)
        {
            delete dpmsub;
            dpmsub=NULL;
        }
	}
public:
	//*******************Please add variables below*******************
    QString topic;
    u_int32_t queuesize;
    int queryinterval;
    ROSSub<dpm::ImageObjectsConstPtr> * dpmsub;
};

/*! @}*/ 

#endif
