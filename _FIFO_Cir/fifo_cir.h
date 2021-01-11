/*
 * fifo_cir.h
 *
 *  Created on: 07.01.2021
 *      Author: atta-es
 */

#ifndef FIFO_CIR_C_
#define FIFO_CIR_C_
#include "stdio.h"
#include "stdint.h"

// USER Configuration
// select the element type (uint8_t, uint16_t, uint32_t, ....)

#define element_type uint8_t
//create buffer
#define width 5
element_type uart_buffer [width]; // global varaible
// type definition
typedef struct {
	element_type* base;
	element_type* head; // for writing
	element_type* tail; // for removing
	unsigned int count;
	unsigned int length;
}FIFO_Buf_t;

typedef enum {
FIFO_no_error,
FIFO_full,
FIFO_empty,
FIFO_null
}FIFO_Buf_Status;

// APIs
FIFO_Buf_Status FIFO_init (FIFO_Buf_t* fifo, unsigned char* buff, uint32_t size); // BUFFER initialization
FIFO_Buf_Status FIFO_enqueue (FIFO_Buf_t* fifo, element_type item ); // adding data fuction
FIFO_Buf_Status FIFO_dequeue (FIFO_Buf_t* fifo, element_type* item);  // Removing data function
FIFO_Buf_Status FIFO_is_FULL (FIFO_Buf_t* fifo );
void FIFO_print(FIFO_Buf_t*fifo);



#endif /* LIFO_CIR_C_ */
