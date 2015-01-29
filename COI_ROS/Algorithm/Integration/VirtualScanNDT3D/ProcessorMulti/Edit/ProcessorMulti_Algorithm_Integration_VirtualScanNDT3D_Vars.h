//You need to modify this file.

#ifndef PROCESSORMULTI_ALGORITHM_INTEGRATION_VIRTUALSCANNDT3D_VARS_H
#define PROCESSORMULTI_ALGORITHM_INTEGRATION_VIRTUALSCANNDT3D_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Vars ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Vars
	\ingroup ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D
	\brief ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Vars defines the Vars in ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D.
*/

/*! \addtogroup ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Vars
	@{
*/

/*! \file ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Vars.h
	 Defines the Vars of ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D
*/

//*******************Please add other headers below*******************
#include<datasync.h>

//The Vars is defined as below
/*! \class ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Vars 
	\brief The Vars of ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Vars 
{
public:
	/*! \fn ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Vars()
		\brief The constructor of ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Vars. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Vars() 
	{
		
	}
	/*! \fn ~ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Vars()
		\brief The destructor of ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Vars. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    struct VirtualScanBufferData
    {
        QTime timestamp;
        QVector<double> virtualscan;
        QVector<double> heights;
    };
    struct NDT3DBufferData
    {
        QTime timestamp;
        cv::Mat cvtransform;
    };
    DataSync<VirtualScanBufferData,NDT3DBufferData> datasync;
};

/*! @}*/ 

#endif
