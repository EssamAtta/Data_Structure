/*
 * fifo_cir.c
 *
 *  Created on: 07.01.2021
 *      Author: atta-es
 */
#include "fifo_cir.h"
#ifndef NULL
#define NULL   ((void *) 0)
#endif


FIFO_Buf_Status FIFO_init (FIFO_Buf_t* fifo, unsigned char* buff, uint32_t size)
{
	if (buff == NULL )
		return FIFO_null;
	fifo->base = buff;
	fifo-> head= fifo->base;
	fifo -> tail= fifo->base;
	fifo ->length= size;
	fifo -> count = 0;
	return FIFO_no_error;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
FIFO_Buf_Status FIFO_enqueue (FIFO_Buf_t* fifo, element_type item )
{
	if (!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;
	if (FIFO_is_FULL(&fifo) == FIFO_full)
		return FIFO_full;
	*(fifo-> head) = item;
	fifo-> count ++ ;

	// CIRCULAR check FIFO
	if ( fifo->head == (fifo->base + (fifo->length * sizeof(element_type))))
		fifo ->head = fifo->base;
	else
		fifo->head++;
	return FIFO_no_error;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
FIFO_Buf_Status FIFO_dequeue (FIFO_Buf_t* fifo, element_type* item)
{
	if (!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;
	if (fifo-> count == 0)
		return FIFO_empty;
	*item = *(fifo->tail);
	fifo->count --;
	if ( fifo->tail  == (fifo->base + (fifo->length * sizeof(element_type))))
		fifo ->tail = fifo->base;
	else
		fifo->tail++;
	return FIFO_no_error;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
FIFO_Buf_Status FIFO_is_FULL (FIFO_Buf_t* fifo )
{
	if (!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;
	if (fifo-> count == fifo->length)
		return FIFO_full;
	else
		return FIFO_no_error;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void FIFO_print(FIFO_Buf_t* fifo)
{
	element_type*  temp;
	int i;
	if (fifo->count == 0)
		printf("FIFo is empty \n");
	else
	{
		temp = fifo->tail;

		printf("\n =======fifo_print=========\n");

		for (i=0; i<fifo->count; i++)
		{
			printf("\t %X \n", *temp);
			temp++;
		}
	}

}
