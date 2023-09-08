/****************************************************************/
/************** NAME : Eslam Osama Saad *************************/
/************** DATE : 02 / 09 / 2023   *************************/
/************** VERSION : 1.0 			*************************/
/************** SWC : GPIO 				*************************/
/****************************************************************/
#ifndef MGPIO_INTERFACE_H
#define MGPIO_INTERFACE_H

/************************/

/*enum for port*/
typedef enum{
	MGPIO_u8_GPIOA = 0U,
	MGPIO_u8_GPIOB = 1U,
	MGPIO_u8_GPIOC = 2U,
	MGPIO_u8_GPIOD = 3U,
	MGPIO_u8_GPIOE = 4U,
	MGPIO_u8_GPIOH = 5U
}GPIONum_t;
/************************/

/*enum for pin numbers*/
typedef enum{
	MGPIO_u8_PIN0  = 0U ,
	MGPIO_u8_PIN1  = 1U ,
	MGPIO_u8_PIN2  = 2U ,
	MGPIO_u8_PIN3  = 3U ,
	MGPIO_u8_PIN4  = 4U ,
	MGPIO_u8_PIN5  = 5U ,
	MGPIO_u8_PIN6  = 6U ,
	MGPIO_u8_PIN7  = 7U ,
	MGPIO_u8_PIN8  = 8U ,
	MGPIO_u8_PIN9  = 9U ,
	MGPIO_u8_PIN10 = 10U,
	MGPIO_u8_PIN11 = 11U,
	MGPIO_u8_PIN12 = 12U,
	MGPIO_u8_PIN13 = 13U,
	MGPIO_u8_PIN14 = 14U,
	MGPIO_u8_PIN15 = 15U
}PinNum_t;

/************************/

/*Macros for pin mode of operation*/
/*===============================*/

#define MGPIO_MODE_INPUT 		(0b00)
#define MGPIO_MODE_OUTPUT	 	(0b01)
#define MGPIO_MODE_ALTF 		(0b10)
#define MGPIO_MODE_ANALOG 		(0b11)

/*==========================================*/

/* In case of Output mode */
#define MGPIO_OUTPUT_TYPE_PUSH_PULL 		(0U)
#define MGPIO_OUTPUT_TYPE_OPEN_DRAIN	 	(1U)

/*==========================================*/

/* In case of Output mode speed choices */
#define MGPIO_OUTPUT_LOW_SPEED_8MHZ 			(0b00)
#define MGPIO_OUTPUT_MEDIUM_SPEED_10MHZ	 		(0b01)
#define MGPIO_OUTPUT_HIGH_SPEED_100MHZ	 		(0b10)
#define MGPIO_OUTPUT_VERY_HIGH_SPEED_180MHZ		(0b11)

/*==========================================*/

/* In case of Input pull type */
#define MGPIO_INPUT_MODE_NO_PULL	 			(0b00)
#define MGPIO_INPUT_MODE_PULL_UP		 		(0b01)
#define MGPIO_INPUT_MODE_PULL_DOWN		 		(0b10)

/************************/

/*macros for pin value*/
#define MGPIO_u8_HIGH	(1U)
#define MGPIO_u8_LOW	(0U)

/************************/

typedef struct{
	GPIONum_t 	portid;
	PinNum_t 	pinid;
}MGPIO_PinConfig_t;

u8 MGPIO_u8_PinInit			(const MGPIO_PinConfig_t * copy_PstrPinConfig);

u8 MGPIO_u8_SetPinValue		(const MGPIO_PinConfig_t * copy_PstrPinConfig , u8 copy_u8_PinValue);

u8 MGPIO_u8_TogglePinValue	(const MGPIO_PinConfig_t * copy_PstrPinConfig);

/************************/

u8 MGPIO_u8_SetPinMode(const MGPIO_PinConfig_t * copy_PstrPinConfig , u8 copy_u8_PinMode);

u8 MGPIO_u8_SetPinOutPutType(const MGPIO_PinConfig_t * copy_PstrPinConfig , u8 copy_u8_PinOutPutType);

u8 MGPIO_u8_SetPinOutPutSpeed(const MGPIO_PinConfig_t * copy_PstrPinConfig , u8 copy_u8_PinOutPutSpeed);

u8 MGPIO_u8_SetPinInPullType(const MGPIO_PinConfig_t * copy_PstrPinConfig , u8 copy_u8_PinInPullType);

u8 MGPIO_u8_GetPinValue(const MGPIO_PinConfig_t * copy_PstrPinConfig , u8 * copy_pu8_ReturnedPinValue);

u8 MGPIO_u8_SetPinValue(const MGPIO_PinConfig_t * copy_PstrPinConfig , u8 copy_u8_PinValue);

/************************/

#endif
