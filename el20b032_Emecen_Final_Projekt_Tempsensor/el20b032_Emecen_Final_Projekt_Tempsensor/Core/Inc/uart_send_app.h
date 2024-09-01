/*
 * uart_send_app.h
 *
 *  Created on: May 24, 2024
 *      Author: yigit
 */
#include "stm32l4xx_hal.h"

#ifndef INC_UART_SEND_APP_H_
#define INC_UART_SEND_APP_H_


/**
 * @brief Transmits a null-terminated string via UART.
 *
 * This function transmits a null-terminated string via the specified UART interface.
 * The UART handle must be properly initialized before calling this function.
 *
 * @param huart Pointer to a UART_HandleTypeDef structure that contains
 *              the configuration information for the specified UART module.
 * @param str Pointer to the null-terminated string to be transmitted.
 */
void transmit_string(UART_HandleTypeDef *huart, char *str);


#endif /* INC_UART_SEND_APP_H_ */
