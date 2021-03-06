/***********************************************************************************
  Filename:     awsn_rf.h

  Description:  AWSN(Agriculture Wireless Sensor Network) RF 库头文件

***********************************************************************************/

#ifndef AWSN_RF_H
#define AWSN_RF_H
/*********************************************头文件包含******************************************/
#include "hal_types.h"
#include "hal_defs.h"
#include "delay.h"

/************************************************常量定义****************************************/
#define HAL_INFOP_IEEE_OSET 0xC


typedef enum {
  AWSN_ACK,
  AWSN_ENTER,
  AWSN_ADD,
  AWSN_SYN,
  AWSN_DATA,
  AWSN_NONE
} awsnRfRxState_t;


typedef struct {
  uint8 macAddr[8];   //mac地址
  uint16 myAddr;      //节点地址
  uint16 panId;       //节点Pan Id
  uint8 channel;      //RF 通道（11-26之间）
  uint8 txPower;      //发射功率
  uint8 cycleTime;    //通信周期
}awsnRfCfg_t;


/************************************************函数声明****************************************/
uint8 awsnRfInit(awsnRfCfg_t* pRfConfig);                               //RF初始化
uint8 awsnRfSensorSendPacket(uint16 destAddr,uint8 *pPayload,uint8 length);   //RF发送数据
uint8 awsnRfGatewaySendPacket(uint16 destAddr,uint8 *pPayload,uint8 length);
uint8 awsnRfPacketIsReady(void);                                        //接收数据是否完成
uint8 awsnRfReceive(uint8 *pRxData,uint8 len, int8* pRssi);            //复制负载内容到buffer中
void awsnRfReceiveOff(void);
void awsnRfReceiveOn(void);
int8 awsnRfGetTxRssi(void);
uint8 awsnRfGetTxLqi(void);
void awsnRfSleep(uint8 sleepTime);
uint8 awsnRfGetTxSrcAddr(void);
void awsnRfGetMacAddr(void);

#endif
