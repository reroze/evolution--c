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
restart://使用goto的种群淘汰措施
	restart();
	srand(time(NULL));//随机种子初始化
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

	swarm_xuanze();//进行自然选择
	printf("\n");
	for (int i = 0; i < qun_number; i++)
	{
		printf("%2d", dead[i]);//查看死亡的种群个体
		if ((i + 1) % 10 == 0)
			printf("\n");
	}
	printf("%f", xuanze_guzhi);
	max_guzhi_whole = max_guzhi;//记录本代种群的最大估值

	int count = 0;//收敛的次数
	int dai = 0;//迭代总次数
	while (count < 100)
	{
		newg();//新生代
		for (int i = 0; i<qun_number; i++)
			swarm_guzhi[i] = guzhi(swarm[i]);//更新种群估值
		swarm_xuanze();//再次自然选择
		printf("%f", xuanze_guzhi);
		if ((max_guzhi_whole - max_guzhi < 0.00001) && (max_guzhi_whole - max_guzhi>-0.00001))//如果满足收敛条件，则收敛次数+1
		{
			count++;
			printf("the %d dai is:\n:", dai);
			printf("the guzhi_now is %f the guzhi_whole is %f\n", max_guzhi, max_guzhi_whole);
			printf("$%d$", count);
		}
		if (max_guzhi > max_guzhi_whole)
			max_guzhi_whole = max_guzhi;//更新整体最大估值
		dai++;//迭代次数+1
		if (dai > max_diedai)
			break;
		if (cishu > 10000)//如果种群生成失败
		{
			cishu = 0;
			failure++;
			goto restart;//从头再来
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
					for (int h = 0; h < length; h++)//检验繁殖时是否出错
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

	printf("the max is:%f", max_guzhi_whole);//输出最优估值
	printf("the failure times is %d", failure);

	for (int i = 0; i < qun_number; i++)
	{
		if (swarm_guzhi[i] = max_guzhi)
		{
			printf("the path is ");
			for (int j = 0; j < length; j++)
			{
				printf("%2d", swarm[i][j]);//输出最优个体

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
	gailv_jiaocha = 1.0;
	gailv_bianyi = 1.0;
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