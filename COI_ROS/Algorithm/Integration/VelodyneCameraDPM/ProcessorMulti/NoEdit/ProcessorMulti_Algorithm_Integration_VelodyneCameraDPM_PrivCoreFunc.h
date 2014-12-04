//You need not to modify this file.

/*! \defgroup ProcessorMulti_Algorithm_Integration_VelodyneCameraDPM ProcessorMulti_Algorithm_Integration_VelodyneCameraDPM
	\ingroup ProcessorMulti_Library Algorithm_Integration_VelodyneCameraDPM_NodeClass
	\brief ProcessorMulti_Algorithm_Integration_VelodyneCameraDPM defines the Algorithm_Integration_VelodyneCameraDPM in ProcessorMulti.
*/

#ifndef PROCESSORMULTI_ALGORITHM_INTEGRATION_VELODYNECAMERADPM_PRIVCOREFUNC_H
#define PROCESSORMULTI_ALGORITHM_INTEGRATION_VELODYNECAMERADPM_PRIVCOREFUNC_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Algorithm_Integration_VelodyneCameraDPM_PrivCoreFunc ProcessorMulti_Algorithm_Integration_VelodyneCameraDPM_PrivCoreFunc
	\ingroup ProcessorMulti_Algorithm_Integration_VelodyneCameraDPM
	\brief ProcessorMulti_Algorithm_Integration_VelodyneCameraDPM_PrivCoreFunc defines the PrivCoreFunc in ProcessorMulti_Algorithm_Integration_VelodyneCameraDPM.
*/

/*! \addtogroup ProcessorMulti_Algorithm_Integration_VelodyneCameraDPM_PrivCoreFunc
	@{
*/

/*! \file ProcessorMulti_Algorithm_Integration_VelodyneCameraDPM_PrivCoreFunc.h
	 Defines the PrivCoreFunc of ProcessorMulti_Algorithm_Integration_VelodyneCameraDPM
*/

//*******************Please add other headers below*******************


#include "../Edit/ProcessorMulti_Algorithm_Integration_VelodyneCameraDPM_ParamsData.h"
#include "../Edit/ProcessorMulti_Algorithm_Integration_VelodyneCameraDPM_Vars.h"

/*! \def NODECONFIG
	\brief Forcefully defines the NodeType_NodeClass.
*/
#ifdef NODECONFIG
#undef NODECONFIG
#endif
#define NODECONFIG ProcessorMulti_Algorithm_Integration_VelodyneCameraDPM

/*! void ProcessorMulti_Algorithm_Integration_VelodyneCameraDPM_getPortsSize(QList<int> & inputPortsSize, int & outputPortsNumber)
	\brief [required] Function pointer type for interface function of getting node's port(s)' size.
	\param [out] inputPortsSize The size of each input port's data buffer.
	\param [out] outputPortsNumber The number of output ports.
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber);

/*! void ProcessorMulti_Algorithm_Integration_VelodyneCameraDPM_initializeParams(boost::shared_ptr<void> & paramsPtr)
	\brief [required] Function pointer type for interface function of initializing node's parameters.
	\param [out] paramsPtr The parameters embelished by boost::shared_pointer<void>.
	\details To initialize parameters:
	- paramsPtr=boost::shared_ptr<void> (new ParametersType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr);

/*! void ProcessorMulti_Algorithm_Integration_VelodyneCameraDPM_initializeVars(boost::shared_ptr<void> & varsPtr)
	\brief [required] Function pointer type for interface function of initializing node's variables.
	\param [out] varsPtr The variables embelished by boost::shared_pointer<void>.
	\details To initialize variables:
	- varsPtr=boost::shared_ptr<void> (new VariablesType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr);

/*! @}*/ 

#endif