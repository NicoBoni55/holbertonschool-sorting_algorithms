#include "sort.h"
/**
 * two_parts - Divide the array into two parts
 * @array: array
 * @size: size
 * @min : min
 * @max : max
 *
 * Return: position where the pivot is located
 */
int two_parts(int *array, size_t size, int min, int max)
{
	int i, j, aux, pivot = array[max];

	for (i = j = min; j < max; j++)
	{
		if (array[j] < pivot)
		{
			if (i < j)
			{
				aux = array[j];
				array[j] = array[i];
				array[i] = aux;
				print_array(array, size);
			}
		i++;
		}
	}
	if (array[i] > pivot)
	{
		aux = array[i];
		array[i] = array[max];
		array[max] = aux;
		print_array(array, size);
	}
	return (i);
}
#include "sort.h"
/**
 * _sort - using the Quick sort algorithm
 * @array: array
 * @size: size
 * @min : min
 * @max : max
 *
 * Return: nothing
 */
void _sort(int *array, size_t size, int min, int max)
{
	int mit;

	if (min < max)
	{
		mit = two_parts(array, size, min, max);
		_sort(array, size, min, mit - 1);
		_sort(array, size, mit + 1, max);
	}
}

#include "sort.h"
/**
 * quick_sort - order using the Quick sort algorithm
 * @array: array
 * @size: size
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;

	_sort(array, size, 0, size - 1);
}
