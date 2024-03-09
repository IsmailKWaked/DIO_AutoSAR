/*
 * DIO_ASR_program.c
 *
 * Created: 07/03/2024 10:02:20 am
 *  Author: Ismail
 */ 

#include "StdTypes_ASR.h"
#include "BIT_MATH.h"
#include "DIO_ASR_register.h"
#include "DIO_ASR_interface.h"
#include "DIO_ASR_private.h"
#include "DIO_ASR_config.h"

Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)
{
	DIO_LevelType ChannelReading=DIO_E_PARAM_INVALID_CHANNEL_ID;
	if(ChannelId<CHANNELS_ID_LIMIT)
	{
		if(ChannelId<8)
		{
			if(GET_BIT(DIO_REG->DDRA,ChannelId%8)==0)
				ChannelReading=GET_BIT(DIO_REG->PINA,ChannelId%8);
			else if(GET_BIT(DIO_REG->DDRA,ChannelId%8)==1)
				ChannelReading=GET_BIT(DIO_REG->PORTA,ChannelId%8);
		}
		else if(ChannelId>7 && ChannelId<16)
		{
			if(GET_BIT(DIO_REG->DDRB,ChannelId%8)==0)
				ChannelReading=GET_BIT(DIO_REG->PINB,ChannelId%8);
			else if(GET_BIT(DIO_REG->DDRB,ChannelId%8)==1)
				ChannelReading=GET_BIT(DIO_REG->PORTB,ChannelId%8);
		}
		else if(ChannelId>15 && ChannelId<24)
		{
			if(GET_BIT(DIO_REG->DDRC,ChannelId%8)==0)
				ChannelReading=GET_BIT(DIO_REG->PINC,ChannelId%8);
			else if(GET_BIT(DIO_REG->DDRC,ChannelId%8)==1)
				ChannelReading=GET_BIT(DIO_REG->PORTC,ChannelId%8);	
		}
		else if(ChannelId>23 && ChannelId<32)
		{
			if(GET_BIT(DIO_REG->DDRD,ChannelId%8)==0)
				ChannelReading=GET_BIT(DIO_REG->PIND,ChannelId%8);
			else if(GET_BIT(DIO_REG->DDRD,ChannelId%8)==1)
				ChannelReading=GET_BIT(DIO_REG->PORTD,ChannelId%8);
		}
	}
	return ChannelReading;
}


void Dio_WriteChannel (Dio_ChannelType ChannelId,Dio_LevelType Level)
{
	if(ChannelId<CHANNELS_ID_LIMIT)
	{
		if(ChannelId<8 && GET_BIT(DIO_REG->DDRA,ChannelId%8)==1)
		{
			switch(Level)
			{
				case STD_LOW:
				CLR_BIT(DIO_REG->PORTA,ChannelId%8);
				break;
				case STD_HIGH:
				SET_BIT(DIO_REG->PORTA,ChannelId%8);
				break;
			}
		}
		
		else if(ChannelId<16 && ChannelId>7 && GET_BIT(DIO_REG->DDRB,ChannelId%8)==1)
		{
			switch(Level)
			{
				case STD_LOW:
				CLR_BIT(DIO_REG->PORTB,ChannelId%8);
				break;
				case STD_HIGH:
				SET_BIT(DIO_REG->PORTB,ChannelId%8);
				break;
			}
		}
		
		else if(ChannelId<24 && ChannelId>15 && GET_BIT(DIO_REG->DDRC,ChannelId%8)==1)
		{
			switch(Level)
			{
				case STD_LOW:
				CLR_BIT(DIO_REG->PORTC,ChannelId%8);
				break;
				case STD_HIGH:
				SET_BIT(DIO_REG->PORTC,ChannelId%8);
				break;
			}
		}
		
		else if(ChannelId<32 && ChannelId>23 && GET_BIT(DIO_REG->DDRD,ChannelId%8)==1)
		{
			switch(Level)
			{
				case STD_LOW:
				CLR_BIT(DIO_REG->PORTD,ChannelId%8);
				break;
				case STD_HIGH:
				SET_BIT(DIO_REG->PORTD,ChannelId%8);
				break;
			}
		}
	}
}


Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId)
{
	Dio_PortLevelType PortReading=DIO_E_PARAM_INVALID_PORT_ID;
	
	if(PortId<PORT_ID_LIMIT)
	{
		switch(PortId)
		{
			case 0:
			PortReading=DIO_REG->PORTA;
			break;
			
			case 1:
			PortReading=DIO_REG->PORTB;
			break;
			
			case 2:
			PortReading=DIO_REG->PORTC;
			break;
			
			case 3:
			PortReading=DIO_REG->PORTD;
			break;
		}
	}
	return PortReading;
}

void Dio_WritePort (Dio_PortType PortId,Dio_PortLevelType Level)
{
	if(PortId<PORT_ID_LIMIT && sizeof(Level)<=PORT_WIDTH)
	{
		switch(PortId)
		{
			case 0:
			for(u8 i=0;i<8;i++)
			{
				if(GET_BIT(DIO_REG->DDRA,i)==1)		//pin is output
				{
					DIO_REG->PORTA|=GET_BIT(Level,i)<<i;
				}
			}
			break;
			
			case 1:
			for(u8 i=0;i<8;i++)
			{
				if(GET_BIT(DIO_REG->DDRB,i)==1)		//pin is output
				{
					DIO_REG->PORTB|=GET_BIT(Level,i)<<i;
				}
			}
			break;
			
			case 2:
			for(u8 i=0;i<8;i++)
			{
				if(GET_BIT(DIO_REG->DDRC,i)==1)		//pin is output
				{
					DIO_REG->PORTC|=GET_BIT(Level,i)<<i;
				}
			}
			break;
			
			case 3:
			for(u8 i=0;i<8;i++)
			{
				if(GET_BIT(DIO_REG->DDRD,i)==1)		//pin is output
				{
					DIO_REG->PORTD|=GET_BIT(Level,i)<<i;
				}
			}
			break;
		}
	}
}

Dio_PortLevelType Dio_ReadChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr)
{
	Dio_PortLevelType ChannelGrp_Reading=DIO_E_PARAM_INVALID_GROUP;
	if(ChannelGroupIdPtr->port <PORT_ID_LIMIT && ChannelGroupIdPtr!=NULL)
	{
		switch(ChannelGroupIdPtr->port)
		{
			case 0:
			ChannelGrp_Reading&=0x00;
			ChannelGrp_Reading=((DIO_REG->PINA)>>(ChannelGroupIdPtr->offset))&(ChannelGroupIdPtr->mask);
			break;
			
			case 1:
			ChannelGrp_Reading&=0x00;
			ChannelGrp_Reading=((DIO_REG->PINB)>>(ChannelGroupIdPtr->offset))&(ChannelGroupIdPtr->mask);
			break;
			
			case 2:
			ChannelGrp_Reading&=0x00;
			ChannelGrp_Reading=((DIO_REG->PINC)>>(ChannelGroupIdPtr->offset))&(ChannelGroupIdPtr->mask);
			break;
			
			case 3:
			ChannelGrp_Reading&=0x00;
			ChannelGrp_Reading=((DIO_REG->PIND)>>(ChannelGroupIdPtr->offset))&(ChannelGroupIdPtr->mask);
			break;
		}
	}
	else if(ChannelGroupIdPtr->port >=PORT_ID_LIMIT)
	{
		ChannelGrp_Reading=DIO_E_PARAM_INVALID_PORT_ID'
	}
	else if (ChannelGroupIdPtr==NULL)
	{
		ChannelGrp_Reading=DIO_E_PARAM_POINTER;
	}
	return ChannelGrp_Reading;
}


void Dio_WriteChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level)
{
	u8 temp_offset=0;
	
	if( ((ChannelGroupIdPtr->port) < PORT_ID_LIMIT) && (ChannelGroupIdPtr!=NULL) )
	{
		switch(ChannelGroupIdPtr->port)
		{
			case 0:
			temp_offset=Level<<(ChannelGroupIdPtr->offset);
			temp_offset=temp_offset & (ChannelGroupIdPtr->mask);
			DIO_REG->PORTA|=temp_offset;
			break;
			
			case 1:
			temp_offset=Level<<(ChannelGroupIdPtr->offset);
			temp_offset=temp_offset & (ChannelGroupIdPtr->mask);
			DIO_REG->PORTB|=temp_offset;
			break;
			
			case 2:
			temp_offset=Level<<(ChannelGroupIdPtr->offset);
			temp_offset=temp_offset & (ChannelGroupIdPtr->mask);
			DIO_REG->PORTC|=temp_offset;
			break;
			
			case 3:
			temp_offset=Level<<(ChannelGroupIdPtr->offset);
			temp_offset=temp_offset & (ChannelGroupIdPtr->mask);
			DIO_REG->PORTD|=temp_offset;
			break;
			
		}
	}
}