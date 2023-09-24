/*
 * GPIO_Reg.h
 *
 *  Created on: Dec 28, 2021
 *      Author: Pradeep
 */

#ifndef STM32F401xx_REG_H_
#define STM32F401xx_REG_H_

#define __vo volatile

typedef struct {
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];
}GPIO_RegDef_t;

typedef struct
{
  __vo uint32_t CR;            /*	Address offset: 0x00 */
  __vo uint32_t PLLCFGR;       /*	Address offset: 0x04 */
  __vo uint32_t CFGR;          /*	Address offset: 0x08 */
  __vo uint32_t CIR;           /*	Address offset: 0x0C */
  __vo uint32_t AHB1RSTR;      /*	Address offset: 0x10 */
  __vo uint32_t AHB2RSTR;      /*	Address offset: 0x14 */
  __vo uint32_t AHB3RSTR;      /*	Address offset: 0x18 */
  uint32_t      RESERVED0;     /*                        */
  __vo uint32_t APB1RSTR;      /*	Address offset: 0x20 */
  __vo uint32_t APB2RSTR;      /*	Address offset: 0x24 */
  uint32_t      RESERVED1[2];  /*                        */
  __vo uint32_t AHB1ENR;       /*	Address offset: 0x30 */
  __vo uint32_t AHB2ENR;       /*	Address offset: 0x34 */
  __vo uint32_t AHB3ENR;       /*	Address offset: 0x38 */
  uint32_t      RESERVED2;     /*                        */
  __vo uint32_t APB1ENR;       /*	Address offset: 0x40 */
  __vo uint32_t APB2ENR;       /*	Address offset: 0x44 */
  uint32_t      RESERVED3[2];  /*                        */
  __vo uint32_t AHB1LPENR;     /*	Address offset: 0x50 */
  __vo uint32_t AHB2LPENR;     /*	Address offset: 0x54 */
  __vo uint32_t AHB3LPENR;     /*	Address offset: 0x58 */
  uint32_t      RESERVED4;     /*                        */
  __vo uint32_t APB1LPENR;     /*	Address offset: 0x60 */
  __vo uint32_t APB2LPENR;     /*	Address offset: 0x64 */
  uint32_t      RESERVED5[2];  /*                        */
  __vo uint32_t BDCR;          /*	Address offset: 0x70 */
  __vo uint32_t CSR;           /*	Address offset: 0x74 */
  uint32_t      RESERVED6[2];  /*                        */
  __vo uint32_t SSCGR;         /*	Address offset: 0x80 */
  __vo uint32_t PLLI2SCFGR;    /*	Address offset: 0x84 */
  __vo uint32_t PLLSAICFGR;    /*	Address offset: 0x88 */
  __vo uint32_t DCKCFGR;       /*	Address offset: 0x8C */
  __vo uint32_t CKGATENR;      /*	Address offset: 0x90 */
  __vo uint32_t DCKCFGR2;      /*	Address offset: 0x94 */

} RCC_RegDef_t;



#define GPIOA	((GPIO_RegDef_t*)0x40020000)
#define GPIOB	((GPIO_RegDef_t*)0x40020400)
#define GPIOC	((GPIO_RegDef_t*)0x40020800)
#define GPIOD	((GPIO_RegDef_t*)0x40020C00)
#define GPIOE	((GPIO_RegDef_t*)0x40021000)
#define GPIOH	((GPIO_RegDef_t*)0x40021C00)

#define RCC		((RCC_RegDef_t*)0x40023800)


/** General Macros  **/
#define ENABLE 	1U
#define DISABLE 0U
#define HIGH	1U
#define LOW		0U

#endif /* STM32F401xx_REG_H_ */
