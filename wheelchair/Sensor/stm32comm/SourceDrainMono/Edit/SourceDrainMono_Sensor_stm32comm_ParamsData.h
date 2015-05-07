//You need to modify this file.

#ifndef SOURCEDRAINMONO_SENSOR_STM32COMM_PARAMSDATA_H
#define SOURCEDRAINMONO_SENSOR_STM32COMM_PARAMSDATA_H

#include<RobotSDK_Global.h>
#include<serialport/qextserialport.h>

/*! \defgroup SourceDrainMono_Sensor_stm32comm_ParamsData SourceDrainMono_Sensor_stm32comm_ParamsData
	\ingroup SourceDrainMono_Sensor_stm32comm
	\brief SourceDrainMono_Sensor_stm32comm_ParamsData defines the ParamsData in SourceDrainMono_Sensor_stm32comm.
*/

/*! \addtogroup SourceDrainMono_Sensor_stm32comm_ParamsData
	@{
*/

/*! \file SourceDrainMono_Sensor_stm32comm_ParamsData.h
	 Defines the ParamsData of SourceDrainMono_Sensor_stm32comm
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params SensorInternalEvent_Sensor_Joystick_Params and Input Data SensorInternalEvent_Sensor_Joystick_Data
#include<wheelchair/Sensor/Joystick/SensorInternalEvent/Edit/SensorInternalEvent_Sensor_Joystick_ParamsData.h>

//0 new input data type(s) created

/*! \def SourceDrainMono_Sensor_stm32comm_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = SensorInternalEvent_Sensor_Joystick_Params, Data_Type = SensorInternalEvent_Sensor_Joystick_Data
*/
#define SourceDrainMono_Sensor_stm32comm_INPUTPORTSSIZE QList<int>()<<10

//The Params is defined as below
/*! \class SourceDrainMono_Sensor_stm32comm_Params 
	\brief The Params of SourceDrainMono_Sensor_stm32comm.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SourceDrainMono_Sensor_stm32comm_Params 
{
public:
	/*! \fn SourceDrainMono_Sensor_stm32comm_Params()
		\brief The constructor of SourceDrainMono_Sensor_stm32comm_Params. [required]
		\details ****Please add details below****

	*/
	SourceDrainMono_Sensor_stm32comm_Params() 
	{
        port = "/dev/ttyUSB0";
        baudrate = BAUD115200;
        databits = DATA_8;
        parity = PAR_NONE;
        stopbits = STOP_1;
        flowtype = FLOW_OFF;
        timeout = 500;
        qurymodel = QextSerialPort::EventDriven;

        recvpacksize = 1;
        recv_packhead = QByteArray(char(0xA2), 1);
        recv_packtail = QByteArray(char(0x2A), 1);

        send_packhead = QByteArray(char(0xF8), 1);
        send_packtail = QByteArray(char(0x8F), 1);

        distPerPulse = 1.0;
        maxpusle = 30000;

	}
	/*! \fn ~SourceDrainMono_Sensor_stm32comm_Params()
		\brief The destructor of SourceDrainMono_Sensor_stm32comm_Params. [required]
		\details *****Please add details below*****

	*/
	~SourceDrainMono_Sensor_stm32comm_Params() 
	{

	}
public:
	//*******************Please add variables below*******************
    QString port;
    BaudRateType baudrate;
    DataBitsType databits;
    ParityType parity;
    StopBitsType stopbits;
    FlowType flowtype;
    long timeout;
    QextSerialPort::QueryMode qurymodel;
    //串口接受数据头，和数据大小
    QByteArray recv_packhead;
    QByteArray recv_packtail;
    int recvpacksize;
    //串口发送数据头
    QByteArray send_packtail;
    QByteArray send_packhead;

    double WheelBase, WheelRadius;

    long maxpusle;
    double distPerPulse;
};

//The Output Data is defined as below
/*! \class SourceDrainMono_Sensor_stm32comm_Data 
	\brief The Data of SourceDrainMono_Sensor_stm32comm.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SourceDrainMono_Sensor_stm32comm_Data 
{
public:
	/*! \fn SourceDrainMono_Sensor_stm32comm_Data()
		\brief The constructor of SourceDrainMono_Sensor_stm32comm_Data. [required]
		\details ****Please add details below****

	*/
	SourceDrainMono_Sensor_stm32comm_Data() 
	{
		
	}
	/*! \fn ~SourceDrainMono_Sensor_stm32comm_Data()
		\brief The destructor of SourceDrainMono_Sensor_stm32comm_Data. [required]
		\details *****Please add details below*****

	*/
	~SourceDrainMono_Sensor_stm32comm_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    //for visualization
    double yaw;
};

/*! \def SourceDrainMono_Sensor_stm32comm_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define SourceDrainMono_Sensor_stm32comm_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
