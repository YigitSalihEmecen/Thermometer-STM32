/*
 * int_to_string_app.h
 *
 *  Created on: May 24, 2024
 *      Author: yigit
 */

#ifndef INC_CONVERSIONS_H_
#define INC_CONVERSIONS_H_

/**
 * @brief Converts an integer to a string.
 *
 * This function converts an integer value to a null-terminated string.
 *
 * @param value The integer value to be converted.
 * @param str The buffer where the converted string will be stored. It should be large enough to hold the resulting string.
 */
void int_to_string(int , char*);

/**
 * @brief Converts a float to a string.
 *
 * This function converts a floating-point value to a null-terminated string.
 *
 * @param value The floating-point value to be converted.
 * @param str The buffer where the converted string will be stored. It should be large enough to hold the resulting string.
 */
void float_to_string(float, char*);

#endif /* INC_CONVERSIONS_H_ */
