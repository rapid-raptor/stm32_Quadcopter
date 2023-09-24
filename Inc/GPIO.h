/*
 * GPIO.h
 *
 *  Created on: Dec 28, 2021
 *      Author: Pradeep
 */

#ifndef GPIO_H_
#define GPIO_H_

/**********Standard Includes***********/
#include<stdint.h>

/**********User Includes************/
#include <Stm32F401xx.h>

/***********User Types**************/
typedef struct {
//	GPIO_RegDef_t* GPIO_Port;
	uint16_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinOutType;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOSpeed;
	uint16_t GPIO_PinAltFuncMode;
}GPIO_StructInit_t;

/* Possible values for GPIO_StructInit_t */
typedef enum {
	GPIO_ePinMode_Input,
	GPIO_ePinMode_Output,
	GPIO_ePinMode_AltFun,
	GPIO_ePinMode_Analog
}GPIO_ePinMode_t;

typedef enum {
	GPIO_eOutType_PushPull,
	GPIO_eOutType_Opendrain
}GPIO_ePinOutType_t;

typedef enum {
	GPIO_ePuPdMode_NoPuPd,
	GPIO_ePuPdMode_PullUp,
	GPIO_ePuPdMode_PullDown
}GPIO_ePinPuPdControl_t;

typedef enum {
	GPIO_ePinOSpeed_Low,
	GPIO_ePinOSpeed_Medium,
	GPIO_ePinOSpeed_High,
	GPIO_ePinOSpeed_VeryHigh
}GPIO_ePinOSpeed_t;

typedef enum {
	GPIO_eCLKPOS_A,
	GPIO_eCLKPOS_B,
	GPIO_eCLKPOS_C,
	GPIO_eCLKPOS_D,
	GPIO_eCLKPOS_E,
	GPIO_eCLKPOS_H=7
}GPIO_eClkPos_t;

/**********Public Function Declarations**********/
void GPIO_ClockControl(GPIO_eClkPos_t GPIOxClk, uint8_t EnOrDi);
void GPIO_Init(GPIO_RegDef_t* GPIOx, GPIO_StructInit_t* GPIO_Init);
uint8_t GPIO_ReadPin(GPIO_RegDef_t* GPIOx, uint16_t pinnumber);
void GPIO_WritePin(GPIO_RegDef_t* GPIOx, uint16_t pinnumber, uint8_t data);
uint16_t GPIO_ReadPort(GPIO_RegDef_t* GPIOx);
void GPIO_WritePort(GPIO_RegDef_t* GPIOx, uint16_t data);

#endif /* GPIO_H_ */
