//You need to program this file.

#include "../NoEdit/SourceDrainMono_Sensor_stm32comm_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	SourceDrainMono_Sensor_stm32comm_Params * params=(SourceDrainMono_Sensor_stm32comm_Params *)paramsPtr;
	SourceDrainMono_Sensor_stm32comm_Vars * vars=(SourceDrainMono_Sensor_stm32comm_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader, params, port);
    GetEnumParamValue(xmlloader, params, baudrate);
    GetEnumParamValue(xmlloader, params, qurymodel);

    GetParamValue(xmlloader, params, recv_packhead);
    GetParamValue(xmlloader, params, recv_packtail);
    GetParamValue(xmlloader, params, send_packhead);
    GetParamValue(xmlloader, params, send_packtail);
    GetParamValue(xmlloader, params, distPerPulse);
    GetParamValue(xmlloader, params, maxpusle);
    GetParamValue(xmlloader, params, WheelBase);
    GetParamValue(xmlloader, params, WheelRadius);

    GetParamValue(xmlloader, params, recvpacksize);

    GetParamValue(xmlloader, vars, encoderrange);

    vars->serialport.setPortName(params->port);
    vars->serialport.setBaudRate(params->baudrate);
    vars->serialport.setDataBits(params->databits);
    vars->serialport.setParity(params->parity);
    vars->serialport.setStopBits(params->stopbits);
    vars->serialport.setFlowControl(params->flowtype);
    vars->serialport.setTimeout(params->timeout);
    vars->serialport.setQueryMode(params->qurymodel);

    if(!(vars->serialport.open(QIODevice::ReadWrite)))
        return 0;
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	SourceDrainMono_Sensor_stm32comm_Params * params=(SourceDrainMono_Sensor_stm32comm_Params *)paramsPtr;
	SourceDrainMono_Sensor_stm32comm_Vars * vars=(SourceDrainMono_Sensor_stm32comm_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->serialport.close();
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	SourceDrainMono_Sensor_stm32comm_Params * params=(SourceDrainMono_Sensor_stm32comm_Params *)paramsPtr;
	SourceDrainMono_Sensor_stm32comm_Vars * vars=(SourceDrainMono_Sensor_stm32comm_Vars *)varsPtr;
    internalTrigger=&(vars->serialport);
    internalTriggerSignal=QString(SIGNAL(readyRead()));

	/*======Occasionally Program above======*/
	/*
	Function: get internal trigger [defined in vars] for node.
	You need to program here when you need internal trigger (internalTrigger + internalTriggerSignal) for node.
	E.g.
	internalTrigger=&(vars->trigger);
	internalTriggerSignal=QString(SIGNAL(triggerSignal()));
	*/
}

void DECOFUNC(initializeOutputData)(void * paramsPtr, void * varsPtr, boost::shared_ptr<void> & outputDataPtr)
{
	SourceDrainMono_Sensor_stm32comm_Params * params=(SourceDrainMono_Sensor_stm32comm_Params *)paramsPtr;
	SourceDrainMono_Sensor_stm32comm_Vars * vars=(SourceDrainMono_Sensor_stm32comm_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new SourceDrainMono_Sensor_stm32comm_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
	SourceDrainMono_Sensor_stm32comm_Params * params=(SourceDrainMono_Sensor_stm32comm_Params *)paramsPtr;
	SourceDrainMono_Sensor_stm32comm_Vars * vars=(SourceDrainMono_Sensor_stm32comm_Vars *)varsPtr;
	SourceDrainMono_Sensor_stm32comm_Data * outputdata=(SourceDrainMono_Sensor_stm32comm_Data *)outputData;
	outputPortIndex=QList<int>();
	timeStamp=QTime();
	/*======Please Program below======*/
	/*
	Step 1: fill outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	Step 3: set the timeStamp for Simulator.
	*/
    if(vars->serialport.bytesAvailable() < params->recvpacksize)
        return 0;

    QByteArray datagram = vars->serialport.readAll();

    int startid = datagram.indexOf(params->recv_packhead);
    int skip = params->recvpacksize - 1;
    if(startid > 0)
    {
        int endid = datagram.indexOf(params->recv_packtail, startid+skip);
        if((endid - skip) == startid)
        {
            QByteArray tmpdata = datagram.mid(startid+params->recv_packhead.size(), endid-(startid+params->recv_packhead.size()));
            vars->roll = *((short*)(tmpdata.data()));
            vars->roll = vars->roll/10.0*180.0/vars->pi;

            vars->pitch = *((short*)(tmpdata.data() + sizeof(short)));
            vars->pitch = vars->pitch/10.0*180.0/vars->pi;

            vars->yaw = *((short*)(tmpdata.data() + 2*sizeof(short)));
            vars->yaw = vars->yaw/10.0*180.0/vars->pi;

            vars->l_encoder = *((short*)(tmpdata.data() + 3*sizeof(short)));
            vars->r_encoder = *((short*)(tmpdata.data() + 4*sizeof(short)));
        }
    }
	return 1;
}

void DECOFUNC(getMonoDrainDataSize)(void * paramsPtr, void * varsPtr, int & drainDataSize)
{
	SourceDrainMono_Sensor_stm32comm_Params * params=(SourceDrainMono_Sensor_stm32comm_Params *)paramsPtr;
	SourceDrainMono_Sensor_stm32comm_Vars * vars=(SourceDrainMono_Sensor_stm32comm_Vars *)varsPtr;
	drainDataSize=0;
	/*======Please Program above======*/
	/*
	Function: get drain data size to be grabbed from buffer.
	Rules:
	drainDataSize=0: grab and remove all data from buffer.
	drainDataSize>0: grab drainDataSize latest data from buffer.
	drainDataSize<0: grab and remove drainDataSize ancient data from buffer.
	*/
}

//Input Port #0: Buffer_Size = 10, Params_Type = SensorInternalEvent_Sensor_Joystick_Params, Data_Type = SensorInternalEvent_Sensor_Joystick_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
	SourceDrainMono_Sensor_stm32comm_Params * params=(SourceDrainMono_Sensor_stm32comm_Params *)paramsPtr;
	SourceDrainMono_Sensor_stm32comm_Vars * vars=(SourceDrainMono_Sensor_stm32comm_Vars *)varsPtr;
	QVector<SensorInternalEvent_Sensor_Joystick_Params *> drainparams; copyQVector(drainparams,drainParams);
	QVector<SensorInternalEvent_Sensor_Joystick_Data *> draindata; copyQVector(draindata,drainData);
	if(draindata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata.
	*/
    SensorInternalEvent_Sensor_Joystick_Data* inputdata = draindata.front();
    double left_vel = inputdata->linear_vel + params->WheelBase*inputdata->angular_vel/2;
    double right_vel = inputdata->linear_vel - params->WheelBase*inputdata->angular_vel/2;

    double tmp_motor = left_vel/(params->WheelBase/2)*1.5; //1.5 =>大齿轮90齿，小齿轮60齿，转速与齿轮数成反比，转速与角速度正比（w=2*pi*n/60）
    short left_motor = tmp_motor*2000/(2*vars->pi); //500线编码器，4倍频后转一圈2000脉冲。该变量的单位是（脉冲／秒）

    tmp_motor = right_vel/(params->WheelBase/2)*1.5;
    short right_motor = tmp_motor*2000/(2*vars->pi);

    char dataput[7];
    char data_size = 4;
    dataput[0] = params->send_packhead.at(0);
    dataput[1] = data_size;
    *(short*)&dataput[2] = left_motor;
    *(short*)&dataput[4] = right_motor;
    dataput[6] = params->send_packtail.at(0);

    int n = vars->serialport.write(dataput, 7);
    if(n < 0)
    {
        return 0;
    }
	return 1;
}

