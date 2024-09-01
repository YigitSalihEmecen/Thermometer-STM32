#ifndef INC_UART_READ_APP_H_
#define INC_UART_READ_APP_H_

#include "stm32l4xx_hal.h"


/**
 * @brief Reads data from the specified UART.
 *
 * This function reads data from the specified UART interface. The UART handle
 * must be properly initialized before calling this function. The function will
 * block until data is received or an error occurs.
 *
 * @param huart Pointer to a UART_HandleTypeDef structure that contains
 *              the configuration information for the specified UART module.
 * @return int  The read data as an integer value. If an error occurs, the function
 *              returns a negative value to indicate the error.
 */
int read_data(UART_HandleTypeDef *huart);

#endif /* INC_UART_READ_APP_H_ */
