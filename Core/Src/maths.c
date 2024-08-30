/*
 * maths.c
 *
 *  Created on: Aug 7, 2024
 *      Author: Admin
 */

#include "maths.h"
#include "lookup.h"


float fast_fmaxf(float x, float y){
    /// Returns maximum of x, y ///
    return (((x)>(y))?(x):(y));
    }

float fast_fminf(float x, float y){
    /// Returns minimum of x, y ///
    return (((x)<(y))?(x):(y));
    }

float fmaxf3(float x, float y, float z){
    /// Returns maximum of x, y, z ///
    return (x > y ? (x > z ? x : z) : (y > z ? y : z));
    }

float fminf3(float x, float y, float z){
    /// Returns minimum of x, y, z ///
    return (x < y ? (x < z ? x : z) : (y < z ? y : z));
    }

float sin_lut(float theta){
	theta = fmodf(theta,TWO_PI);
	theta = theta<0 ? theta + TWO_PI : theta;

	return sin_tab[(int)(sin_lut_mult*theta)];
}

float cos_lut(float theta){
	return sin_lut(PI_OVER_TWO - theta);
}
