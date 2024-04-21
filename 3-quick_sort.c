#include "sort.h"

/**
 *swap - function that swaps two intergers in an array.
 *@a: first integer
 *@b: secon integer
 */

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - scheme for quicksort.
 * @array: array to be sorted
 * @a: starting index of the partition
 * @b: ending index of the partition
 * @size: size of the array
 *
 * Return: index of the pivot
 */

int lomuto_partition(int *array, int a, int b, size_t size)
{
	int pivot = array[b];
	int i = a - 1;
	int j;

	for (j = a; j <= b - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[b])
	{
		swap(&array[i + 1], &array[b]);
		print_array(array, size);
	}
	return (i + 1);
}


/**
 * quicksort - recursive function to perform quicksort
 * @array: array to be sorted
 * @a: starting index of the partition
 * @b: ending index of the partition
 * @size: size of the array
 */

void quicksort(int *array, int a, int b, size_t size)
{
	int pi;

	if (a < b)
	{
		pi = lomuto_partition(array, a, b, size);

		quicksort(array, a, pi - 1, size);
		quicksort(array, pi + 1, b, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using Quick sort
 * @array: array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	 quicksort(array, 0, size - 1, size);
}

