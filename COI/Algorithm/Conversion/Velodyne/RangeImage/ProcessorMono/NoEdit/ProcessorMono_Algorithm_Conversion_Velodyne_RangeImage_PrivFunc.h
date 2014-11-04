//You need not to modify this file.

#ifndef PROCESSORMONO_ALGORITHM_CONVERSION_VELODYNE_RANGEIMAGE_PRIVFUNC_H
#define PROCESSORMONO_ALGORITHM_CONVERSION_VELODYNE_RANGEIMAGE_PRIVFUNC_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_PrivFunc ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_PrivFunc
	\ingroup ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage
	\brief ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_PrivFunc defines the PrivFunc in ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage.
*/

/*! \addtogroup ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_PrivFunc
	@{
*/

/*! \file ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_PrivFunc.h
	 Defines the PrivFunc of ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage
*/

//*******************Please add other headers below*******************


#include "../Edit/ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_ParamsData.h"
#include "../Edit/ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Vars.h"

/*! \def NODECONFIG
	\brief Forcefully defines the NodeType_NodeClass.
*/
#ifdef NODECONFIG
#undef NODECONFIG
#endif
#define NODECONFIG ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage

/*! bool ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_setParamsVarsOpenNode(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
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

/*! bool ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_handleVarsCloseNode(void * paramsPtr, void * varsPtr)
	\brief [required] Function pointer type for interface function of handling node's variables while closing node.
	\param [in] paramsPtr The parameters(\ref Node::paramsptr) for setting variables.
	\param [in,out] varsPtr The variables(\ref Node::varsptr) to be handled
	\return 1 for success and 0 for failure.
*/
extern "C" ROBOTSDK_OUTPUT bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr);

/*! void ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_getInternalTrigger(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
	\brief [optional] Function pointer type for interface function of getting node's internal trigger.
	\param [in] paramsPtr The node's parameters(\ref Node::paramsptr).
	\param [in] varsPtr The node's variables(\ref Node::varsptr) that contains internal trigger.
	\param [out] internalTrigger The internal trigger.
	\param [out] internalTriggerSignal The internal trigger signal embelished by QString.
	\details To embelish internal trigger signal:
	- QString(SIGNAL(<internal trigger signal>));
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal);

/*! void ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_initializeOutputData(void * paramsPtr, void * varsPtr, boost::shared_ptr<void> & outputDataPtr)
	\brief [required] Function pointer type for interface function of initializing node's output data.
	\param [in] paramsPtr The node's parameters(\ref Node::paramsptr).
	\param [in] varsPtr The node's variables(\ref Node::varsptr).
	\param [out] outputDataPtr The output data embelished by boost::shared_pointer<void>.
	\details To initialize output data:
	- outputDataPtr=boost::shared_ptr<void> (new OutputDataType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeOutputData)(void * paramsPtr, void * varsPtr, boost::shared_ptr<void> & outputDataPtr);

/*! void ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_getMonoInputDataSize(void * paramsPtr, void * varsPtr, int & inputDataSize)
	\brief [required] Function pointer type for interface function of getting mono input data size.
	\param [in] paramsPtr The node's parameters(\ref Node::paramsptr).
	\param [in] varsPtr The node's variables(\ref Node::varsptr).
	\param [out] inputDataSize The required mono input data size. (see InputNode::grabInputData(int grabSize))
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getMonoInputDataSize)(void * paramsPtr, void * varsPtr, int & inputDataSize);

/*! bool ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_processMonoInputData(void * paramsPtr, void * varsPtr, QVector<void *> inputParams, QVector<void *> inputData, void * outputData, QList<int> & outputPortIndex)
	\brief [required] Function pointer type for interface function of processing mono input data.
	\param [in] paramsPtr The node's parameters(\ref Node::paramsptr).
	\param [in] varsPtr The node's variables(\ref Node::varsptr).
	\param [in] inputParams The mono input parameters of input node.
	\param [in] inputData The mono input data of input node.
	\param [out] outputData The output data.
	\param [out] outputPortIndex The index of output port to send output data.
	\return 1 for success and 0 for failure.
*/
extern "C" ROBOTSDK_OUTPUT bool DECOFUNC(processMonoInputData)(void * paramsPtr, void * varsPtr, QVector<void *> inputParams, QVector<void *> inputData, void * outputData, QList<int> & outputPortIndex);

/*! @}*/ 

#endif