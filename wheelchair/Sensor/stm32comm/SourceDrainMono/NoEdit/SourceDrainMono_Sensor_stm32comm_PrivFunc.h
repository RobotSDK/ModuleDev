//You need not to modify this file.

#ifndef SOURCEDRAINMONO_SENSOR_STM32COMM_PRIVFUNC_H
#define SOURCEDRAINMONO_SENSOR_STM32COMM_PRIVFUNC_H

#include<RobotSDK_Global.h>

/*! \defgroup SourceDrainMono_Sensor_stm32comm_PrivFunc SourceDrainMono_Sensor_stm32comm_PrivFunc
	\ingroup SourceDrainMono_Sensor_stm32comm
	\brief SourceDrainMono_Sensor_stm32comm_PrivFunc defines the PrivFunc in SourceDrainMono_Sensor_stm32comm.
*/

/*! \addtogroup SourceDrainMono_Sensor_stm32comm_PrivFunc
	@{
*/

/*! \file SourceDrainMono_Sensor_stm32comm_PrivFunc.h
	 Defines the PrivFunc of SourceDrainMono_Sensor_stm32comm
*/

//*******************Please add other headers below*******************


#include "../Edit/SourceDrainMono_Sensor_stm32comm_Vars.h"

/*! \def NODECONFIG
	\brief Forcefully defines the NodeType_NodeClass.
*/
#ifdef NODECONFIG
#undef NODECONFIG
#endif
#define NODECONFIG SourceDrainMono_Sensor_stm32comm

/*! bool SourceDrainMono_Sensor_stm32comm_setParamsVarsOpenNode(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
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

/*! bool SourceDrainMono_Sensor_stm32comm_handleVarsCloseNode(void * paramsPtr, void * varsPtr)
	\brief [required] Function pointer type for interface function of handling node's variables while closing node.
	\param [in] paramsPtr The parameters(\ref Node::paramsptr) for setting variables.
	\param [in,out] varsPtr The variables(\ref Node::varsptr) to be handled
	\return 1 for success and 0 for failure.
*/
extern "C" ROBOTSDK_OUTPUT bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr);

/*! void SourceDrainMono_Sensor_stm32comm_getInternalTrigger(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
	\brief [optional] Function pointer type for interface function of getting node's internal trigger.
	\param [in] paramsPtr The node's parameters(\ref Node::paramsptr).
	\param [in] varsPtr The node's variables(\ref Node::varsptr) that contains internal trigger.
	\param [out] internalTrigger The internal trigger.
	\param [out] internalTriggerSignal The internal trigger signal embelished by QString.
	\details To embelish internal trigger signal:
	- QString(SIGNAL(<internal trigger signal>));
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal);

/*! void SourceDrainMono_Sensor_stm32comm_initializeOutputData(void * paramsPtr, void * varsPtr, boost::shared_ptr<void> & outputDataPtr)
	\brief [required] Function pointer type for interface function of initializing node's output data.
	\param [in] paramsPtr The node's parameters(\ref Node::paramsptr).
	\param [in] varsPtr The node's variables(\ref Node::varsptr).
	\param [out] outputDataPtr The output data embelished by boost::shared_pointer<void>.
	\details To initialize output data:
	- outputDataPtr=boost::shared_ptr<void> (new OutputDataType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeOutputData)(void * paramsPtr, void * varsPtr, boost::shared_ptr<void> & outputDataPtr);

/*! bool SourceDrainMono_Sensor_stm32comm_generateSourceData(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
	\brief [required] Function pointer type for interface function of generating source data.
	\param [in] paramsPtr The node's parameters(\ref Node::paramsptr).
	\param [in] varsPtr The node's variables(\ref Node::varsptr).
	\param [out] outputData The output data.
	\param [out] outputPortIndex The index of output port to send output data.
	\param [out] timeStamp The timestamp. Mainly used in simulator to get the timestamp of one data frame.
	\return 1 for success and 0 for failure.
*/
extern "C" ROBOTSDK_OUTPUT bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp);

/*! void SourceDrainMono_Sensor_stm32comm_getMonoDrainDataSize(void * paramsPtr, void * varsPtr, int & drainDataSize)
	\brief [required] Function pointer type for interface function of getting mono drain data size.
	\param [in] paramsPtr The node's parameters(\ref Node::paramsptr).
	\param [in] varsPtr The node's variables(\ref Node::varsptr).
	\param [out] drainDataSize The required mono drain data size. (see InputNode::grabDrainData(int grabSize))
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getMonoDrainDataSize)(void * paramsPtr, void * varsPtr, int & drainDataSize);

/*! bool SourceDrainMono_Sensor_stm32comm_processMonoDrainData(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
	\brief [required] Function pointer type for interface function of processing mono drain data.
	\param [in] paramsPtr The node's parameters(\ref Node::paramsptr).
	\param [in] varsPtr The node's variables(\ref Node::varsptr).
	\param [in] drainParams The mono drain parameters of input node.
	\param [in] drainData The mono drain data of input node.
	\return 1 for success and 0 for failure.
*/
extern "C" ROBOTSDK_OUTPUT bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData);

/*! @}*/ 

#endif