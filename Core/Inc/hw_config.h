/*
 * hw_config.h
 *
 *  Created on: Aug 4, 2024
 *      Author: Admin
 */

#ifndef INC_HW_CONFIG_H_
#define INC_HW_CONFIG_H_

//MOTOR
#define PPairs		7		//pole pairs

// SPI
#define AMT_SPI			hspi1		//Encoder SPI handle
#define AMT_CS			GPIOA, GPIO_PIN_15		//Encoder chip select

//CAN
#define CANID_MASTER 	0x1
#define CANID_SLAVE 	0x0

//ADC
#define Vbus_scale		0.008369954427f		//DC bus voltage scale (voltage divider)

//SVM
#define DTC_MIN		0.0f		//minimum duty cycle
#define DTC_MAX		0.94f		//maximum duty cycle
#define DTC_MID		0.47f		//duty cycle midpoint
#define OVERMODULATION		1.0f	//
#endif /* INC_HW_CONFIG_H_ */
