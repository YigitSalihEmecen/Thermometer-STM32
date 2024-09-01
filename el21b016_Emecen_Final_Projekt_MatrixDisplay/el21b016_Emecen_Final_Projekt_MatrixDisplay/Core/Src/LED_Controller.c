/*
 * numbers_and_stuff.c
 *
 *  Created on: June 4, 2024
 *  Author: Yigit Salih Emecen
 */

#include <main.h>
#include "LED_Controller.h"

extern SPI_HandleTypeDef hspi1;

extern uint8_t tx_data[2];

uint8_t leftDigit[10][7] =
{
	7, 5, 5, 5, 5, 5, 7, //0
	7, 2, 2, 2, 2, 3, 2, //1
	7, 1, 1, 7, 4, 4, 7, //2
	7, 4, 4, 7, 4, 4, 7, //3
	4, 4, 4, 7, 5, 5, 5, //4
	7, 4, 4, 7, 1, 1, 7, //5
	7, 5, 5, 7, 1, 1, 7, //6
	4, 4, 4, 4, 4, 4, 7, //7
	7, 5, 5, 7, 5, 5, 7, //8
	7, 4, 4, 7, 5, 5, 7, //9
};

void set_modes_from_datasheet_MATRIX ()
{


	  tx_data[0] = 0x09;
	  tx_data[1] = 0x00;

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
	  HAL_Delay(1);

	  HAL_SPI_Transmit(&hspi1, tx_data, 2, 2);

	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);

	  tx_data[0] = 0x0A;
	  tx_data[1] = 0x09;

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
	  HAL_Delay(1);

	  HAL_SPI_Transmit(&hspi1, tx_data, 2, 2);

	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);

	   tx_data[0] = 0x0B;
	   tx_data[1] = 0x07;

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
	  HAL_Delay(1);

	  HAL_SPI_Transmit(&hspi1, tx_data, 2, 2);

	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);

	  tx_data[0] = 0x0C;
	  tx_data[1] = 0x01;

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
	  HAL_Delay(1);

	  HAL_SPI_Transmit(&hspi1, tx_data, 2, 2);

	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);

	  tx_data[0] = 0x0F;
	  tx_data[1] = 0x00;



	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
	  HAL_Delay(1);

	  HAL_SPI_Transmit(&hspi1, tx_data, 2, 2);

	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);



}

void set_degree_symbol()
{
	set_led (7,128); //achtes bit der linken Zahl
}

void set_number(int first, int second)
{
	int annen[10][7];

	for (int i = 0; i < 7; i++)
	{
		annen[second][i] = leftDigit[second][i] << 4;
		set_led(i, leftDigit[first][i] + annen[second][i]);
	}
}

void set_led (uint8_t col, uint8_t row)
{
	 tx_data[0] = col + 1; //Reihe der Matrix von 0 bis 7 decimal
	 tx_data[1] = row; //Spalte der Matrix diese ist in decimal to bit anzuschreiben von 0 bis 255


	 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
	 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
	 HAL_Delay(1);

	 HAL_SPI_Transmit(&hspi1, tx_data, 2, 2);

	 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);
}



