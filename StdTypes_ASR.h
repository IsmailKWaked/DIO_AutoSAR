
#ifndef Std_Types_ASR_H
#define Std_Types_ASR_H

#ifndef NULL
#define NULL ((void*)0)
#endif

typedef unsigned char u8 ; 
typedef unsigned  short int u16 ; 
typedef unsigned long int u32 ;
typedef signed char s8 ; 
typedef signed short int s16 ; 
typedef signed long  int s32 ;
typedef float f32 ; 
typedef double  f64 ;


//AUtoSAR DIO typedefs

typedef DIO_ChannelType	u8;
typedef DIO_PortType	u8;
typedef struct
{
	u8 mask;
	u8 offset;
	DIO_PortType port;
}Dio_ChannelGroupType;

typedef enum
{
	STD_LOW=0,
	STD_HIGH=1,
}Dio_LevelType;

typedef	Dio_PortLevelType	u8;



//typedef for constants

typedef const unsigned char ku8 ;
typedef const unsigned  short int ku16 ;
typedef const unsigned long ku32 ;
typedef const signed char ks8 ;
typedef const signed short int ks16 ;
typedef const signed long ks32 ;
typedef const float kf32 ;
typedef const double  kf64 ;

typedef enum
{
	false,
	true
}Bool;




#endif
