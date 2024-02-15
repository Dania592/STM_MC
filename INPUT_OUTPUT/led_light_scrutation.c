
/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA

#define USER_B_GPIO_Port GPIOC
#define USER_B GPIO_PIN_13

/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void Error_Handler(void);


/* Private functions ---------------------------------------------------------*/
/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{


  /* STM32F4xx HAL library initialization*/
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();


  /*A COMPLETER */
  //Activate clock for GPIOA
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  
  // Initialisation GPIOA: Pin 5
  GPIO_InitTypeDef GPIO_Led2 ;
  GPIO_Led2.Pin = LD2_Pin;
  GPIO_Led2.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_Led2.Pull = GPIO_PULLDOWN;
  GPIO_Led2.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_Led2);

  // initialisation GPIOC : PIN 13
  GPIO_InitTypeDef GPIO_USER_B ;
  GPIO_USER_B.Pin = USER_B;
  GPIO_USER_B.Mode = GPIO_MODE_INPUT;
  GPIO_USER_B.Pull = GPIO_PULLDOWN;
  GPIO_USER_B.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(USER_B_GPIO_Port, &GPIO_USER_B);

	//Set default value: RESET
  HAL_GPIO_WritePin(GPIOA, LD2_Pin, GPIO_PIN_RESET);
	
	//Infinite loop
	while(1){
		GPIO_PinState state = HAL_GPIO_ReadPin(GPIOC, USER_B);

		if(state == GPIO_PIN_RESET){
			HAL_GPIO_WritePin(GPIOA, LD2_Pin, GPIO_PIN_RESET);
			HAL_Delay(500);
		}else{
			HAL_GPIO_WritePin(GPIOA, LD2_Pin, GPIO_PIN_SET);
		}

	}
}


void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}
/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void Error_Handler(void)
{
  /* User may add here some code to deal with this error */
  while(1)
  {
  }
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
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
