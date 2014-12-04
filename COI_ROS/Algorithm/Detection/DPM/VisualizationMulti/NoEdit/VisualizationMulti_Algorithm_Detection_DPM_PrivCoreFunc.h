//You need not to modify this file.

/*! \defgroup VisualizationMulti_Algorithm_Detection_DPM VisualizationMulti_Algorithm_Detection_DPM
	\ingroup VisualizationMulti_Library Algorithm_Detection_DPM_NodeClass
	\brief VisualizationMulti_Algorithm_Detection_DPM defines the Algorithm_Detection_DPM in VisualizationMulti.
*/

#ifndef VISUALIZATIONMULTI_ALGORITHM_DETECTION_DPM_PRIVCOREFUNC_H
#define VISUALIZATIONMULTI_ALGORITHM_DETECTION_DPM_PRIVCOREFUNC_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMulti_Algorithm_Detection_DPM_PrivCoreFunc VisualizationMulti_Algorithm_Detection_DPM_PrivCoreFunc
	\ingroup VisualizationMulti_Algorithm_Detection_DPM
	\brief VisualizationMulti_Algorithm_Detection_DPM_PrivCoreFunc defines the PrivCoreFunc in VisualizationMulti_Algorithm_Detection_DPM.
*/

/*! \addtogroup VisualizationMulti_Algorithm_Detection_DPM_PrivCoreFunc
	@{
*/

/*! \file VisualizationMulti_Algorithm_Detection_DPM_PrivCoreFunc.h
	 Defines the PrivCoreFunc of VisualizationMulti_Algorithm_Detection_DPM
*/

//*******************Please add other headers below*******************


#include "../Edit/VisualizationMulti_Algorithm_Detection_DPM_ParamsData.h"
#include "../Edit/VisualizationMulti_Algorithm_Detection_DPM_Vars.h"

/*! \def NODECONFIG
	\brief Forcefully defines the NodeType_NodeClass.
*/
#ifdef NODECONFIG
#undef NODECONFIG
#endif
#define NODECONFIG VisualizationMulti_Algorithm_Detection_DPM

/*! void VisualizationMulti_Algorithm_Detection_DPM_getPortsSize(QList<int> & inputPortsSize, int & outputPortsNumber)
	\brief [required] Function pointer type for interface function of getting node's port(s)' size.
	\param [out] inputPortsSize The size of each input port's data buffer.
	\param [out] outputPortsNumber The number of output ports.
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber);

/*! void VisualizationMulti_Algorithm_Detection_DPM_initializeParams(boost::shared_ptr<void> & paramsPtr)
	\brief [required] Function pointer type for interface function of initializing node's parameters.
	\param [out] paramsPtr The parameters embelished by boost::shared_pointer<void>.
	\details To initialize parameters:
	- paramsPtr=boost::shared_ptr<void> (new ParametersType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr);

/*! void VisualizationMulti_Algorithm_Detection_DPM_initializeVars(boost::shared_ptr<void> & varsPtr)
	\brief [required] Function pointer type for interface function of initializing node's variables.
	\param [out] varsPtr The variables embelished by boost::shared_pointer<void>.
	\details To initialize variables:
	- varsPtr=boost::shared_ptr<void> (new VariablesType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr);

/*! @}*/ 

#endif