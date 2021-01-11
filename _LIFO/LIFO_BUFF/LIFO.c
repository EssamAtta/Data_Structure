/*
 * LIFO.c
 *
 *  Created on: 07.01.2021
 *      Author: atta-es
 */

#ifndef NULL
#define NULL   ((void *) 0)
#endif
#include "LIFO.h"

// APIs

LIFO_status LIFO_Add_item (LIFO_Buf_t* LIFO_buf, unsigned int item){
	// LIFO validity (exisit or not)
	if (!LIFO_buf->base || !LIFO_buf->head)
		return LIFO_NULL;

	// Check LIFO full
	// if (LIFO_buf->head >= (LIFO_buf->base +(LIFO_buf->length * 4 )))
	if (LIFO_buf->length == LIFO_buf->count)
		return LIFO_full;
	// ADD value
	*( LIFO_buf->head) = item;
	LIFO_buf->head ++ ;
	LIFO_buf->count ++ ;
	return LIFO_no_error;

}
LIFO_status LIFO_get_item (LIFO_Buf_t* LIFO_buf, unsigned int* item){
	// LIFO validity (exisit or not)
	if (!LIFO_buf->base || !LIFO_buf->head)
		return LIFO_NULL;
	// check if LIFO has DATA or not
	if (LIFO_buf->count == 0)
		return LIFO_empty;

	LIFO_buf->head -- ;
	*item = *(LIFO_buf->head);
	LIFO_buf->count -- ;
	return LIFO_no_error;


}
LIFO_status LIFO_init (LIFO_Buf_t* LIFO_buf, unsigned int* buf, unsigned int size){

	if (buf == NULL )
		return LIFO_NULL;

	LIFO_buf ->base = buf;
	LIFO_buf ->head = buf;
	LIFO_buf ->length = size;
	LIFO_buf ->count = 0;
	return LIFO_no_error;


}

