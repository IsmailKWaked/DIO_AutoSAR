/*
 * DIO_ASR_interface.h
 *
 * Created: 07/03/2024 10:01:20 am
 *  Author: Ismail
 */ 


#ifndef DIO_ASR_INTERFACE_H_
#define DIO_ASR_INTERFACE_H_

#define	DIO_E_PARAM_INVALID_CHANNEL_ID	0x0A
#define	DIO_E_PARAM_INVALID_PORT_ID		0x14
#define	DIO_E_PARAM_INVALID_GROUP		0x1F
#define	DIO_E_PARAM_POINTER				0x20

Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId);

void Dio_WriteChannel (Dio_ChannelType ChannelId,Dio_LevelType Level);

Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId);

void Dio_WritePort (Dio_PortType PortId,Dio_PortLevelType Level);

Dio_PortLevelType Dio_ReadChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr);

void Dio_WriteChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level);


#endif /* DIO_ASR_INTERFACE_H_ */