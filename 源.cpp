/*
函数：
1.种群初始化 ok
2.新生代种群
3.交换
4.变异
5.选择 ok
6.适应计算 ok
7.城市距离导入 ok
*/

/*
元素：
1.最大迭代次数
2.最强壮个体
3.


*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "init_first.h"
#include "thedefine.h"
#include "guzhi.h"
#include "xuanze.h"
#include "newgene.h"
int failure = 0;

void restart();

void main()
{
	int times = 0;
restart:
	restart();
	srand(time(NULL));
	/*for (int j = 0; j < 10; j++)
	{

	int i = rand()%14;
	printf("%d\t", i);
	}*/
	init();//初始化
	for (int i = 0; i < qun_number; i++)
	{
		swarm_guzhi[i] = guzhi(swarm[i]);//初始化 种群权值
		printf("\n$%f$\n", swarm_guzhi[i]);
		for (int j = 0; j < length; j++)
		{
			printf("%3d", swarm[i][j]);
		}
		printf("\n");
	}

	swarm_xuanze();
	printf("\n");
	for (int i = 0; i < qun_number; i++)
	{
		printf("%2d", dead[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}
	printf("%f", xuanze_guzhi);
	max_guzhi_whole = max_guzhi;

	int count = 0;
	int dai = 0;
	while (count < 100)
	{
		newg();
		for (int i = 0; i<qun_number; i++)
			swarm_guzhi[i] = guzhi(swarm[i]);
		swarm_xuanze();
		printf("%f", xuanze_guzhi);
		if ((max_guzhi_whole - max_guzhi < 0.00001) && (max_guzhi_whole - max_guzhi>-0.00001))
		{
			count++;
			printf("the %d dai is:\n:", dai);
			printf("the guzhi_now is %f the guzhi_whole is %f\n", max_guzhi, max_guzhi_whole);
			printf("$%d$", count);
		}
		if (max_guzhi > max_guzhi_whole)
			max_guzhi_whole = max_guzhi;
		dai++;
		if (dai > max_diedai)
			break;
		if (cishu > 10000)
		{
			cishu = 0;
			failure++;
			goto restart;
		}

		for (int i = 0; i < qun_number; i++)
		{
			for (int j = 0; j < length; j++)
			{
				for (int k = 0; k < length; k++)
				{
					if (swarm[i][k] == j)
						times++;
				}
				if (times != 1)
				{
					printf("error stop");
					printf("the %d is wrong", i);
					for (int h = 0; h < length; h++)
						printf("$%d$", swarm[i][h]);
					system("pause");
				}
				times = 0;
			}
		}
	}
	printf("\n");
	for (int i = 0; i < qun_number; i++)
	{
		printf("%2d", dead[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}
	printf("%f", xuanze_guzhi);

	printf("the max is:%f", max_guzhi_whole);
	printf("the failure times is %d", failure);

	for (int i = 0; i < qun_number; i++)
	{
		if (swarm_guzhi[i] = max_guzhi)
		{
			printf("the path is ");
			for (int j = 0; j < length; j++)
			{
				printf("%2d", swarm[i][j]);

			}
			break;
		}
	}

	system("pause");

}

void restart()
{
	max_guzhi = 0;
	min_guzhi = 0;
	xuanze_guzhi = 0;
	gailv_jiaocha = 0.6;
	gailv_bianyi = 0.1;
	max_guzhi_whole = 0;
	
	for (int i = 0; i < qun_number; i++)
	{
		for (int j = 0; j < length; j++)
		{
			newge[i][j] = { 0 };
			//cities[length][2] = { { 1,1 },{ 2,2 },{ 3,3 },{ 1,3 },{ 2,3 },{ 5,6 },{ 8,7 },{ 9,4 },{ 5,3 },{ 4,7 },{ 5,5 },{ 4,9 },{ 7,1 },{ 6,7 } };//初始化城市坐标
			swarm[i][j] = { 0 };//初始化种群
		}
	}
	for (int i = 0; i < qun_number; i++)
	{
		swarm_guzhi[i] = { 0 };
		dead[i] = { 0 };
	}

}