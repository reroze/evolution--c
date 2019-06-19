#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "thedefine.h"

void init()//初始化种群
{
	for (int i = 0; i < length; i++)
		swarm[0][i] = i;
	for (int i = 1; i < qun_number; i++)
	{
		for (int k = 0; k < length; k++)
			swarm[i][k] = swarm[0][k];
		int temp = 0;
		int left = 0;
		int right = 0;
		for (int j = 0; j < 5; j++)
		{
			left = rand() % length;
			right = rand() % length;
			temp = swarm[i][left];
			swarm[i][left] = swarm[i][right];//随机交换5个值作为新个体
			swarm[i][right] = temp;
		}
	}

}