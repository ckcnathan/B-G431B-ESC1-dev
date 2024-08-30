/*
 * foc.c
 *
 *  Created on: Aug 7, 2024
 *      Author: Admin
 */

#include "foc.h"
#include "maths.h"
#include "hw_config.h"
#include "tim.h"

void set_dtc(ControllerStruct *controller){

	/* Invert duty cycle if that's how hardware is configured */

	float dtc_u = controller->dtc_u;
	float dtc_v = controller->dtc_v;
	float dtc_w = controller->dtc_w;

	/* Handle phase order swapping so that voltage/current/torque match encoder direction */
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, ((htim1.Instance->ARR))*dtc_u);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, ((htim1.Instance->ARR))*dtc_v);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, ((htim1.Instance->ARR))*dtc_w);

}


void abc(float theta, float d, float q, float *a, float *b, float *c){
    float cf = cos_lut(theta);
    float sf = sin_lut(theta);

    *a = cf*d - sf*q;
    *b = (SQRT3_2*sf-.5f*cf)*d - (-SQRT3_2*cf-.5f*sf)*q;
    *c = (-SQRT3_2*sf-.5f*cf)*d - (SQRT3_2*cf-.5f*sf)*q;
}


void svm(float v_max, float u, float v, float w, float *dtc_u, float *dtc_v, float *dtc_w){
    /* Space Vector Modulation
     u,v,w amplitude = v_bus for full modulation depth */

    float v_offset = (fminf3(u, v, w) + fmaxf3(u, v, w))*0.5f;

    *dtc_u = fast_fminf(fast_fmaxf((.5f*(u -v_offset)*OVERMODULATION/v_max + DTC_MID ), DTC_MIN), DTC_MAX);
    *dtc_v = fast_fminf(fast_fmaxf((.5f*(v -v_offset)*OVERMODULATION/v_max + DTC_MID ), DTC_MIN), DTC_MAX);
    *dtc_w = fast_fminf(fast_fmaxf((.5f*(w -v_offset)*OVERMODULATION/v_max + DTC_MID ), DTC_MIN), DTC_MAX);
    }




