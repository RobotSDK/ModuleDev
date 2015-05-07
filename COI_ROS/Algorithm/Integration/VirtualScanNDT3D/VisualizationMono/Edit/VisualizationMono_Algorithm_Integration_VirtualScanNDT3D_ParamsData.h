//You need to modify this file.

#ifndef VISUALIZATIONMONO_ALGORITHM_INTEGRATION_VIRTUALSCANNDT3D_PARAMSDATA_H
#define VISUALIZATIONMONO_ALGORITHM_INTEGRATION_VIRTUALSCANNDT3D_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_ParamsData VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_ParamsData
	\ingroup VisualizationMono_Algorithm_Integration_VirtualScanNDT3D
	\brief VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_ParamsData defines the ParamsData in VisualizationMono_Algorithm_Integration_VirtualScanNDT3D.
*/

/*! \addtogroup VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_ParamsData
	@{
*/

/*! \file VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_ParamsData.h
	 Defines the ParamsData of VisualizationMono_Algorithm_Integration_VirtualScanNDT3D
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Params and Input Data ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Data
#include<COI_ROS/Algorithm/Integration/VirtualScanNDT3D/ProcessorMulti/Edit/ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 0, Params_Type = ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Params, Data_Type = ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Data
*/
#define VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_INPUTPORTSSIZE QList<int>()<<0

//The Params is defined as below
/*! \class VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Params 
	\brief The Params of VisualizationMono_Algorithm_Integration_VirtualScanNDT3D.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Params 
{
public:
	/*! \fn VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Params()
		\brief The constructor of VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Params() 
	{
        maxrange=50;
        gridsize=5;
        imagewidth=600;
        imageheight=600;
        imagesize=600;
        frames=10;
        baseframe=2;
        showbeam=0;
	}
	/*! \fn ~VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Params()
		\brief The destructor of VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    int maxrange;
    int gridsize;
    int imageheight;
    int imagewidth;
    int imagesize;
    int frames;
    int baseframe;
    bool showbeam;
};

//There is no Output Data.

/*! \def VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMono_Algorithm_Integration_VirtualScanNDT3D_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif
