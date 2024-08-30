/*
 * maths.h
 *
 *  Created on: Aug 6, 2024
 *      Author: Admin
 */

#ifndef INC_MATHS_H_
#define INC_MATHS_H_

#include "math.h"

#define TWO_PI		6.283185307f		//2*pi
#define PI_OVER_TWO		1.570796327f		//pi/2

#define SQRT3_2		0.866025403		//sqrt3/2

#define fourteen_bits		16384.0f		//2^14
#define sin_lut_mult		81.4873308631f	//


float fast_fmaxf(float x, float y);
float fast_fminf(float x, float y);
float fminf3(float x, float y, float z);
float fmaxf3(float x, float y, float z);
float sin_lut(float theta);
float cos_lut(float theta);

#endif /* INC_MATHS_H_ */
