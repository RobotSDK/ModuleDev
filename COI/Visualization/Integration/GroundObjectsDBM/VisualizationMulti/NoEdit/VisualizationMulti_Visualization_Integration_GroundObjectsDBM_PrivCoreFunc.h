//You need not to modify this file.

/*! \defgroup VisualizationMulti_Visualization_Integration_GroundObjectsDBM VisualizationMulti_Visualization_Integration_GroundObjectsDBM
	\ingroup VisualizationMulti_Library Visualization_Integration_GroundObjectsDBM_NodeClass
	\brief VisualizationMulti_Visualization_Integration_GroundObjectsDBM defines the Visualization_Integration_GroundObjectsDBM in VisualizationMulti.
*/

#ifndef VISUALIZATIONMULTI_VISUALIZATION_INTEGRATION_GROUNDOBJECTSDBM_PRIVCOREFUNC_H
#define VISUALIZATIONMULTI_VISUALIZATION_INTEGRATION_GROUNDOBJECTSDBM_PRIVCOREFUNC_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMulti_Visualization_Integration_GroundObjectsDBM_PrivCoreFunc VisualizationMulti_Visualization_Integration_GroundObjectsDBM_PrivCoreFunc
	\ingroup VisualizationMulti_Visualization_Integration_GroundObjectsDBM
	\brief VisualizationMulti_Visualization_Integration_GroundObjectsDBM_PrivCoreFunc defines the PrivCoreFunc in VisualizationMulti_Visualization_Integration_GroundObjectsDBM.
*/

/*! \addtogroup VisualizationMulti_Visualization_Integration_GroundObjectsDBM_PrivCoreFunc
	@{
*/

/*! \file VisualizationMulti_Visualization_Integration_GroundObjectsDBM_PrivCoreFunc.h
	 Defines the PrivCoreFunc of VisualizationMulti_Visualization_Integration_GroundObjectsDBM
*/

//*******************Please add other headers below*******************


#include "../Edit/VisualizationMulti_Visualization_Integration_GroundObjectsDBM_ParamsData.h"
#include "../Edit/VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Vars.h"

/*! \def NODECONFIG
	\brief Forcefully defines the NodeType_NodeClass.
*/
#ifdef NODECONFIG
#undef NODECONFIG
#endif
#define NODECONFIG VisualizationMulti_Visualization_Integration_GroundObjectsDBM

/*! void VisualizationMulti_Visualization_Integration_GroundObjectsDBM_getPortsSize(QList<int> & inputPortsSize, int & outputPortsNumber)
	\brief [required] Function pointer type for interface function of getting node's port(s)' size.
	\param [out] inputPortsSize The size of each input port's data buffer.
	\param [out] outputPortsNumber The number of output ports.
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber);

/*! void VisualizationMulti_Visualization_Integration_GroundObjectsDBM_initializeParams(boost::shared_ptr<void> & paramsPtr)
	\brief [required] Function pointer type for interface function of initializing node's parameters.
	\param [out] paramsPtr The parameters embelished by boost::shared_pointer<void>.
	\details To initialize parameters:
	- paramsPtr=boost::shared_ptr<void> (new ParametersType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr);

/*! void VisualizationMulti_Visualization_Integration_GroundObjectsDBM_initializeVars(boost::shared_ptr<void> & varsPtr)
	\brief [required] Function pointer type for interface function of initializing node's variables.
	\param [out] varsPtr The variables embelished by boost::shared_pointer<void>.
	\details To initialize variables:
	- varsPtr=boost::shared_ptr<void> (new VariablesType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr);

/*! @}*/ 

#endif