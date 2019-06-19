#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "thedefine.h"

float oushijuli(float a[2], float b[2]);

float oushijuli(float a[2], float b[2])//计算路线走上相邻两城市的欧式距离
{
	float result = 0;
	result = sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
	return result;
}

float guzhi(int path[length])//计算个体估值
{
	float juli = 0;
	for (int i = 0; i < length-1; i++)
	{
		juli = juli + oushijuli(cities[path[i]], cities[path[i + 1]]);
	}
	juli = juli + oushijuli(cities[path[length - 1]], cities[path[0]]);//计算一条回录上的总距离
	juli = (1 / juli);//距离越短越好，故而取倒数
	return juli;
}