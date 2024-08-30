/*
 * foc.h
 *
 *  Created on: Aug 7, 2024
 *      Author: Admin
 */

#ifndef INC_FOC_H_
#define INC_FOC_H_

typedef struct{
	float v_u, v_v, v_w;
	float v_bus;
	float v_d, v_q;
    float dtc_u, dtc_v, dtc_w;
}ControllerStruct;

void set_dtc(ControllerStruct *controller);
void abc(float theta, float d, float q, float *a, float *b, float *c);
void svm(float v_max, float u, float v, float w, float *dtc_u, float *dtc_v, float *dtc_w);

#endif /* INC_FOC_H_ */
