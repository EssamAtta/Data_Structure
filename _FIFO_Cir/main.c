/*
 * main.c
 *
 *  Created on: 07.01.2021
 *      Author: atta-es
 */

#include "fifo_cir.h"
void main  ()
{
	FIFO_Buf_t FIFO_UART;
	element_type i, temp;
	if (FIFO_init(& FIFO_UART ,uart_buffer, 5 ) == FIFO_no_error)
		printf("\t fifo init ---------Done \n");

	for(i=0; i<7 ; i++)
	{
		printf("FIFO Enqueue (%x) \n", i);
		if (FIFO_enqueue(&FIFO_UART, i) == FIFO_no_error)
			printf("\t fifo enqueue(%x) ---------Done\n", i);
		else
			printf("\t fifo enqueue (%x) ---------failed\n",i);
	}

	FIFO_print(&FIFO_UART);
	if (FIFO_dequeue(&FIFO_UART, &temp) == FIFO_no_error)
		printf("\t fifo denqueue %x ---------Done\n", temp);

	if (FIFO_dequeue(&FIFO_UART, &temp) == FIFO_no_error)
		printf("\t fifo denqueue %x ---------Done\n", temp);
	for(i=0; i<2 ; i++)
		{
			printf("FIFO Enqueue (%x) \n", i);
			if (FIFO_enqueue(&FIFO_UART, i) == FIFO_no_error)
				printf("\t fifo enqueue(%x) ---------Done\n", i);
			else
				printf("\t fifo enqueue (%x) ---------failed\n",i);
		}


	FIFO_print(&FIFO_UART);

}
