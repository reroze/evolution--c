#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "thedefine.h"

float find_max(float swarm_guzhi[qun_number]);

float find_max(float swarm_guzhi[qun_number])
{
	float temp = 0;
	for (int i = 0; i < qun_number; i++)
	{
		if (swarm_guzhi[i] > temp)
		{
			temp = swarm_guzhi[i];
		}
	}
	return temp;
}

float find_min(float swarm_guzhi[qun_number]);

float find_min(float swarm_guzhi[qun_number])
{
	float temp = 1;
	for (int i = 0; i < qun_number; i++)
	{
		if (swarm_guzhi[i] < temp)
		{
			temp = swarm_guzhi[i];
		}
	}
	return temp;
}

float jiancha();
float jiancha()
{
	int count = 0;
	for (int i = 0; i < qun_number; i++)
	{
		if (swarm_guzhi[i] < xuanze_guzhi)
			count++;
	}
	return (1.0*count) / qun_number;
}

void guzhi_xuanze();

void guzhi_xuanze()//����ѡ����ֵ
{
	int count = 0;
	float ceshi = 0;
	max_guzhi = find_max(swarm_guzhi);//�ҵ���Ⱥ�е�����ֵ
	min_guzhi = find_min(swarm_guzhi);//�ҵ���Ⱥ�е���С��ֵ
	xuanze_guzhi = min_guzhi + (max_guzhi - min_guzhi)*rand() / (RAND_MAX);//�������һ���������С��ֵ֮���һ����ֵ
	ceshi = jiancha();//������ֵ�ĺ�����

	while (ceshi < 0.005 || ceshi>0.8)//��������Ⱥ���ҵĸı�ͳ��ڣ�δ�������Ļ�������
	{
		xuanze_guzhi = min_guzhi + (max_guzhi - min_guzhi)*rand() / (RAND_MAX);
		ceshi = jiancha();
		count++;
		//guzhi_xuanze();
		//ceshi = jiancha();
		if (count > 10000)
		{
			//xuanze_guzhi = (max_guzhi + min_guzhi) / 2;

			printf("error\n");
			printf("$%f\t", max_guzhi);
			printf("$%f\t", min_guzhi);
			printf("$%f\t", ceshi);
			cishu = count;//��δ�ﵽ�������������������������Ⱥ����ʧ�ܣ������ֵƫ�ͣ�
			printf("%d\n", count);
			break;
			//system("pause");
		}
	}
	count = 0;
	printf("\n%f\n", ceshi);
}

void swarm_xuanze();
void swarm_xuanze()//��Ȼѡ����
{
	guzhi_xuanze();
	for (int i = 0; i < qun_number; i++)
	{
		if (swarm_guzhi[i] < xuanze_guzhi)
			dead[i] = 1;//��̭����
	}
	/*for (int i = 0; i < qun_number; i++)
	{
	printf("%2d", dead[i]);
	if ((i+1) % 8 == 0 && i != 0)
	printf("\n");
	}*/
}