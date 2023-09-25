#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 *               using the Quick Sort algorithm (Lomuto partition scheme).
 * @array: The array of integers to be sorted.
 * @size: The number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	return; /* no sorting needed if array is empty*/

	quick_sort_recursive(array, 0, size - 1);
}

/**
 * quick_sort_recursive - Recursive function to perform the  Quick Sort.
 * @array: The array of integers to be sorted.
 * @low: The low index of the subarray.
 * @high: The high index of the subarray.
 */
void quick_sort_recursive(int *array, int low, int high)
{
	if (low < high)
	{
		int pivot = lomuto_partition(array, low, high);

		/* Recursively sorts the subarrays on either side of the pivot*/
		quick_sort_recursive(array, low, pivot - 1);
		quick_sort_recursive(array, pivot + 1, high);
	}
}

/**
 * lomuto_partition - Partitions the array using the Lomuto partition scheme.
 * @array: The array of integers to be partitioned.
 * @low: The low index of the subarray.
 * @high: The high index of the subarray.
 *
 * Return: The index of the pivot element after partitioning os dpne.
 */
int lomuto_partition(int *array, int low, int high)
{
	int j, temp;
	int pivot = array[high]; /* Choosing the last element as the pivot*/
	int i = low - 1; /* Index of the smaller element*/

	for ( j = low; j < high; j++)
	{
		/* If the current element is smaller or equal to the pivot*/
		if (array[j] <= pivot)
		{
			i++;
			/* Swap array[i] and array[j]*/
			temp = array[i];

			array[i] = array[j];
			array[j] = temp;
			print_array(array, high - low + 1);
		}
	}

	/* Swap array[i + 1] and the pivot (array[high])*/
	temp = array[i + 1];

	array[i + 1] = array[high];
	array[high] = temp;
	print_array(array, high - low + 1);

	return (i + 1);
}
