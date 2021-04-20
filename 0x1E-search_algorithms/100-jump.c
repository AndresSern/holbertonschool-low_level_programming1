#include "search_algos.h"
#include <math.h>
/**
 * jump_search - function that searches for a value in a sorted array of
 *                 integers using the Binary search algorithm
 *
 * @array:  is a pointer to the first element of the array to search in
 * @size:   is the number of elements in array
 * @value:  is the value to search for
 *
 * Return:  Must return the index where value is located
 *          If value is not present in array or if array is NULL,
 *          your function must return -1
 */
int jump_search(int *array, size_t size, int value)
{
	size_t low = 0, i = 0, high = 3;

	if (array == NULL)
		return (-1);
	size = size - 1;
	while (high <= size || low <= size)
	{
		printf("Value checked array[%li] = [%li]\n", low, low);

		if (value <= array[high] || high > size)
		{

			printf("Value found between indexes [%li] and [%li]\n",
				low, high);
			i = low;
			while (i <= size || i <= high)
			{
				printf("Value checked array[%li] = [%d]\n", i,
					array[i]);

				if (array[i] == value)
					return (i);
				if (array[i] > value)
					return (-1);
				if (i == size || i == high)
					return (-1);
				i++;
			}
		}
		low = high;
		high = high + sqrt(size);
	}
	return (-1);
}
