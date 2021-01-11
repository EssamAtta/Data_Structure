/*
 * LIFO.h
 *
 *  Created on: 07.01.2021
 *      Author: atta-es
 */

#ifndef LIFO_H_
#define LIFO_H_

// type definitions
typedef struct LIFO_Buf{
	unsigned int length;
	unsigned int count;
	unsigned int *base;
	unsigned int *head;

}LIFO_Buf_t;

typedef enum{

	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_NULL
}LIFO_status;

// APIs

LIFO_status LIFO_Add_item (LIFO_Buf_t* LIFO_buf, unsigned int item);
LIFO_status LIFO_get_item (LIFO_Buf_t* LIFO_buf, unsigned int* item);
LIFO_status LIFO_init (LIFO_Buf_t* LIFO_buf, unsigned int* buf, unsigned int size);


#endif /* LIFO_H_ */
