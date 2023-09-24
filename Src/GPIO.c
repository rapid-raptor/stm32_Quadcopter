/*
 * GPIO.c
 *
 *  Created on: Dec 28, 2021
 *      Author: Pradeep
 */


#include "GPIO.h"

void GPIO_ClockControl(GPIO_eClkPos_t GPIOxClk, uint8_t EnOrDi)
{
	if(EnOrDi == ENABLE)
	{
		RCC->AHB1ENR |= (1 << GPIOxClk);
	}
	else if(EnOrDi == DISABLE)
	{
		RCC->AHB1ENR &= ~(1 << GPIOxClk);
	}
}

void GPIO_Init(GPIO_RegDef_t* GPIOx, GPIO_StructInit_t* GPIO_Init)
{
	uint16_t u16LocPinNumber = GPIO_Init->GPIO_PinNumber;

	/*	Setting Pin mode */
	GPIOx->MODER |= (GPIO_Init->GPIO_PinMode) << (u16LocPinNumber * 2) ;

	/* Setting output mode */
	if( (GPIO_Init->GPIO_PinMode) == GPIO_ePinMode_Output)
	{
		GPIOx->OTYPER |= (GPIO_Init->GPIO_PinOutType) << u16LocPinNumber ;
	}

	/* Setting Pull up or Pull down	*/
	GPIOx->PUPDR |= (GPIO_Init->GPIO_PinPuPdControl) << (u16LocPinNumber * 2);

	/* Setting output speed	*/
	GPIOx->OSPEEDR |= GPIO_Init->GPIO_PinOSpeed << (u16LocPinNumber * 2);

	/* Setting Alternate function mode */
	GPIOx->AFR[u16LocPinNumber/8] |= (GPIO_Init->GPIO_PinAltFuncMode) << ((u16LocPinNumber % 8) * 4);
}

uint8_t GPIO_ReadPin(GPIO_RegDef_t* GPIOx, uint16_t pinnumber)
{
	return ((GPIOx->IDR >> pinnumber) & 1);
}

void GPIO_WritePin(GPIO_RegDef_t* GPIOx, uint16_t pinnumber, uint8_t data)
{
	if(data == HIGH)
	GPIOx->ODR |= (data & 1) << pinnumber ;

	else if(data == LOW)
	GPIOx->ODR &=  ~(1 << pinnumber) ;
}

uint16_t GPIO_ReadPort(GPIO_RegDef_t* GPIOx)
{
	return (GPIOx->IDR);
}

void GPIO_WritePort(GPIO_RegDef_t* GPIOx, uint16_t data)
{
	GPIOx->ODR = data;
}
