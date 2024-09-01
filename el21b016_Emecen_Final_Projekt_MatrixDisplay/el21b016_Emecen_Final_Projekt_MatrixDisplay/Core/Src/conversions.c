#include "conversions.h"

/**
 * @brief Converts an integer to a string.
 *
 * This function converts an integer value to a null-terminated string.
 * It handles negative numbers by prefixing the string with a minus sign.
 *
 * @param num The integer value to be converted.
 * @param str The buffer where the converted string will be stored. It should be large enough to hold the resulting string.
 */
void int_to_string(int num, char* str)
{
    // Handle negative numbers
    if (num < 0)
    {
        *str++ = '-';
        num *= -1;
    }

    // Convert each digit to a character and store it in the string
    int temp = num;
    int length = 0;
    do {
        ++length;
        temp /= 10;
    } while (temp);


    str[length] = '\0';

    while (num)
    {
        str[--length] = '0' + (num % 10); // Convert digit to character
        num /= 10; // Move to the next digit
    }
}


/**
 * @brief Converts a float to a string.
 *
 * This function converts a floating-point value to a null-terminated string.
 * It handles negative numbers by prefixing the string with a minus sign.
 * The function extracts both the integer and fractional parts of the float
 * and converts them to string format.
 *
 * @param num The floating-point value to be converted.
 * @param str The buffer where the converted string will be stored. It should be large enough to hold the resulting string.
 */
void float_to_string(float num, char *str)
{
    // Handle negative numbers
    if (num < 0) {
        *str++ = '-';
        num = -num;
    }

    // Extract integer part
    int integer_part = (int)num;

    // Check if integer part is zero
    if (integer_part == 0)
    {
        *str++ = '0';
    }

    else
    {
        // Convert integer part to string
        int_to_string(integer_part, str);

        // Move to the end of the string
        while (*str != '\0')
        {
            str++;
        }
    }

    // Add decimal point
    *str++ = '.';

    // Extract fractional part and convert it to string
    float fractional_part = num - integer_part;
    int fractional_digits = 2; // Number of decimal places
    for (int i = 0; i < fractional_digits; i++)
    {
        fractional_part *= 10;
        int digit = (int)fractional_part;
        *str++ = '0' + digit;
        fractional_part -= digit;
    }

    *str++ = '\n';
    // Terminate the string
    *str = '\0';
}
