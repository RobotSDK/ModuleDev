//You need to modify this file.

#ifndef SENSORINTERNALEVENT_ALGORITHM_LOCALIZATION_NDT3D_VARS_H
#define SENSORINTERNALEVENT_ALGORITHM_LOCALIZATION_NDT3D_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorInternalEvent_Algorithm_Localization_NDT3D_Vars SensorInternalEvent_Algorithm_Localization_NDT3D_Vars
	\ingroup SensorInternalEvent_Algorithm_Localization_NDT3D
	\brief SensorInternalEvent_Algorithm_Localization_NDT3D_Vars defines the Vars in SensorInternalEvent_Algorithm_Localization_NDT3D.
*/

/*! \addtogroup SensorInternalEvent_Algorithm_Localization_NDT3D_Vars
	@{
*/

/*! \file SensorInternalEvent_Algorithm_Localization_NDT3D_Vars.h
	 Defines the Vars of SensorInternalEvent_Algorithm_Localization_NDT3D
*/

//*******************Please add other headers below*******************
#include<rosinterface.h>

//The Vars is defined as below
/*! \class SensorInternalEvent_Algorithm_Localization_NDT3D_Vars 
	\brief The Vars of SensorInternalEvent_Algorithm_Localization_NDT3D.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_Algorithm_Localization_NDT3D_Vars 
{
public:
	/*! \fn SensorInternalEvent_Algorithm_Localization_NDT3D_Vars()
		\brief The constructor of SensorInternalEvent_Algorithm_Localization_NDT3D_Vars. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_Algorithm_Localization_NDT3D_Vars() 
	{
        destinationframe="ndt_frame";
        originalframe="world";
        queryinterval=10;
        ndt3dsub=new ROSTFSub(destinationframe,originalframe,queryinterval);
	}
	/*! \fn ~SensorInternalEvent_Algorithm_Localization_NDT3D_Vars()
		\brief The destructor of SensorInternalEvent_Algorithm_Localization_NDT3D_Vars. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_Algorithm_Localization_NDT3D_Vars() 
	{
        if(ndt3dsub!=NULL)
        {
            delete ndt3dsub;
            ndt3dsub=NULL;
        }
	}
public:
	//*******************Please add variables below*******************
    QString destinationframe;
    QString originalframe;
    int queryinterval;
    ROSTFSub * ndt3dsub;
};

/*! @}*/ 

#endif
