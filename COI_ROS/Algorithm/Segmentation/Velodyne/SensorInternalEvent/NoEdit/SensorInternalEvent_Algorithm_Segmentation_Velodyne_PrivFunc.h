//You need not to modify this file.

#ifndef SENSORINTERNALEVENT_ALGORITHM_SEGMENTATION_VELODYNE_PRIVFUNC_H
#define SENSORINTERNALEVENT_ALGORITHM_SEGMENTATION_VELODYNE_PRIVFUNC_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorInternalEvent_Algorithm_Segmentation_Velodyne_PrivFunc SensorInternalEvent_Algorithm_Segmentation_Velodyne_PrivFunc
	\ingroup SensorInternalEvent_Algorithm_Segmentation_Velodyne
	\brief SensorInternalEvent_Algorithm_Segmentation_Velodyne_PrivFunc defines the PrivFunc in SensorInternalEvent_Algorithm_Segmentation_Velodyne.
*/

/*! \addtogroup SensorInternalEvent_Algorithm_Segmentation_Velodyne_PrivFunc
	@{
*/

/*! \file SensorInternalEvent_Algorithm_Segmentation_Velodyne_PrivFunc.h
	 Defines the PrivFunc of SensorInternalEvent_Algorithm_Segmentation_Velodyne
*/

//*******************Please add other headers below*******************


#include "../Edit/SensorInternalEvent_Algorithm_Segmentation_Velodyne_ParamsData.h"
#include "../Edit/SensorInternalEvent_Algorithm_Segmentation_Velodyne_Vars.h"

/*! \def NODECONFIG
	\brief Forcefully defines the NodeType_NodeClass.
*/
#ifdef NODECONFIG
#undef NODECONFIG
#endif
#define NODECONFIG SensorInternalEvent_Algorithm_Segmentation_Velodyne

/*! bool SensorInternalEvent_Algorithm_Segmentation_Velodyne_setParamsVarsOpenNode(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
	\brief [required] Function pointer type for interface function of setting node's parameters and variables while openning node.
	\param [in] qstrConfigName The config-name of the node.
	\param [in] qstrNodeType The type-name of the node.
	\param [in] qstrNodeClass The class-name of the node.
	\param [in] qstrNodeName The node-name of the node.
	\param [in,out] paramsPtr The parameters(\ref Node::paramsptr) to be loaded.
	\param [in,out] varsPtr The variables(\ref Node::varsptr) to be set
	\return 1 for success and 0 for failure.
*/
extern "C" ROBOTSDK_OUTPUT bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr);

/*! bool SensorInternalEvent_Algorithm_Segmentation_Velodyne_handleVarsCloseNode(void * paramsPtr, void * varsPtr)
	\brief [required] Function pointer type for interface function of handling node's variables while closing node.
	\param [in] paramsPtr The parameters(\ref Node::paramsptr) for setting variables.
	\param [in,out] varsPtr The variables(\ref Node::varsptr) to be handled
	\return 1 for success and 0 for failure.
*/
extern "C" ROBOTSDK_OUTPUT bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr);

/*! void SensorInternalEvent_Algorithm_Segmentation_Velodyne_getInternalTrigger(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
	\brief [optional] Function pointer type for interface function of getting node's internal trigger.
	\param [in] paramsPtr The node's parameters(\ref Node::paramsptr).
	\param [in] varsPtr The node's variables(\ref Node::varsptr) that contains internal trigger.
	\param [out] internalTrigger The internal trigger.
	\param [out] internalTriggerSignal The internal trigger signal embelished by QString.
	\details To embelish internal trigger signal:
	- QString(SIGNAL(<internal trigger signal>));
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal);

/*! void SensorInternalEvent_Algorithm_Segmentation_Velodyne_initializeOutputData(void * paramsPtr, void * varsPtr, boost::shared_ptr<void> & outputDataPtr)
	\brief [required] Function pointer type for interface function of initializing node's output data.
	\param [in] paramsPtr The node's parameters(\ref Node::paramsptr).
	\param [in] varsPtr The node's variables(\ref Node::varsptr).
	\param [out] outputDataPtr The output data embelished by boost::shared_pointer<void>.
	\details To initialize output data:
	- outputDataPtr=boost::shared_ptr<void> (new OutputDataType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeOutputData)(void * paramsPtr, void * varsPtr, boost::shared_ptr<void> & outputDataPtr);

/*! bool SensorInternalEvent_Algorithm_Segmentation_Velodyne_generateSourceData(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
	\brief [required] Function pointer type for interface function of generating source data.
	\param [in] paramsPtr The node's parameters(\ref Node::paramsptr).
	\param [in] varsPtr The node's variables(\ref Node::varsptr).
	\param [out] outputData The output data.
	\param [out] outputPortIndex The index of output port to send output data.
	\param [out] timeStamp The timestamp. Mainly used in simulator to get the timestamp of one data frame.
	\return 1 for success and 0 for failure.
*/
extern "C" ROBOTSDK_OUTPUT bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp);

/*! @}*/ 

#endif