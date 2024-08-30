/*
 * structs.h
 *
 *  Created on: Aug 4, 2024
 *      Author: Admin
 */

#ifndef INC_STRUCTS_H_
#define INC_STRUCTS_H_


#include <stdint.h>
#include "gpio.h"
#include "adc.h"
#include "tim.h"
#include "analog_sample.h"
#include "fdcan.h"
#include "foc.h"

extern Encoderstruct AMT_struct;
extern CANTxMessage can_tx;
extern CANRxMessage can_rx;
extern ControllerStruct controller;

#endif /* INC_STRUCTS_H_ */
