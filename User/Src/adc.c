/**
   @file adc.c
   @brief Using ADC for simple measurements
   @author Bernhard Breinbauer
 */

// Includes ------------------------------------------------------------------
#include <stdio.h>

#include "stm32f4xx.h"
#include "stm32f429i_discovery.h"
#include "stm32f4xx_hal_adc.h"


#include "adc.h"

// Variables ------------------------------------------------------------------
static ADC_HandleTypeDef adc1Handle;

// Function Declarations ------------------------------------------------------
static void GpioInit(void);
static void AdcInit(void);

// Functions ------------------------------------------------------------------

/**
 * Initialization Code for module adc
 * @param None
 * @retval None
 */
void adcInit(void) {
	GpioInit();
	AdcInit();

}

/**
 * return voltage value of ADC measurement on potentiometer
 * @param None
 * @retval voltage value
 */
float adcPotiVoltage(void){
	uint16_t messwert;
	float voltage;

	ADC_ChannelConfTypeDef adc1Ch5;
	adc1Ch5.Channel = ADC_CHANNEL_5;
	adc1Ch5.Rank = 1; // set rank to 1
	adc1Ch5.SamplingTime = ADC_SAMPLETIME_144CYCLES; // set sampling time to 144 clock cycles
	HAL_ADC_ConfigChannel(&adc1Handle, &adc1Ch5); // select channel_5 for ADC1

	// TODO: start ADC measurement: HAL_ADC_Start()


	// wait until conversion is finished
	// (could be done with interrupt - would require different configuration)
	if (HAL_ADC_PollForConversion(&adc1Handle, 5) == HAL_TIMEOUT) {
		// Error
		return -1.0;
	}

	// TODO: get measurement result, calculate voltage value: HAL_ADC_GetValue()

	return voltage;
}





/**
 * @brief  Configuration of used GPIOs
 * @param  None
 * @retval None
 */
static void GpioInit(void)
{
	// TODO: What GPIOs do we need? -> Configure them!

}

/**
 * @brief  Configuration of ADC1 and ADC3
 * @param  None
 * @retval None
 */
static void AdcInit(void) {
	__HAL_RCC_ADC1_CLK_ENABLE();

	// TODO: Initialize ADC1 for single conversion
/*	adc1Handle.Instance =
	adc1Handle.Init.Resolution =
	adc1Handle.Init.EOCSelection =
	adc1Handle.Init.DataAlign =
	adc1Handle.Init.ExternalTrigConv =
*/
	adc1Handle.Init.ClockPrescaler = 0;
	adc1Handle.Init.ContinuousConvMode = DISABLE;
	adc1Handle.Init.DMAContinuousRequests = DISABLE;
	adc1Handle.Init.DiscontinuousConvMode = DISABLE;
	adc1Handle.Init.ExternalTrigConvEdge = 0;
	adc1Handle.Init.NbrOfConversion = 0;
	adc1Handle.Init.NbrOfDiscConversion = 0;
	adc1Handle.Init.ScanConvMode = DISABLE;

	// TODO: Use HAL_ADC_Init() to configure the ADC
}
