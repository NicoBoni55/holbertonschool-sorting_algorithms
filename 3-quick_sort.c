#include "sort.h"
/**
 * twoparts - Divide the array into two parts
 * @array: array
 * @size: size
 * @min : min
 * @max : max
 *
 * Return: position where the pivot is located
 */
int two_parts(int *array, size_t size, int min, int max)
{
	int i, j, aux, pivot = max;

	i = (min - 1);

	for (j = min; j <= max - 1; j++)
	{
		if (array[j] < pivot)
                {
			i++;
			aux = array[i];
                        array[i] = array[j];
			array[j] = aux;
			print_array(array, size);
                }
	}
	aux = array[i + 1];
	array[i + 1] = array[max];
	array[max] = aux;
	print_array(array, size);

	return (i);
}
#include "sort.h"
/**
 * quick_sort - order using the Quick sort algorithm
 * @array: array
 * @size: size
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
