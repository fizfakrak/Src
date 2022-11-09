/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32g4xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32g4xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
extern unsigned int period, pulseWidth;
extern unsigned long count_mess, counter_send, number_bit,n;
extern unsigned char counter, data[2], adc,  buff_read[4], buff_ready[40] ;
unsigned char dlit_log_1, dlit_log_0, MANCH_REG, bit, MANCH_SINHFLAG_1 = 2, MANCH_SINHFLAG_0 = 1, counter_ready;
uint16_t manch_read  ;
extern uint8_t buff_manch[42] ;//sinh 
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
 
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern DMA_HandleTypeDef hdma_spi1_tx;
extern DMA_HandleTypeDef hdma_tim1_up;
extern DMA_HandleTypeDef hdma_tim2_up;
extern DMA_HandleTypeDef hdma_tim3_ch4;
extern TIM_HandleTypeDef htim4;
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */ 
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32G4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32g4xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles DMA1 channel1 global interrupt.
  */
void DMA1_Channel1_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Channel1_IRQn 0 */

  /* USER CODE END DMA1_Channel1_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_tim1_up);
  /* USER CODE BEGIN DMA1_Channel1_IRQn 1 */

  /* USER CODE END DMA1_Channel1_IRQn 1 */
}

/**
  * @brief This function handles DMA1 channel2 global interrupt.
  */
void DMA1_Channel2_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Channel2_IRQn 0 */

  /* USER CODE END DMA1_Channel2_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_tim2_up);
  /* USER CODE BEGIN DMA1_Channel2_IRQn 1 */

  /* USER CODE END DMA1_Channel2_IRQn 1 */
}

/**
  * @brief This function handles DMA1 channel3 global interrupt.
  */
void DMA1_Channel3_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Channel3_IRQn 0 */

  /* USER CODE END DMA1_Channel3_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_tim3_ch4);
  /* USER CODE BEGIN DMA1_Channel3_IRQn 1 */

  /* USER CODE END DMA1_Channel3_IRQn 1 */
}

/**
  * @brief This function handles DMA1 channel4 global interrupt.
  */
void DMA1_Channel4_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Channel4_IRQn 0 */

  /* USER CODE END DMA1_Channel4_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_spi1_tx);
  /* USER CODE BEGIN DMA1_Channel4_IRQn 1 */

  /* USER CODE END DMA1_Channel4_IRQn 1 */
}

/**
  * @brief This function handles TIM4 global interrupt.
  */
void TIM4_IRQHandler(void)
{
  /* USER CODE BEGIN TIM4_IRQn 0 */

  /* USER CODE END TIM4_IRQn 0 */
  HAL_TIM_IRQHandler(&htim4);
  /* USER CODE BEGIN TIM4_IRQn 1 */

  /* USER CODE END TIM4_IRQn 1 */
}

/* USER CODE BEGIN 1 */



void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM4)
    {
        if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
        {
         period  = TIM4->CCR1;
         pulseWidth = TIM4->CCR2;
       //  TIM4->CNT = 0;
         dlit_log_1 = period - pulseWidth;
         buff_ready[counter_ready++] =  period - pulseWidth;
          if(MANCH_REG == (MANCH_SINHFLAG_1 | MANCH_SINHFLAG_0))
          {
            if (((dlit_log_1) > 21) & ((dlit_log_1) < 26) || (bit == 1)) {manch_read |= (1 << --n); bit = 0;}
            else  if (((dlit_log_1) > 10) & ((dlit_log_1) < 14) & (bit == 0)) bit = 1;
          }
         
         if(!(MANCH_REG & MANCH_SINHFLAG_1) & ((dlit_log_1) > 30) & (MANCH_REG & MANCH_SINHFLAG_0))
          {
            if((dlit_log_1) < 37)
            {
              MANCH_REG |= MANCH_SINHFLAG_1;
              n=16;
              bit = 1;
            }
            else
            {
              if((dlit_log_1) < 49)
              {
                MANCH_REG |= MANCH_SINHFLAG_1;
                n=16;
                manch_read |= (1 << --n);
                bit = 0;
              }
            }
          }

          // TIM4->CNT = 0;
        }
        if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)
        {
         // TIM4->CNT = 0;
         pulseWidth= TIM4->CCR1;
         period = TIM4->CCR2;
         dlit_log_0 = period - pulseWidth;
         buff_ready[counter_ready++] = period - pulseWidth;          
          if(!(MANCH_REG & MANCH_SINHFLAG_1) & ((dlit_log_0) > 34) & !(MANCH_REG & MANCH_SINHFLAG_0) & ((dlit_log_0) < 38))
          {
          MANCH_REG |= MANCH_SINHFLAG_0;
          }
          if(MANCH_REG == (MANCH_SINHFLAG_1 | MANCH_SINHFLAG_0))
          {
            if (((dlit_log_0) > 21) & ((dlit_log_0) < 26) || (bit == 1)) {manch_read &= ~(1 << --n);bit = 0;}
            else if (((dlit_log_0) > 10) & ((dlit_log_0) < 14) & (bit == 0)) bit = 1;
          }
        }
        if(n == 0)
        {MANCH_REG = 0;
          
          if(manch_read == 0x0d41)
          {
            TIM4->CR1 &= ~TIM_CR1_CEN;
            buff_read[0] = 0x75;
            buff_read[1] = 0x73;
            counter_send = 6;
            for(count_mess = 0; count_mess<2; count_mess++) 
                 {
                   for(number_bit = 128; number_bit>0; number_bit = number_bit/2)
                   {
                     if(buff_read[count_mess] & number_bit)
                     {
                      buff_manch[counter_send++] = 0x0002;
                      buff_manch[counter_send++] = 0x0004;
                     }
                     else
                     {
                      buff_manch[counter_send++] = 0x0004;
                      buff_manch[counter_send++] = 0x0002;
                     }
                   }
                 }
            
            DMA1_Channel1->CCR |= DMA_CCR_EN;
          TIM1->CR1 |= TIM_CR1_CEN;
          }
          MANCH_REG = 0;
          while(!(USART3->ISR & USART_ISR_TXE));
          USART3->TDR = manch_read;
          while(!(USART3->ISR & USART_ISR_TXE));
          USART3->TDR = manch_read >> 8;
       /*   for(counter_ready = 0; counter_ready <31;counter_ready++)
          {
            while(!(USART3->ISR & USART_ISR_TXE));
            USART3->TDR = buff_ready[counter_ready];
          }*/
          counter_ready = 0;
         n = 18;
        }
    }
}
/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
