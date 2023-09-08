/****************************************************************/
/************** NAME : Eslam Osama Saad *************************/
/************** DATE : 01 / 09 / 2023   *************************/
/************** VERSION : 1.0 			*************************/
/************** SWC : MRCC      		*************************/
/****************************************************************/

#ifndef MRCC_CONFIG_H
#define MRCC_CONFIG_H

/*options of RCC CLK SOURCE*/
/*
 * 1- MRCC_u8_HSI
 * 2- MRCC_U8_HSE
 * 3- MRCC_u8_PLL
 */
#define MRCC_u8_CLK_SYS  MRCC_u8_HSI

/*options of HSE CLK SOURCE*/
/*
 * 1- MRCC_U8_HSE_CRY
 * 2- MRCC_u8_HSE_RC
 */
 
#define MRCC_U8_HSE_SRC MRCC_u8_HSE_RC

/*options of PLL CLK SOURCE*/
/*
 * 1- MRCC_U8_PLL_HSI
 * 2- MRCC_u8_PLL_HSE
 */
 
#define MRCC_U8_PLL_SRC MRCC_U8_PLL_HSI

#endif
