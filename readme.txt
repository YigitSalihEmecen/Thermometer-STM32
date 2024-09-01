# Embedded Systems Final Project

## Project Overview

This project involves two microcontrollers, a temperature sensor, and an 8x8 LED matrix display. The temperature sensor reads data, which is then sent to the second microcontroller using UART. The data is processed and displayed on the LED matrix.

**Microcontrollers:**
- Microcontroller 1: Temperature sensor data acquisition and UART transmission.
- Microcontroller 2: UART reception and LED matrix display control.

## Project Files

The project consists of two separate files for each microcontroller, located in the same directory as this README:

- **Temperature Sensor Code**: `el20b032_Emecen_Final_Projekt_Tempsensor.zip`
- **Matrix Display Code**: `el21b016_Emecen_Final_Projekt_MatrixDisplay.zip`

## Setup Instructions

### 1. Temperature Sensor Configuration

1. Connect the temperature sensor to the shield's port **"2"**.
2. Upload the temperature sensor code to the microcontroller.

### 2. LED Matrix Display Configuration

We opted not to use the shield for the LED matrix; instead, we used jumper cables for necessary connections. Make the following connections:

| Microcontroller Pin | Function        | LED Matrix Pin |
|---------------------|-----------------|----------------|
| PA_7                | SPI1_MOSI       | A6             |
| PB_1                | GPIO_Output     | D6             |
| PA_1                | SPI1_SCK        | A1             |
| 5V                  | Power Supply    | 5V             |
| GND                 | Ground          | GND            |

3. Upload the matrix display code to the microcontroller.
4. Connect the GNDs of both boards and cross-connect the TX and RX pins between the boards using jumper wires.

### 3. Final Steps

After completing the setup, reset the microcontroller responsible for the LED matrix display. The matrix should now display the temperature readings.

## Code Overview

### Temperature Sensor

The temperature sensor code is organized into two tasks:

- **StartTempTask**: Sends commands to the sensor and reads temperature data.
- **TransmitTask**: Converts the sensor data into a string format and transmits it to the second microcontroller via UART.

These tasks use queues to ensure that data transmission occurs only when there is a new reading from the sensor.

### LED Matrix Display

The LED matrix display code also includes two tasks:

- **receiveUARTstart**: Receives data from UART.
- **showNumberStart**: Displays the received data on the LED matrix.

These tasks use queues to ensure that the temperature is displayed only when new data is received from UART. The code includes a detailed `LED_Controller` script, which handles the display of numbers on the matrix. The shapes of the numbers are hardcoded but can be easily modified.

## Libraries

Custom libraries were used for conversions and UART communication. Ensure that all dependencies are correctly included in your project setup.
