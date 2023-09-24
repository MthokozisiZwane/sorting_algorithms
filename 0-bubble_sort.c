#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers
 * in ascending order using Bubble Sort.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swap_count;

	for (i = 0; i < size - 1; i++)
	{
		swap_count = 0; /* no swapping has occured at the deginning*/

		for (j = 0; j < size - i - 1; j++)
		{
			/* Compares adjacent elements and swaps if needed*/
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap_count = 1; /* Sets swap_count to 1 to indicate a swap occurred*/
				print_array(array, size); /* Prints the array afterevery swap*/
			}
		}

	/* If no swaps occurred in this pass, the array is already sorted*/
	if (swap_count == 0)
		break;
	}
}

