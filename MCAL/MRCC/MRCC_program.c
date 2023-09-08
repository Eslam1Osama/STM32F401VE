/****************************************************************/
/************** NAME : Eslam Osama Saad *************************/
/************** DATE : 01 / 09 / 2023   *************************/
/************** VERSION : 1.0 			*************************/
/************** SWC : MRCC       		*************************/
/****************************************************************/
/*1 - include which state in LIB layer*/
#include"LSTD_TYPES.h"
#include"LBIT_MATH.h"
#include"LSTM32F103C8.h"

/*2 - include which state in MCAL layer for RCC*/
#include"MRCC_interface.h"
#include"MRCC_config.h"
#include"MRCC_private.h"

u8 MRCC_u8_InitSysClk(void)
{
	/*always do not forget to return error states*/
	u8 local_u8ErrorState = LSTD_TYPES_OK;
	
	/* 
	enable the clk to be selected 
    select clk source 1- HSI , 2- HSE , 3- PLL 
	*/
	
/************************** HSI **************************/	
#if(MRCC_u8_CLK_SYS == MRCC_u8_HSI)
	
	/*enable HSI*/
	SET_BIT(MRCC->CR , 0U);
	
	/* while(GET_BIT(MRCC->CR , 1U) == 0); */
	
	/*Input System CLK*/
	CLR_BIT(MRCC->CFGR , 0U);
	CLR_BIT(MRCC->CFGR , 1U);
	
/************************** HSE **************************/
#elif(MRCC_u8_CLK_SYS == MRCC_u8_HSE)
	
	/*enable HSE*/
	SET_BIT(MRCC->CR , 16U);
	
	/* while(GET_BIT(MRCC->CR , 17U) == 0); */
	
	/************************** CRYSTAL **************************/
	#if(MRCC_U8_HSE_SRC == MRCC_U8_HSE_CRY)
		/* DISABLE BYPASS */
		CLR_BIT(MRCC->CLR_BIT , 18U);
		
	/************************** RC **************************/
	#elif(MRCC_U8_HSE_SRC == MRCC_u8_HSE_RC)
		/* ENABLE BYPASS */
		SET_BIT(MRCC->CLR_BIT , 18U);
		
	/***********************************************************/	
	#else
		#error "Wrong choice"
	#endif
	
	/*Input System CLK*/
	SET_BIT(MRCC->CFGR , 0U);
	CLR_BIT(MRCC->CFGR , 1U);
	
/************************** PLL **************************/
#elif(MRCC_u8_CLK_SYS == MRCC_u8_PLL)
	
	/************************** HSE as source of PLL **************************/
	#if(MRCC_U8_PLL_SRC == MRCC_U8_PLL_HSE)
		/*enable HSE*/
		SET_BIT(MRCC->CR , 16U);
		
		/* while(GET_BIT(MRCC->CR , 17U) == 0); */
		
		/*Select HSE as source of PLL*/
		SET_BIT(MRCC->PLLCFGR , 22U);
		
	/************************** HSI as source of PLL **************************/
	#elif(MRCC_U8_PLL_SRC == MRCC_U8_PLL_HSI)
		/*enable HSI*/
		SET_BIT(MRCC->CR , 0U);
		
		/* while(GET_BIT(MRCC->CR , 1U) == 0); */
		
		/*Select HSI as source of PLL*/
		CLR_BIT(MRCC->PLLCFGR , 22U);
		
	/***********************************************************/	
	#else
		#error "Wrong choice"
	#endif
	
	/*enable PLL*/
	SET_BIT(MRCC->CR , 24U);
	
	/* while(GET_BIT(MRCC->CR , 25U) == 0); */
	
	/*Input System CLK*/
	CLR_BIT(MRCC->CFGR , 0U);
	SET_BIT(MRCC->CFGR , 1U);
/***********************************************************/

#else
	#error "Wrong choice"
#endif

	return local_u8ErrorState;
}

/**********************************************************************************************/

u8 MRCC_u8_EnablePeripheralClk(BusName_t Bus_Name , u8 copy_u8_PerpheralNum)
{
	/*always do not forget to return error states*/
	u8 local_u8ErrorState = LSTD_TYPES_OK;

	if(copy_u8_PerpheralNum <= 31)
	{
		switch(Bus_Name)
		{
			case AHB1: SET_BIT(MRCC->AHB1ENR , copy_u8_PerpheralNum );		break;
			case AHB2: SET_BIT(MRCC->AHB2ENR , copy_u8_PerpheralNum );		break;
			case APB1: SET_BIT(MRCC->APB1ENR , copy_u8_PerpheralNum );		break;
			case APB2: SET_BIT(MRCC->APB2ENR , copy_u8_PerpheralNum );		break;
			default	 : local_u8ErrorState = LSTD_TYPES_NOK;					break;
		}
	}
	else
		local_u8ErrorState = LSTD_TYPES_NOK;
	
	return local_u8ErrorState;
}

/**********************************************************************************************/

u8 MRCC_u8_DisablePeripheralClk(BusName_t Bus_Name , u8 copy_u8_PerpheralNum)
{
	/*always do not forget to return error states*/
	u8 local_u8ErrorState = LSTD_TYPES_OK;

	if(copy_u8_PerpheralNum <= 31)
	{
		switch(Bus_Name)
		{
			case AHB1: CLR_BIT(MRCC->AHB1ENR , copy_u8_PerpheralNum );		break;
			case AHB2: CLR_BIT(MRCC->AHB2ENR , copy_u8_PerpheralNum );		break;
			case APB1: CLR_BIT(MRCC->APB1ENR , copy_u8_PerpheralNum );		break;
			case APB2: CLR_BIT(MRCC->APB2ENR , copy_u8_PerpheralNum );		break;
			default	 : local_u8ErrorState = LSTD_TYPES_NOK;					break;
		}
	}
	else
		local_u8ErrorState = LSTD_TYPES_NOK;
	
	return local_u8ErrorState;
}

/**********************************************************************************************/

u8 MRCC_u8_EnableSecuritySystem(void)
{
	u8 local_u8ErrorState = LSTD_TYPES_OK;
	
	SET_BIT(MRCC->CR , CSSON);
	
	return local_u8ErrorState;
}

/**********************************************************************************************/

u8 MRCC_u8_DisableSecuritySystem(void)
{
	u8 local_u8ErrorState = LSTD_TYPES_OK;
	
	CLR_BIT(MRCC->CR , CSSON);
	
	return local_u8ErrorState;
}

/**********************************************************************************************/
