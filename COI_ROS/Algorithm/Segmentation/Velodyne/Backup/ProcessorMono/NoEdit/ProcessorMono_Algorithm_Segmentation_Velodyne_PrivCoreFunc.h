//You need not to modify this file.

/*! \defgroup ProcessorMono_Algorithm_Segmentation_Velodyne ProcessorMono_Algorithm_Segmentation_Velodyne
	\ingroup ProcessorMono_Library Algorithm_Segmentation_Velodyne_NodeClass
	\brief ProcessorMono_Algorithm_Segmentation_Velodyne defines the Algorithm_Segmentation_Velodyne in ProcessorMono.
*/

#ifndef PROCESSORMONO_ALGORITHM_SEGMENTATION_VELODYNE_PRIVCOREFUNC_H
#define PROCESSORMONO_ALGORITHM_SEGMENTATION_VELODYNE_PRIVCOREFUNC_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMono_Algorithm_Segmentation_Velodyne_PrivCoreFunc ProcessorMono_Algorithm_Segmentation_Velodyne_PrivCoreFunc
	\ingroup ProcessorMono_Algorithm_Segmentation_Velodyne
	\brief ProcessorMono_Algorithm_Segmentation_Velodyne_PrivCoreFunc defines the PrivCoreFunc in ProcessorMono_Algorithm_Segmentation_Velodyne.
*/

/*! \addtogroup ProcessorMono_Algorithm_Segmentation_Velodyne_PrivCoreFunc
	@{
*/

/*! \file ProcessorMono_Algorithm_Segmentation_Velodyne_PrivCoreFunc.h
	 Defines the PrivCoreFunc of ProcessorMono_Algorithm_Segmentation_Velodyne
*/

//*******************Please add other headers below*******************


#include "../Edit/ProcessorMono_Algorithm_Segmentation_Velodyne_ParamsData.h"
#include "../Edit/ProcessorMono_Algorithm_Segmentation_Velodyne_Vars.h"

/*! \def NODECONFIG
	\brief Forcefully defines the NodeType_NodeClass.
*/
#ifdef NODECONFIG
#undef NODECONFIG
#endif
#define NODECONFIG ProcessorMono_Algorithm_Segmentation_Velodyne

/*! void ProcessorMono_Algorithm_Segmentation_Velodyne_getPortsSize(QList<int> & inputPortsSize, int & outputPortsNumber)
	\brief [required] Function pointer type for interface function of getting node's port(s)' size.
	\param [out] inputPortsSize The size of each input port's data buffer.
	\param [out] outputPortsNumber The number of output ports.
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber);

/*! void ProcessorMono_Algorithm_Segmentation_Velodyne_initializeParams(boost::shared_ptr<void> & paramsPtr)
	\brief [required] Function pointer type for interface function of initializing node's parameters.
	\param [out] paramsPtr The parameters embelished by boost::shared_pointer<void>.
	\details To initialize parameters:
	- paramsPtr=boost::shared_ptr<void> (new ParametersType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr);

/*! void ProcessorMono_Algorithm_Segmentation_Velodyne_initializeVars(boost::shared_ptr<void> & varsPtr)
	\brief [required] Function pointer type for interface function of initializing node's variables.
	\param [out] varsPtr The variables embelished by boost::shared_pointer<void>.
	\details To initialize variables:
	- varsPtr=boost::shared_ptr<void> (new VariablesType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr);

/*! @}*/ 

#endif