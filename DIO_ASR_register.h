/*
 * DIO_ASR_register.h
 *
 * Created: 07/03/2024 10:01:43 am
 *  Author: Ismail
 */ 


#ifndef DIO_ASR_REGISTER_H_
#define DIO_ASR_REGISTER_H_


typedef struct
{
/*PORT D registers*/	
	u8 PIND;
	u8 DDRD;
	u8 PORTD;
	
/*PORT C registers*/
	u8 PINC;
	u8 DDRC;
	u8 PORTC;
	
/*PORT B registers*/
	u8 PINB;
	u8 DDRB;
	u8 PORTB;
   
/*PORT A registers*/
	u8 PINA;
	u8 DDRA;
	u8 PORTA;
}DIO;

#define DIO_REG		((volatile DIO*)(0x30))

#endif /* DIO_ASR_REGISTER_H_ */