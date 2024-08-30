
#include <stdio.h>
#include "analog_sample.h"
#include "hw_config.h"
#include "maths.h"
#include "adc.h"



void ps_amt_sample(Encoderstruct *encoder){

	HAL_GPIO_WritePin(AMT_CS, 0);		//chip select
	encoder->old_angle = encoder->new_angle;
	encoder->old_count = encoder->new_count;

	HAL_SPI_Receive(&AMT_SPI, (uint8_t *)encoder->spi_rx_buff, 1, 100);
	while( AMT_SPI.State == HAL_SPI_STATE_BUSY );
	HAL_GPIO_WritePin(AMT_CS, 1);

	encoder->amt_offset = 2312; //0b00100100010000;
	encoder->new_count = ((encoder->spi_rx_word & 0x1FFF)<<1) - encoder->amt_offset;
	if (encoder->new_count < 0){
		encoder->new_count = TWO_PI+encoder->new_count;
	}
	encoder->new_angle = (float)encoder->new_count*TWO_PI/fourteen_bits;
}

float vbus_sample(){
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	return HAL_ADC_GetValue(&hadc1)*Vbus_scale;
	//uint16_t VBUS_RAW[1];
    //HAL_ADC_Start_DMA(&hadc1,(uint32_t*)VBUS_RAW,1);
	//return VBUS_RAW[0]*Vbus_scale;
}

