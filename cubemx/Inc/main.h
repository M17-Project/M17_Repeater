/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2019 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H__
#define __MAIN_H__

/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define TP7_Pin GPIO_PIN_2
#define TP7_GPIO_Port GPIOE
#define TP8_Pin GPIO_PIN_3
#define TP8_GPIO_Port GPIOE
#define TAMPER_Pin GPIO_PIN_6
#define TAMPER_GPIO_Port GPIOE
#define TAMPER_EXTI_IRQn EXTI9_5_IRQn
#define LCD_CS1_Pin GPIO_PIN_0
#define LCD_CS1_GPIO_Port GPIOC
#define LCD_CS2_Pin GPIO_PIN_1
#define LCD_CS2_GPIO_Port GPIOC
#define LCD_CS3_Pin GPIO_PIN_2
#define LCD_CS3_GPIO_Port GPIOC
#define RX_SCK_Pin GPIO_PIN_5
#define RX_SCK_GPIO_Port GPIOA
#define RX_MISO_Pin GPIO_PIN_6
#define RX_MISO_GPIO_Port GPIOA
#define RX_MOSI_Pin GPIO_PIN_7
#define RX_MOSI_GPIO_Port GPIOA
#define RX_CS_Pin GPIO_PIN_4
#define RX_CS_GPIO_Port GPIOC
#define RX_NIRQ_Pin GPIO_PIN_5
#define RX_NIRQ_GPIO_Port GPIOC
#define RX_NIRQ_EXTI_IRQn EXTI9_5_IRQn
#define RX_SDN_Pin GPIO_PIN_0
#define RX_SDN_GPIO_Port GPIOB
#define LCD_RS_Pin GPIO_PIN_1
#define LCD_RS_GPIO_Port GPIOB
#define LCD_RW_Pin GPIO_PIN_2
#define LCD_RW_GPIO_Port GPIOB
#define LCD_E_Pin GPIO_PIN_7
#define LCD_E_GPIO_Port GPIOE
#define LCD_DB0_Pin GPIO_PIN_8
#define LCD_DB0_GPIO_Port GPIOE
#define LCD_DB1_Pin GPIO_PIN_9
#define LCD_DB1_GPIO_Port GPIOE
#define LCD_DB2_Pin GPIO_PIN_10
#define LCD_DB2_GPIO_Port GPIOE
#define LCD_DB3_Pin GPIO_PIN_11
#define LCD_DB3_GPIO_Port GPIOE
#define LCD_DB4_Pin GPIO_PIN_12
#define LCD_DB4_GPIO_Port GPIOE
#define LCD_DB5_Pin GPIO_PIN_13
#define LCD_DB5_GPIO_Port GPIOE
#define LCD_DB6_Pin GPIO_PIN_14
#define LCD_DB6_GPIO_Port GPIOE
#define LCD_DB7_Pin GPIO_PIN_15
#define LCD_DB7_GPIO_Port GPIOE
#define LCD_RES_Pin GPIO_PIN_10
#define LCD_RES_GPIO_Port GPIOB
#define TX_SDN_Pin GPIO_PIN_12
#define TX_SDN_GPIO_Port GPIOB
#define TX_SCK_Pin GPIO_PIN_13
#define TX_SCK_GPIO_Port GPIOB
#define TX_MISO_Pin GPIO_PIN_14
#define TX_MISO_GPIO_Port GPIOB
#define TX_MOSI_Pin GPIO_PIN_15
#define TX_MOSI_GPIO_Port GPIOB
#define TX_CS_Pin GPIO_PIN_8
#define TX_CS_GPIO_Port GPIOD
#define TX_NIRQ_Pin GPIO_PIN_9
#define TX_NIRQ_GPIO_Port GPIOD
#define TX_NIRQ_EXTI_IRQn EXTI9_5_IRQn
#define LCD_PWM_Pin GPIO_PIN_12
#define LCD_PWM_GPIO_Port GPIOD
#define PWM_FAN_L_Pin GPIO_PIN_13
#define PWM_FAN_L_GPIO_Port GPIOD
#define PWM_FAN_R_Pin GPIO_PIN_14
#define PWM_FAN_R_GPIO_Port GPIOD
#define LED_0_Pin GPIO_PIN_15
#define LED_0_GPIO_Port GPIOA
#define LED_1_Pin GPIO_PIN_10
#define LED_1_GPIO_Port GPIOC
#define LED_2_Pin GPIO_PIN_11
#define LED_2_GPIO_Port GPIOC
#define LED_3_Pin GPIO_PIN_12
#define LED_3_GPIO_Port GPIOC
#define LED_4_Pin GPIO_PIN_0
#define LED_4_GPIO_Port GPIOD
#define LED_5_Pin GPIO_PIN_1
#define LED_5_GPIO_Port GPIOD
#define BTN_3_Pin GPIO_PIN_2
#define BTN_3_GPIO_Port GPIOD
#define BTN_3_EXTI_IRQn EXTI2_IRQn
#define BTN_2_Pin GPIO_PIN_3
#define BTN_2_GPIO_Port GPIOD
#define BTN_2_EXTI_IRQn EXTI3_IRQn
#define BTN_1_Pin GPIO_PIN_4
#define BTN_1_GPIO_Port GPIOD
#define BTN_1_EXTI_IRQn EXTI4_IRQn
#define BTN_0_Pin GPIO_PIN_7
#define BTN_0_GPIO_Port GPIOD
#define BTN_0_EXTI_IRQn EXTI9_5_IRQn
#define ENC_B_Pin GPIO_PIN_4
#define ENC_B_GPIO_Port GPIOB
#define ENC_A_Pin GPIO_PIN_5
#define ENC_A_GPIO_Port GPIOB
#define PTT_Pin GPIO_PIN_0
#define PTT_GPIO_Port GPIOE
#define PTT_EXTI_IRQn EXTI0_IRQn
#define ENC_BTN_Pin GPIO_PIN_1
#define ENC_BTN_GPIO_Port GPIOE
#define ENC_BTN_EXTI_IRQn EXTI1_IRQn

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the 
  *        HAL drivers code
  */
/* #define USE_FULL_ASSERT    1U */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
 extern "C" {
#endif
void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
