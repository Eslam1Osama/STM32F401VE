/****************************************************************/
/************** NAME : Eslam Osama Saad *************************/
/************** DATE : 01 / 09 / 2023   *************************/
/************** VERSION : 1.0 			*************************/
/************** SWC : MRCC      		*************************/
/****************************************************************/

#ifndef MRCC_INTERFACE_H
#define MRCC_INTERFACE_H

typedef enum{
	
	AHB1 = 0,
	AHB2	,
	APB1	,
	APB2
	
}BusName_t;
/*****************************???????????????????????????***********************/

/*************** RCC AHB1 CLK ENABLE ***************/

#define _PERIPHERAL_EN_GPIOA	(0U)
#define _PERIPHERAL_EN_GPIOA	(0U)
#define _PERIPHERAL_EN_GPIOA	(0U)
#define _PERIPHERAL_EN_GPIOA	(0U)

/**************************************************/

/*************** RCC AHB2 CLK ENABLE ***************/

#define _PERIPHERAL_EN_GPIOA	(0U)
#define _PERIPHERAL_EN_GPIOA	(0U)
#define _PERIPHERAL_EN_GPIOA	(0U)
#define _PERIPHERAL_EN_GPIOA	(0U)

/**************************************************/

/*************** RCC APB1 CLK ENABLE ***************/

#define _PERIPHERAL_EN_GPIOA	(0U)
#define _PERIPHERAL_EN_GPIOA	(0U)
#define _PERIPHERAL_EN_GPIOA	(0U)
#define _PERIPHERAL_EN_GPIOA	(0U)

/**************************************************/

/*************** RCC APB2 CLK ENABLE ***************/

#define _PERIPHERAL_EN_GPIOA	(0U)
#define _PERIPHERAL_EN_GPIOA	(0U)
#define _PERIPHERAL_EN_GPIOA	(0U)
#define _PERIPHERAL_EN_GPIOA	(0U)

/**************************************************/

/*****************************???????????????????????????***********************/
#define CSSON	(19U)

/**************************************************/

u8 MRCC_u8_InitSysClk(void);

u8 MRCC_u8_EnablePeripheralClk(BusName_t Bus_Name , u8 copy_u8_PerpheralNum);

u8 MRCC_u8_DisablePeripheralClk(BusName_t Bus_Name , u8 copy_u8_PerpheralNum);

u8 MRCC_u8_EnableSecuritySystem(void);

u8 MRCC_u8_DisableSecuritySystem(void);

#endif