
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f7xx_hal.h"

/* USER CODE BEGIN Includes */
#include "font.h"

#include "radio_config.h"

#define	FRAMESIZE		160*2					//20+20=40ms frame
#define	RAW_BYTES		8*2
#define	CRC_LEN			2
#define	ENC_LEN			(RAW_BYTES)*2
#define	PLOAD_LEN		97

#define	DC_OFFSET		2040					//input signal DC offset

#define	MAX_TX_POWER	0x7F					//+20dBm
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

DAC_HandleTypeDef hdac;

SPI_HandleTypeDef hspi1;
SPI_HandleTypeDef hspi2;

TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
//Si 446x RELATED
const uint8_t config[] = RADIO_CONFIGURATION_DATA_ARRAY;	//config
volatile uint8_t RX_ints[8];								//interrupts
volatile uint8_t r_initd=0;									//RX initialized?

volatile uint8_t rcv_buff[PLOAD_LEN];						//Si RX buffer

//main
volatile uint32_t rx_freq=439575000;						//RX frequency in Hz
volatile uint32_t tx_freq=439575000;						//TX

volatile uint32_t last_id_from=0;
volatile uint32_t last_id_to=0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_DAC_Init(void);
static void MX_SPI2_Init(void);
static void MX_TIM4_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_SPI1_Init(void);
static void MX_TIM3_Init(void);

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);
                                

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/
//------------------------------SPI1 - Si4463 - RX------------------------------
void RX_WaitForCTS(void)
{
	uint8_t cts[1]={0x00};
	const uint8_t dta[1]={0x44};

	do
	{
		HAL_GPIO_WritePin(RX_CS_GPIO_Port, RX_CS_Pin, 0);
		HAL_SPI_Transmit(&hspi1, dta, 1, 100);
		HAL_SPI_Receive(&hspi1, cts, 1, 100);
		//if(cts[0]!=0xFF)
			HAL_GPIO_WritePin(RX_CS_GPIO_Port, RX_CS_Pin, 1);
	}while(cts[0]!=0xFF);
}

void RX_Send(uint8_t *data, uint8_t len)
{
	RX_WaitForCTS();
	HAL_GPIO_WritePin(RX_CS_GPIO_Port, RX_CS_Pin, 0);
	HAL_SPI_Transmit(&hspi1, data, len, 100);
	HAL_GPIO_WritePin(RX_CS_GPIO_Port, RX_CS_Pin, 1);
}

void RX_GetResponse(uint8_t len, uint8_t *data)
{
	uint8_t cts[1]={0x00};
	uint8_t dta[1]={0x44};

	while(cts[0]!=0xFF)
	{
		HAL_GPIO_WritePin(RX_CS_GPIO_Port, RX_CS_Pin, 0);
		HAL_SPI_Transmit(&hspi1, dta, 1, 100);
		HAL_SPI_Receive(&hspi1, cts, 1, 1);

		if(cts[0]!=0xFF)
			HAL_GPIO_WritePin(RX_CS_GPIO_Port, RX_CS_Pin, 1);
	}

	HAL_SPI_Receive(&hspi1, data, len, 100);

	HAL_GPIO_WritePin(RX_CS_GPIO_Port, RX_CS_Pin, 1);
}

void RX_ReadRxDataBuff(uint8_t len, uint8_t *data)
{
	uint8_t cmd[1]={0x77};

	HAL_GPIO_WritePin(RX_CS_GPIO_Port, RX_CS_Pin, 0);
	HAL_SPI_Transmit(&hspi1, cmd, 1, 100);
	HAL_SPI_Receive(&hspi1, data, len, 100);
	HAL_GPIO_WritePin(RX_CS_GPIO_Port, RX_CS_Pin, 1);
}

//------------------------------SPI2 - Si4463 - TX------------------------------
void TX_WaitForCTS(void)
{
	uint8_t cts[1]={0x00};
	const uint8_t dta[1]={0x44};

	do
	{
		HAL_GPIO_WritePin(TX_CS_GPIO_Port, TX_CS_Pin, 0);
		HAL_SPI_Transmit(&hspi2, dta, 1, 100);
		HAL_SPI_Receive(&hspi2, cts, 1, 100);
		//if(cts[0]!=0xFF)
			HAL_GPIO_WritePin(TX_CS_GPIO_Port, TX_CS_Pin, 1);
	}while(cts[0]!=0xFF);
}

void TX_Send(uint8_t *data, uint8_t len)
{
	TX_WaitForCTS();
	HAL_GPIO_WritePin(TX_CS_GPIO_Port, TX_CS_Pin, 0);
	HAL_SPI_Transmit(&hspi2, data, len, 100);
	HAL_GPIO_WritePin(TX_CS_GPIO_Port, TX_CS_Pin, 1);
}

void TX_GetResponse(uint8_t len, uint8_t *data)
{
	uint8_t cts[1]={0x00};
	uint8_t dta[1]={0x44};

	while(cts[0]!=0xFF)
	{
		HAL_GPIO_WritePin(TX_CS_GPIO_Port, TX_CS_Pin, 0);
		HAL_SPI_Transmit(&hspi2, dta, 1, 100);
		HAL_SPI_Receive(&hspi2, cts, 1, 1);

		if(cts[0]!=0xFF)
			HAL_GPIO_WritePin(TX_CS_GPIO_Port, TX_CS_Pin, 1);
	}

	HAL_SPI_Receive(&hspi2, data, len, 100);

	HAL_GPIO_WritePin(TX_CS_GPIO_Port, TX_CS_Pin, 1);
}

void TX_WriteTxDataBuff(uint8_t *data, uint8_t len)
{
	uint8_t cmd = 0x66;

	HAL_GPIO_WritePin(TX_CS_GPIO_Port, TX_CS_Pin, 0);
	HAL_SPI_Transmit(&hspi2, &cmd, 1, 100);
	HAL_SPI_Transmit(&hspi2, data, len, 100);
	HAL_GPIO_WritePin(TX_CS_GPIO_Port, TX_CS_Pin, 1);
}

//------------------------------RX Si4463 FUNCS------------------------------
void RX_Reset(void)
{
	HAL_GPIO_WritePin(RX_SDN_GPIO_Port, RX_SDN_Pin, 1);
	HAL_Delay(5);
	HAL_GPIO_WritePin(RX_SDN_GPIO_Port, RX_SDN_Pin, 0);
	HAL_Delay(5);
}

static void RX_SetProp(uint8_t* vals, uint8_t group, uint8_t number, uint8_t len)
{
	uint8_t data[16]={0x11,	group, len, number};

	memcpy(data + 4, vals, len);

	RX_WaitForCTS();
	RX_Send(data, len + 4);
}

static void RX_StartupConfig(void)
{
	uint8_t buff[17];

	for(uint16_t i=0; i<sizeof(config); i++)
	{
		memcpy(buff, &config[i], sizeof(buff));
		RX_WaitForCTS();
		RX_Send(&buff[1], buff[0]);
		i += buff[0];
	}
}

static void RX_Interrupts(void* buff)
{
	uint8_t data = 0x20;

	RX_Send(&data, 1);
	if(buff!=NULL)
		RX_GetResponse(8, buff);
}

/*static void RX_InterruptsNoCTS(void* buff)
{
	uint8_t v = 0x20;

	HAL_GPIO_WritePin(RX_CS_GPIO_Port, RX_CS_Pin, 0);
	HAL_SPI_Transmit(&hspi1, &v, 1, 100);
	HAL_SPI_Receive(&hspi1, buff, 8, 100);
	HAL_GPIO_WritePin(RX_CS_GPIO_Port, RX_CS_Pin, 1);
}*/

static void RX_Interrupts2(void* buff, uint8_t clearPH, uint8_t clearMODEM, uint8_t clearCHIP)
{
	uint8_t data[] = {
		0x20,
		clearPH,
		clearMODEM,
		clearCHIP
	};

	RX_Send(data, 4);
	if(buff!=NULL)
		RX_GetResponse(8, buff);
}

static uint8_t RX_GetState(void)
{
	uint8_t state[2]={0, 0};
	uint8_t get_state_cmd=0x33;

	RX_WaitForCTS();
	RX_Send(&get_state_cmd, 1);
	RX_GetResponse(2, state);

	return state[0]&0x0F;
}

static void RX_SetState(uint8_t newState)
{
	uint8_t data[2]={0x34, newState};

	RX_Send(data, 2);
}

void RX_Sleep(void)
{
	uint8_t state=RX_GetState();

	if(state==7 || state==5)
		return;

	RX_SetState(1);
}

void RX_ClearFIFO(uint8_t fifos)
{
	uint8_t msg[3]={0x15, fifos};

	RX_Send(&msg, 2);
}

void RX_StartRx(uint8_t ch, uint8_t len)
{
	//RX_SetState(3);		//RX state
	RX_ClearFIFO(3);	//clear both FIFOs
	//RX_Interrupts2(NULL, 0, 0, 0xFF);	//clear some interrupts

	uint8_t msg[8]={0x32, ch, 0, 0, len, 0x08, 0x08, 0x08};

	RX_Send(msg, 8);
}

void RX_FreqSet(uint32_t freq)	//freq in Hz
{
	uint8_t inte=0x3C;	//default values
	uint64_t frac=0x00080000;

	freq=freq*(30.0/32.0);
	inte=freq/7500000-1;
	frac=(freq-(uint32_t)(inte+1)*7500000)/75;
	frac=(uint64_t)frac*(1<<19)/100000+(uint32_t)(1<<19);

	uint8_t vals[4]={inte, (frac>>16)&0xFF, (frac>>8)&0xFF, frac&0xFF};

	RX_SetProp(&vals, 0x40, 0x00, 4);
}

uint8_t RX_GetRSSI(void)
{
	uint8_t v=0x50;
	uint8_t r[4];

	HAL_GPIO_WritePin(RX_CS_GPIO_Port, RX_CS_Pin, 0);
	HAL_SPI_Transmit(&hspi1, &v, 1, 100);
	HAL_SPI_Receive(&hspi1, r, 4, 100);
	HAL_GPIO_WritePin(RX_CS_GPIO_Port, RX_CS_Pin, 1);

	return r[0];
}

void RX_GetInfo(uint8_t *resp)
{
	uint8_t cmd=0x01;

	RX_Send(&cmd, 1);
	RX_WaitForCTS();
	RX_GetResponse(8, resp);
}

uint8_t RX_Check(void)
{
	uint8_t info[8];

	RX_GetInfo(info);

	if(info[1]==0x44 && info[2]==0x63)
		return 0;

	return 1;
}

//------------------------------TX Si4463 FUNCS------------------------------
void TX_Reset(void)
{
	HAL_GPIO_WritePin(TX_SDN_GPIO_Port, TX_SDN_Pin, 1);
	HAL_Delay(5);
	HAL_GPIO_WritePin(TX_SDN_GPIO_Port, TX_SDN_Pin, 0);
	HAL_Delay(5);
}

static void TX_SetProp(uint8_t* vals, uint8_t group, uint8_t number, uint8_t len)
{
	uint8_t data[16]={0x11,	group, len, number};

	memcpy(data + 4, vals, len);

	TX_WaitForCTS();
	TX_Send(data, len + 4);
}

static void TX_StartupConfig(void)
{
	uint8_t buff[17];

	for(uint16_t i=0; i<sizeof(config); i++)
	{
		memcpy(buff, &config[i], sizeof(buff));
		TX_WaitForCTS();
		TX_Send(&buff[1], buff[0]);
		i += buff[0];
	}
}

static void TX_Interrupts(void* buff)
{
	uint8_t data = 0x20;

	TX_Send(&data, 1);
	if(buff!=NULL)
		TX_GetResponse(8, buff);
}

/*static void TX_InterruptsNoCTS(void* buff)
{
	uint8_t v = 0x20;

	HAL_GPIO_WritePin(TX_CS_GPIO_Port, TX_CS_Pin, 0);
	HAL_SPI_Transmit(&hspi2, &v, 1, 100);
	HAL_SPI_Receive(&hspi21, buff, 8, 100);
	HAL_GPIO_WritePin(TX_CS_GPIO_Port, TX_CS_Pin, 1);
}*/

static void TX_Interrupts2(void* buff, uint8_t clearPH, uint8_t clearMODEM, uint8_t clearCHIP)
{
	uint8_t data[] = {
		0x20,
		clearPH,
		clearMODEM,
		clearCHIP
	};

	TX_Send(data, 4);
	if(buff!=NULL)
		TX_GetResponse(8, buff);
}

static uint8_t TX_GetState(void)
{
	uint8_t state[2]={0, 0};
	uint8_t get_state_cmd=0x33;

	TX_WaitForCTS();
	TX_Send(&get_state_cmd, 1);
	TX_GetResponse(2, state);

	return state[0]&0x0F;
}

static void TX_SetState(uint8_t newState)
{
	uint8_t data[2]={0x34, newState};

	TX_Send(data, 2);
}

void TX_Sleep(void)
{
	uint8_t state=TX_GetState();

	if(state==7 || state==5)
		return;

	TX_SetState(1);
}

void TX_ClearFIFO(uint8_t fifos)
{
	uint8_t msg[3]={0x15, fifos};

	TX_Send(&msg, 2);
}

void TX_SetTxPower(uint8_t pwr)
{
	/*uint8_t msg[5]={0x11, 0x22, 0x01, 0x01, pwr};

	TX_Send(&msg, 5);*/
	TX_SetProp(&pwr, 0x22, 0x01, 1);
}

void TX_StartTx(uint8_t ch, uint8_t end_state, uint8_t tx_len)
{
	uint8_t msg[7]={0x31, ch, (uint8_t)end_state<<4, 0, tx_len, 0, 0};

	TX_WaitForCTS();
	TX_Send(&msg, 7);
}

void TX_TxData(uint8_t *d, uint8_t len, uint8_t ch)
{
	TX_ClearFIFO(3);
	TX_Interrupts2(NULL, 0, 0, 0xFF);

	TX_WriteTxDataBuff(d, len);
	TX_StartTx(ch, 3, len);	//3 - READY state after TX complete
}

void TX_FreqSet(uint32_t freq)	//freq in Hz
{
	uint8_t inte=0x3C;	//default values
	uint64_t frac=0x00080000;

	freq=freq*(30.0/32.0);
	inte=freq/7500000-1;
	frac=(freq-(uint32_t)(inte+1)*7500000)/75;
	frac=(uint64_t)frac*(1<<19)/100000+(uint32_t)(1<<19);

	uint8_t vals[4]={inte, (frac>>16)&0xFF, (frac>>8)&0xFF, frac&0xFF};

	TX_SetProp(&vals, 0x40, 0x00, 4);
}

void TX_GetInfo(uint8_t *resp)
{
	uint8_t cmd=0x01;

	TX_Send(&cmd, 1);
	TX_WaitForCTS();
	TX_GetResponse(8, resp);
}

uint8_t TX_Check(void)
{
	uint8_t info[8];

	TX_GetInfo(info);

	if(info[1]==0x44 && info[2]==0x63)
		return 0;

	return 1;
}

//----------------------------------MISC FUNCS---------------------------------
void Delay(uint32_t val)
{
	for(uint32_t i=0; i<val; i++)
		__ASM volatile("NOP");
}

//----------------------------------LCD FUNCS----------------------------------
/*void LCD_Wait(void)
{
	HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, 0);
	for(uint8_t i=0; i<100; i++);
	HAL_GPIO_WritePin(RW_GPIO_Port, RW_Pin, 1);
	for(uint8_t i=0; i<100; i++);
	GPIOD->MODER&=~0x0000;
	while((GPIOD->IDR)&0x80);
	GPIOD->MODER=0x5555;
}*/

void LCD_Init(void)
{
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, 0);
	HAL_Delay(0);
	HAL_GPIO_WritePin(LCD_RES_GPIO_Port, LCD_RES_Pin, 1);
	HAL_Delay(50);
	HAL_GPIO_WritePin(LCD_RES_GPIO_Port, LCD_RES_Pin, 0);
	HAL_Delay(250);
	HAL_GPIO_WritePin(LCD_RES_GPIO_Port, LCD_RES_Pin, 1);
	HAL_Delay(50);
}
void LCD_SetX(uint8_t x)
{
	HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, 0);
	HAL_GPIO_WritePin(LCD_RW_GPIO_Port, LCD_RW_Pin, 0);
	Delay(200);
	GPIOE->ODR&=0x00FF; GPIOE->ODR|=(uint32_t)(0b10111000|x)<<8;
	Delay(100);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, 1);
	Delay(200);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, 0);
	Delay(200);
}

void LCD_SetY(uint8_t y)
{
	HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, 0);
	HAL_GPIO_WritePin(LCD_RW_GPIO_Port, LCD_RW_Pin, 0);
	Delay(200);
	GPIOE->ODR&=0x00FF; GPIOE->ODR|=(uint32_t)(0b01000000|y)<<8;
	Delay(100);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, 1);
	Delay(200);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, 0);
	Delay(200);
}

void LCD_SetZ(uint8_t z)
{
	HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, 0);
	HAL_GPIO_WritePin(LCD_RW_GPIO_Port, LCD_RW_Pin, 0);
	Delay(200);
	GPIOE->ODR&=0x00FF; GPIOE->ODR|=(uint32_t)(0b11000000|z)<<8;
	Delay(100);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, 1);
	Delay(200);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, 0);
	Delay(200);
}

void LCD_WriteData(uint8_t dta)
{
	HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, 1);
	HAL_GPIO_WritePin(LCD_RW_GPIO_Port, LCD_RW_Pin, 0);
	Delay(200);
	GPIOE->ODR&=0x00FF; GPIOE->ODR|=(uint32_t)dta<<8;
	Delay(125);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, 1);
	Delay(200);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, 0);
	Delay(200);
}

void LCD_Disp(uint8_t ena)
{
	HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, 0);
	HAL_GPIO_WritePin(LCD_RW_GPIO_Port, LCD_RW_Pin, 0);
	Delay(200);
	GPIOE->ODR&=0xFF00; GPIOE->ODR|=(uint32_t)(0b00111110|ena)<<8;
	Delay(100);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, 1);
	Delay(200);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, 0);
	Delay(200);
}

void LCD_Clear(void)
{
	HAL_GPIO_WritePin(LCD_CS1_GPIO_Port, LCD_CS1_Pin, 0);
	HAL_GPIO_WritePin(LCD_CS2_GPIO_Port, LCD_CS2_Pin, 0);
	HAL_GPIO_WritePin(LCD_CS3_GPIO_Port, LCD_CS3_Pin, 0);

	LCD_Disp(0);

	LCD_SetZ(0);

	for(uint8_t x=0; x<8; x++)
	{
		for(uint8_t y=0; y<64; y++)
		{
			LCD_SetX(x);
			LCD_SetY(y);
			LCD_WriteData(0);
		}
	}

	LCD_Disp(1);
}

//1 - 6x8; 2 - 12x16
void LCD_PutStrFast(uint8_t x, uint8_t y, uint8_t *str, uint8_t font)
{
	uint8_t k=0;
	LCD_SetZ(0);
	if(font==1)
	{
		for(uint j=0; j<strlen(str); j++)
		{
			for(uint8_t i=0; i<6; i++)
			{
				if((x+k+i)<64)
				{
					HAL_GPIO_WritePin(LCD_CS1_GPIO_Port, LCD_CS1_Pin, 0);
					HAL_GPIO_WritePin(LCD_CS2_GPIO_Port, LCD_CS2_Pin, 1);
					HAL_GPIO_WritePin(LCD_CS3_GPIO_Port, LCD_CS3_Pin, 1);
				}
				else if((x+k+i)<128)
				{
					HAL_GPIO_WritePin(LCD_CS1_GPIO_Port, LCD_CS1_Pin, 1);
					HAL_GPIO_WritePin(LCD_CS2_GPIO_Port, LCD_CS2_Pin, 0);
					HAL_GPIO_WritePin(LCD_CS3_GPIO_Port, LCD_CS3_Pin, 1);
				}
				else
				{
					HAL_GPIO_WritePin(LCD_CS1_GPIO_Port, LCD_CS1_Pin, 1);
					HAL_GPIO_WritePin(LCD_CS2_GPIO_Port, LCD_CS2_Pin, 1);
					HAL_GPIO_WritePin(LCD_CS3_GPIO_Port, LCD_CS3_Pin, 0);
				}

				LCD_SetX(y);
				LCD_SetY((x+k+i)%64);
				LCD_WriteData(font_6x8[str[j]][i]);
			}

			k+=6;
		}
	}
	else if(font==2)
	{
		for(uint j=0; j<strlen(str); j++)
		{
			for(uint8_t i=0; i<24; i++)
			{
				if((x+k+i/2)<64)
				{
					HAL_GPIO_WritePin(LCD_CS1_GPIO_Port, LCD_CS1_Pin, 0);
					HAL_GPIO_WritePin(LCD_CS2_GPIO_Port, LCD_CS2_Pin, 1);
					HAL_GPIO_WritePin(LCD_CS3_GPIO_Port, LCD_CS3_Pin, 1);
				}
				else if((x+k+i/2)<128)
				{
					HAL_GPIO_WritePin(LCD_CS1_GPIO_Port, LCD_CS1_Pin, 1);
					HAL_GPIO_WritePin(LCD_CS2_GPIO_Port, LCD_CS2_Pin, 0);
					HAL_GPIO_WritePin(LCD_CS3_GPIO_Port, LCD_CS3_Pin, 1);
				}
				else
				{
					HAL_GPIO_WritePin(LCD_CS1_GPIO_Port, LCD_CS1_Pin, 1);
					HAL_GPIO_WritePin(LCD_CS2_GPIO_Port, LCD_CS2_Pin, 1);
					HAL_GPIO_WritePin(LCD_CS3_GPIO_Port, LCD_CS3_Pin, 0);
				}

				LCD_SetX(y+i%2);
				LCD_SetY((x+k+i/2)%64);
				LCD_WriteData(font_12x16[str[j]][i]);
			}

			k+=12;
		}
	}
}

//------------------------------IRQ HANDLER FUNCS------------------------------
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	//RX_NIRQ
	if(GPIO_Pin==GPIO_PIN_5 && r_initd==1)
	{
		RX_Interrupts(RX_ints);	//check pending interrupt flags

		//PACKET_RX_PEND flag set?
		if(RX_ints[2]&(1<<4))
		{
			HAL_GPIO_TogglePin(LED_0_GPIO_Port, LED_0_Pin);
			RX_ReadRxDataBuff(PLOAD_LEN, rcv_buff);
			RX_ClearFIFO(3);

			uint32_t now_id_from=(rcv_buff[19]<<16) | (rcv_buff[20]<<8) | rcv_buff[21];
			uint32_t now_id_to=(rcv_buff[22]<<16) | (rcv_buff[23]<<8) | rcv_buff[24];

			if(last_id_from!=now_id_from)
				last_id_from=now_id_from;
			if(last_id_to!=now_id_to)
				last_id_to=now_id_to;

			uint8_t s[20];
			sprintf(s, "%07d->", last_id_from);
			LCD_PutStrFast(114, 2, s, 1);
			sprintf(s, "    ->%07d", last_id_to);
			LCD_PutStrFast(114, 3, s, 1);
		}

		//clear pending flags
		RX_Interrupts(NULL);
	}
}
/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  *
  * @retval None
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_DAC_Init();
  MX_SPI2_Init();
  MX_TIM4_Init();
  MX_USART1_UART_Init();
  MX_SPI1_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
  HAL_Delay(1000);
  RX_Reset();
  TX_Reset();

  if(RX_Check() || TX_Check())	//fucked up comms with either one of Si4463
  {
	  while(1)
	  {
		  HAL_GPIO_TogglePin(LED_0_GPIO_Port, LED_0_Pin);
		  HAL_Delay(100);
	  }
  }

  RX_StartupConfig(); TX_StartupConfig();
  RX_Interrupts(NULL); TX_Interrupts(NULL);
  RX_FreqSet(rx_freq); TX_FreqSet(rx_freq-7600000);
  RX_Sleep(); TX_Sleep();
  RX_StartRx(0, PLOAD_LEN);
  TX_SetTxPower(10);
  r_initd=1;

  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
  TIM4->CCR1=99;
  HAL_Delay(500);

  HAL_GPIO_WritePin(LCD_CS1_GPIO_Port, LCD_CS1_Pin, 0);
  HAL_GPIO_WritePin(LCD_CS2_GPIO_Port, LCD_CS2_Pin, 0);
  HAL_GPIO_WritePin(LCD_CS3_GPIO_Port, LCD_CS3_Pin, 0);

  LCD_Init();

  LCD_Clear();

  LCD_PutStrFast(0, 0, "M17 STREFA CENTRUM", 1); LCD_PutStrFast(138, 0, "TEST", 1);

  LCD_PutStrFast(0, 2, "RX   439.575MHz", 1);
  LCD_PutStrFast(0, 3, "TX   431.975MHz", 1);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  HAL_GPIO_TogglePin(LED_0_GPIO_Port, LED_0_Pin);
	  HAL_Delay(1000);
	  TX_TxData("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567", PLOAD_LEN, 0);
  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */

}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct;

    /**Configure the main internal regulator output voltage 
    */
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 216;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Activate the Over-Drive mode 
    */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USART1;
  PeriphClkInitStruct.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* ADC1 init function */
static void MX_ADC1_Init(void)
{

  ADC_ChannelConfTypeDef sConfig;

    /**Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion) 
    */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time. 
    */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* DAC init function */
static void MX_DAC_Init(void)
{

  DAC_ChannelConfTypeDef sConfig;

    /**DAC Initialization 
    */
  hdac.Instance = DAC;
  if (HAL_DAC_Init(&hdac) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**DAC channel OUT1 config 
    */
  sConfig.DAC_Trigger = DAC_TRIGGER_NONE;
  sConfig.DAC_OutputBuffer = DAC_OUTPUTBUFFER_ENABLE;
  if (HAL_DAC_ConfigChannel(&hdac, &sConfig, DAC_CHANNEL_1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* SPI1 init function */
static void MX_SPI1_Init(void)
{

  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 7;
  hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi1.Init.NSSPMode = SPI_NSS_PULSE_DISABLE;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* SPI2 init function */
static void MX_SPI2_Init(void)
{

  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_MASTER;
  hspi2.Init.Direction = SPI_DIRECTION_2LINES;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_32;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 7;
  hspi2.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi2.Init.NSSPMode = SPI_NSS_PULSE_DISABLE;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* TIM3 init function */
static void MX_TIM3_Init(void)
{

  TIM_Encoder_InitTypeDef sConfig;
  TIM_MasterConfigTypeDef sMasterConfig;

  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 0;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 0;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  sConfig.EncoderMode = TIM_ENCODERMODE_TI1;
  sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC1Filter = 0;
  sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC2Filter = 0;
  if (HAL_TIM_Encoder_Init(&htim3, &sConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* TIM4 init function */
static void MX_TIM4_Init(void)
{

  TIM_ClockConfigTypeDef sClockSourceConfig;
  TIM_MasterConfigTypeDef sMasterConfig;
  TIM_OC_InitTypeDef sConfigOC;

  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 21599;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 99;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim4, &sClockSourceConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  if (HAL_TIM_PWM_Init(&htim4) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 45;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sConfigOC.Pulse = 0;
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  HAL_TIM_MspPostInit(&htim4);

}

/* USART1 init function */
static void MX_USART1_UART_Init(void)
{

  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, TP7_Pin|TP8_Pin|LCD_E_Pin|LCD_DB0_Pin 
                          |LCD_DB1_Pin|LCD_DB2_Pin|LCD_DB3_Pin|LCD_DB4_Pin 
                          |LCD_DB5_Pin|LCD_DB6_Pin|LCD_DB7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, LCD_CS1_Pin|LCD_CS2_Pin|LCD_CS3_Pin|LED_1_Pin 
                          |LED_2_Pin|LED_3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(RX_CS_GPIO_Port, RX_CS_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, RX_SDN_Pin|TX_SDN_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LCD_RS_Pin|LCD_RW_Pin|LCD_RES_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(TX_CS_GPIO_Port, TX_CS_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_0_GPIO_Port, LED_0_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, LED_4_Pin|LED_5_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : TP7_Pin TP8_Pin */
  GPIO_InitStruct.Pin = TP7_Pin|TP8_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : TAMPER_Pin PTT_Pin ENC_BTN_Pin */
  GPIO_InitStruct.Pin = TAMPER_Pin|PTT_Pin|ENC_BTN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : LCD_CS1_Pin LCD_CS2_Pin LCD_CS3_Pin RX_CS_Pin */
  GPIO_InitStruct.Pin = LCD_CS1_Pin|LCD_CS2_Pin|LCD_CS3_Pin|RX_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : RX_NIRQ_Pin */
  GPIO_InitStruct.Pin = RX_NIRQ_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(RX_NIRQ_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : RX_SDN_Pin LCD_RS_Pin LCD_RW_Pin LCD_RES_Pin 
                           TX_SDN_Pin */
  GPIO_InitStruct.Pin = RX_SDN_Pin|LCD_RS_Pin|LCD_RW_Pin|LCD_RES_Pin 
                          |TX_SDN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : LCD_E_Pin LCD_DB0_Pin LCD_DB1_Pin LCD_DB2_Pin 
                           LCD_DB3_Pin LCD_DB4_Pin LCD_DB5_Pin LCD_DB6_Pin 
                           LCD_DB7_Pin */
  GPIO_InitStruct.Pin = LCD_E_Pin|LCD_DB0_Pin|LCD_DB1_Pin|LCD_DB2_Pin 
                          |LCD_DB3_Pin|LCD_DB4_Pin|LCD_DB5_Pin|LCD_DB6_Pin 
                          |LCD_DB7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : TX_CS_Pin */
  GPIO_InitStruct.Pin = TX_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(TX_CS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : TX_NIRQ_Pin BTN_3_Pin BTN_2_Pin BTN_1_Pin 
                           BTN_0_Pin */
  GPIO_InitStruct.Pin = TX_NIRQ_Pin|BTN_3_Pin|BTN_2_Pin|BTN_1_Pin 
                          |BTN_0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : LED_0_Pin */
  GPIO_InitStruct.Pin = LED_0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_0_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_1_Pin LED_2_Pin LED_3_Pin */
  GPIO_InitStruct.Pin = LED_1_Pin|LED_2_Pin|LED_3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_4_Pin LED_5_Pin */
  GPIO_InitStruct.Pin = LED_4_Pin|LED_5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

  HAL_NVIC_SetPriority(EXTI1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI1_IRQn);

  HAL_NVIC_SetPriority(EXTI2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI2_IRQn);

  HAL_NVIC_SetPriority(EXTI3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI3_IRQn);

  HAL_NVIC_SetPriority(EXTI4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_IRQn);

  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void _Error_Handler(char *file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
