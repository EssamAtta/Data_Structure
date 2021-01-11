/*
 * main.c
 *
 *  Created on: 07.01.2021
 *      Author: atta-es
 */
#include "LIFO.h"
#include "stdio.h"
#include "stdlib.h"
unsigned int buffer1 [5];


void main (void)
{
	unsigned int temp = 0;
	LIFO_Buf_t uart_lifo, I2C_lifo;
	// Static allocation
	LIFO_init(&uart_lifo, buffer1, 5);
	// Dynamic allocation
	unsigned int* buffer2 = (unsigned int *) malloc (5*sizeof(unsigned int));
	LIFO_init(&I2C_lifo, buffer2, 5);
	for (int i=0; i<5; i++)
	{
		if ((LIFO_Add_item(&uart_lifo, i)) == LIFO_no_error )
		printf("UART_LIFO add : %d \n ", i);
	}
	for (int i=0; i<5; i++)
	{
		if (LIFO_get_item(&uart_lifo, &temp) == LIFO_no_error)
		printf("UART_LIFO add : %d \n ", temp);

	}


}

