/****************************************************************/
/************** NAME : Eslam Osama Saad *************************/
/************** DATE : 01 / 09 / 2023   *************************/
/************** VERSION : 1.0 			*************************/
/************** SWC : STM32F401XX 		*************************/
/****************************************************************/

#ifndef LSTM32F103C8_H
#define LSTM32F103C8_H

/*****************************************************************/
/************** MRCC REGISTERS DEFINATION ************************/
/*****************************************************************/

#define MRCC_u32_BASE_ADRRESS		0X40023800U   /* BASE ADDRESS OF RCC PERPHERAL */

/* 
NOTE THAT ->Aim of volatile is to stop optimizer from doing any optimization 
            on REGs difined in MRCC_u32_RegDef_t stuct 
*/

typedef struct{
	volatile u32 CR;
	volatile u32 PLLCFGR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 AHB1RSTR;
	volatile u32 AHB2RSTR;
	volatile u32 __________RESERVED1[2];
	volatile u32 APB1RSTR;
	volatile u32 APB2RSTR;
	volatile u32 __________RESERVED2[2];
	volatile u32 AHB1ENR;
	volatile u32 AHB2ENR;
	volatile u32 __________RESERVED3[2];
	volatile u32 APB1ENR;
	volatile u32 APB2ENR;
	volatile u32 __________RESERVED4[2];
	volatile u32 AHB1LPENR;
	volatile u32 AHB2LPENR;
	volatile u32 __________RESERVED5[2];
	volatile u32 APB1LPENR;
	volatile u32 APB2LPENR;
	volatile u32 __________RESERVED6[2];
	volatile u32 BDCR;
	volatile u32 CSR;
	volatile u32 __________RESERVED7[2];
	volatile u32 SSCGR;
	volatile u32 PLLI2SCFGR;
	volatile u32 DCKCFGR;
}MRCC_u32_RegDef_t;//_t means type

#define MRCC			( ( MRCC_u32_RegDef_t* ) MRCC_u32_BASE_ADRRESS )

/*****************************************************************/
/************** MGPIO REGISTERS DEFINATION ***********************/
/*****************************************************************/

#define GPIO_u32_GPIOA_BASE_ADRRESS		0X40020000U
#define GPIO_u32_GPIOB_BASE_ADRRESS		0X40020400U
#define GPIO_u32_GPIOC_BASE_ADRRESS		0X40020800U
#define GPIO_u32_GPIOD_BASE_ADRRESS		0X40020C00U
#define GPIO_u32_GPIOE_BASE_ADRRESS		0X40021000U
#define GPIO_u32_GPIOH_BASE_ADRRESS		0X40021C00U

typedef struct{
	volatile u32 MODER;
	volatile u32 OTYPER;
	volatile u32 OSPEEDR;
	volatile u32 PUPDR;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 LCKR;
	volatile u32 AFRL;
	volatile u32 AFRH;
}GPIO_u32_RegDef_t;//_t means type

#define GPIOA			( ( GPIO_u32_RegDef_t* ) GPIO_u32_GPIOA_BASE_ADRRESS )
#define GPIOB		    ( ( GPIO_u32_RegDef_t* ) GPIO_u32_GPIOB_BASE_ADRRESS )
#define GPIOC			( ( GPIO_u32_RegDef_t* ) GPIO_u32_GPIOC_BASE_ADRRESS )
#define GPIOD			( ( GPIO_u32_RegDef_t* ) GPIO_u32_GPIOD_BASE_ADRRESS )
#define GPIOE		    ( ( GPIO_u32_RegDef_t* ) GPIO_u32_GPIOE_BASE_ADRRESS )
#define GPIOH			( ( GPIO_u32_RegDef_t* ) GPIO_u32_GPIOH_BASE_ADRRESS )

/****************************************************************/
#endif
