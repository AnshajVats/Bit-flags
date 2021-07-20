/*
Author : Anshaj vats
Date :  10/ 03 / 2020

Effort: 8 hours

purpose : to practice data struct.

Interface proposal: I think a function to test other codes will be useful. Similar to Long_function_name we have in lab5.
that takes status as precondition and handle as post condition. It will tell you abot capacity and size. Whether they are 
what is required by the program or not.

*/








#include<stdio.h>
#include<stdlib.h>
#include "bit_flags.h"
const int BIT_PER_INT = (sizeof(int) * 8);

struct vector {

	int size;
	int capacity;
	int* data;
};
typedef struct vector Bit_flag;


// takes  number of bits and makes the size of the array into number of bits. size= number of bits.
BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits)
{
	int i;
	Bit_flag* pBit_flag;

	pBit_flag = (Bit_flag*)malloc(sizeof(Bit_flag));
	
	if (pBit_flag != NULL)
	{
		pBit_flag->size = number_of_bits;
		
		pBit_flag->capacity =number_of_bits/(BIT_PER_INT)+((number_of_bits%(BIT_PER_INT)!=0));
		pBit_flag->data = (int*)calloc(pBit_flag->capacity,sizeof(int));
		if (pBit_flag == NULL)
		{
			free(pBit_flag);
			pBit_flag = NULL;
		}
	}
	


	return(BIT_FLAGS)pBit_flag;
}

// similar to push back just does the set flag operation and if fails because of size it resizes the capacity. 
Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	Bit_flag* pBit_flag = (Bit_flag*)hBit_flags;
	int index = flag_position / (BIT_PER_INT);
	int *tmp;
	int i;
	
		// push back function
		if (index >= pBit_flag->capacity)
		{
			tmp = (int*)calloc((index + 1),sizeof(int));
			if (tmp == NULL)
			{
				return FAILURE;
			}

			for (i = 0; i < pBit_flag->capacity; i++)
			{
				tmp[i] = pBit_flag->data[i];
			}
		
			free(pBit_flag->data);
			pBit_flag->data = tmp;
			if (flag_position >= pBit_flag->size)
				pBit_flag->size = flag_position + 1;
			pBit_flag->capacity += (index + 1);
			
		
		}
		
		pBit_flag->data[index]  |= (1 << flag_position % (BIT_PER_INT));
		
		
	
	
	return SUCCESS;
}
// same to bit flag set flag function it just unsets the number.
Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	Bit_flag* pBit_flag = (Bit_flag*)hBit_flags;
	int index = flag_position / (BIT_PER_INT);
	int* tmp;
	int i;
	
	if (index >= pBit_flag->capacity)
	{
	
		tmp = (int*)calloc((index + 1),sizeof(int));
		
		if (tmp == NULL)
		{
		
			return FAILURE;
		}
		

		for (i = 0; i < pBit_flag->capacity; i++)
		{
			tmp[i] = pBit_flag->data[i];
		}
		free(pBit_flag->data);
		pBit_flag->data = tmp;
		if (flag_position >= pBit_flag->size)
			pBit_flag->size = flag_position + 1;
		pBit_flag->capacity += (index + 1);
		
		
	
	}
	
	
	pBit_flag->data[index] &= (~(1 << flag_position % (BIT_PER_INT)));


	

	return SUCCESS;






}

// function to print the bits.
int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	Bit_flag* pBit_flag = (Bit_flag*)hBit_flags;
	int index = flag_position / BIT_PER_INT;
	
	if (flag_position >= pBit_flag->size)
		return -1;

	return (pBit_flag->data[index] >> (flag_position % (BIT_PER_INT))) & 1;
}


// gets the size of the array
int bit_flags_get_size(BIT_FLAGS hBit_flags)
{
	Bit_flag* pBit_flag = (Bit_flag*)hBit_flags;
	return pBit_flag->size;
}
// gets capacity
int bit_flags_get_capacity(BIT_FLAGS hBit_flags)
{
	Bit_flag* pBit_flag = (Bit_flag*)hBit_flags;
	return pBit_flag->capacity*(BIT_PER_INT);
}
// destory and clears the memory.

void bit_flags_destory(BIT_FLAGS* phBit_flags)
{
	Bit_flag* pBit_flag = (Bit_flag*)*phBit_flags;
	
	free(pBit_flag->data);
	free(pBit_flag);
	*phBit_flags = NULL;
	printf("Destory complete");
}