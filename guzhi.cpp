#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "thedefine.h"

float oushijuli(float a[2], float b[2]);

float oushijuli(float a[2], float b[2])
{
	float result = 0;
	result = sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
	return result;
}

float guzhi(int path[length])
{
	float juli = 0;
	for (int i = 0; i < length-1; i++)
	{
		juli = juli + oushijuli(cities[path[i]], cities[path[i + 1]]);
	}
	juli = juli + oushijuli(cities[path[length - 1]], cities[path[0]]);
	juli = (1 / juli);
	return juli;
}