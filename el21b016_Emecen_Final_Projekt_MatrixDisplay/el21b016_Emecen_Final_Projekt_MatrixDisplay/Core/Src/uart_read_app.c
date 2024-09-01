#include "uart_read_app.h"
#include "stm32l4xx_hal.h"
#include "conversions.h"

extern UART_HandleTypeDef huart2;


/**
 * @brief Reads data from the specified UART.
 *
 * This function reads data from the specified UART interface. The UART handle
 * must be properly initialized before calling this function. The function will
 * block until data is received or an error occurs.
 *
 * @param huart Pointer to a UART_HandleTypeDef structure that contains
 *              the configuration information for the specified UART module.
 * @return int  The read data as an integer value representing the percentage.
 *              If an error occurs or the input is out of range, the function
 *              returns 0.
 */
int read_data(UART_HandleTypeDef *huart)
{
    char buffer[4] = {0}; // Buffer to hold the input string (max 3 digits + null terminator)
    char c;
    int idx = 0;

    // Read characters until a newline is received
    while (1) {
        HAL_UART_Receive(huart, (uint8_t*)&c, 1, HAL_MAX_DELAY);

        if (c == '\r' || c == '\n')
        {
            // Newline or carriage return detected, end of input
            break;
        }

        else if (c == '\b' && idx > 0)
        {
            // Handle backspace
            idx--;
            buffer[idx] = '\0';
        }

        else if (c >= '0' && c <= '9' && idx < 3)
        {
            // Valid digit, store it in the buffer
            buffer[idx++] = c;
        }
    }

    // Null-terminate the input string
    buffer[idx] = '\0';

    // Convert the string to an integer
    int percentage = 0;
    for (int i = 0; buffer[i] != '\0'; i++) {
        percentage = percentage * 10 + (buffer[i] - '0');
    }

    // Ensure the percentage is within 0-100
    if (percentage > 100) {
        percentage = 100;
    }

    return percentage;
}
