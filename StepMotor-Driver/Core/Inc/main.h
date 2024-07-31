/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#define FIRMWARE_VERSION 2
#define I2C_ADDRESS 0x27

#define Output_GPIO_PortA GPIOA
#define Output_GPIO_PortB GPIOB
#define Output_GPIO_PortF GPIOF

#define DriveOutput_En_Pin GPIO_PIN_4

#define ResetOutput_X_Pin GPIO_PIN_1
#define ResetOutput_Y_Pin GPIO_PIN_1
#define ResetOutput_Z_Pin GPIO_PIN_6

#define Input_GPIO_PortA GPIOA
#define Input_GPIO_PortF GPIOF

#define ExInput_1_Pin GPIO_PIN_0
#define ExInput_2_Pin GPIO_PIN_1
#define ExInput_3_Pin GPIO_PIN_2
#define ExInput_4_Pin GPIO_PIN_3

#define FaultInput_X_Pin GPIO_PIN_0
#define FaultInput_Y_Pin GPIO_PIN_7
#define FaultInput_Z_Pin GPIO_PIN_5
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
/* USER CODE BEGIN Private defines */
extern __IO uint8_t rgb_state;
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
