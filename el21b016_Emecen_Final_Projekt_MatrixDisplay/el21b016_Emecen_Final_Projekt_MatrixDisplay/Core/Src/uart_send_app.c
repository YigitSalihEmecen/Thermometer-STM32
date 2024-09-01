
#include "uart_send_app.h"
#include "stm32l4xx_hal.h"

#include "main.h"

extern UART_HandleTypeDef huart2;

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
void transmit_string(UART_HandleTypeDef *huart, char *str)
{
    // Loop through each character in the string
    while (*str != '\0')
    {
        // Transmit the character using HAL_UART_Transmit
        HAL_UART_Transmit(huart, (uint8_t *)str, 1, HAL_MAX_DELAY);


        // Move to the next character
        str++;
    }

}



