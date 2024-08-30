/*
 * analog_sample.h
 *
 *  Created on: Aug 6, 2024
 *      Author: Admin
 */

#ifndef INC_ANALOG_SAMPLE_H_
#define INC_ANALOG_SAMPLE_H_

#include "spi.h"
#include <stdint.h>


typedef struct{
	union{
		uint8_t spi_rx_buff[2];
		uint16_t spi_rx_word;
	};
	uint16_t old_count, new_count;
	float old_angle, new_angle;
	int amt_offset;
} Encoderstruct;

void ps_amt_sample();
float vbus_sample();

#endif /* INC_ANALOG_SAMPLE_H_ */
