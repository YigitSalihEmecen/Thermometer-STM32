/*
 * LED_Controller.h
 *
 *  Created on: Jun 10, 2024
 *      Author: yigit
 */

#ifndef INC_LED_CONTROLLER_H_
#define INC_LED_CONTROLLER_H_

void set_modes_from_datasheet_MATRIX();
void set_degree_symbol();
void set_number(int, int);
void set_led(uint8_t col, uint8_t row);

#endif /* INC_LED_CONTROLLER_H_ */
