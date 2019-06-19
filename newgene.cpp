#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "thedefine.h"

int *f = NULL;
int *m = NULL;

int jiancha_new(int mu, int new_now[length]);
int jiancha_new(int mu, int new_now[length])
{
	for (int i = 0; i < length; i++)
	{
		if (i % 2 == 0)
		{
			if (mu == new_now[i])
				return 0;
		}
	}
	return 1;
}

void zhengchang(int fu[length], int mu[length], int new_now[length]);
void zhengchang(int fu[length], int mu[length], int new_now[length])//正常繁殖
{
	
	for (int i = 0; i < length; i++)
	{
		if (i % 2 == 0)//将偶数位的染色体遗传给子代
		{
			new_now[i] = fu[i];
		}
	}
	int mu_zuobiao = 0;
	int panduan = 0;
	for (int i = 0; i < length; i++)
	{
		if (i % 2 != 0)//在母亲的性状中，将父亲没有遗传的染色体按照其在母亲染色体组中出现的顺序遗传给子代，从而保证子代的染色体不重复
		{
			while (1)
			{
				if (jiancha_new(mu[mu_zuobiao], new_now) == 1)//该位对应的染色体父亲未传给子代
				{
					new_now[i] = mu[mu_zuobiao];
					panduan = 1;
				}
				mu_zuobiao++;
				if (panduan == 1)
					break;
			}
			panduan = 0;
		}
	}
	mu_zuobiao = 0;

}



void chachong(int one[length], int zuobiao[length]);
void chachong(int one[length], int zuobiao[length])
{
	int count = 0;
	int record1 = 0;
	int record2 = 0;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (one[j] == i && count == 1)
			{
				record2 = j;
				count++;
			}
			if (one[j] == i && count == 0)
			{
				record1 = j;
				count++;
			}
			if (count == 2)//同一个i出现了两次，为重复染色体
			{
				count = 0;
				zuobiao[record1] = 1;
				break;
			}
		}
		count = 0;
	}
}


void jiaocha(int fu_now[length], int mu_now[length]);
void jiaocha(int fu_now[length], int mu_now[length])//交叉函数
{
	int temp = 0;
	int left = 0;
	int zuobiao_fu[length]= { 0 };
	int zuobiao_mu[length] = { 0 };
	int right = length-1;
	while ((right - left > 4) || (right - left<0))//随机选择4个连续的染色体
	{
		left = length * rand() / (RAND_MAX);
		right = length * rand() / (RAND_MAX);
		if (right == length)
			right--;
		if (left == length)
			left--;
	}
	for (int i = left; i <= right; i++)//进行交换
	{
		temp = fu_now[i];
		fu_now[i] = mu_now[i];
		mu_now[i] = temp;
		temp = 0;
	}
	chachong(fu_now, zuobiao_fu);//得到父亲中重复染色体的位置（靠左边）
	chachong(mu_now, zuobiao_mu);//得到母亲中重复染色体的位置（靠左边）
	int mu_zuo = 0;
	int panduan = 0;
	for (int i = 0; i < length; i++)//易知父母重复的数字数目一致，将父母重复的染色体再进行更换
	{
		if (zuobiao_fu[i] == 1)
		{
			while(1)
			{
				if (zuobiao_mu[mu_zuo] == 1)
				{
					temp = fu_now[i];
					fu_now[i] = mu_now[mu_zuo];
					mu_now[mu_zuo] = temp;
					panduan = 1;
				}
				mu_zuo++;
				if (panduan == 1)
					break;
			}
			panduan = 0;
			
		}
	
	}

}

void bianyi(int new_now[length]);
void bianyi(int new_now[length])//随机挑取两个染色体位置互换
{
	int left = length * rand() / (RAND_MAX);
	int right = length * rand() / (RAND_MAX);
	if (left == length)
		left--;
	if (right == length)
		right--;
	int temp = 0;
	temp = new_now[left];
	new_now[left] = new_now[right];
	new_now[right] = temp;
}

void fanzhi(int fu[length], int mu[length], int new_now[length]);
void fanzhi(int fu[length], int mu[length], int new_now[length])
{
	int fu_now[length] = { 0 };//备份父亲性状
	for (int i = 0; i < length; i++)
		fu_now[i] = fu[i];
	int mu_now[length] = { 0 };//备份母亲性状
	for (int i = 0; i < length; i++)
		mu_now[i] = mu[i];

	f = fu_now;
	m = mu_now;

	float jiaocha_gailv_now =1.0*rand() / (RAND_MAX);//生成交叉概率
	//jiaocha_gailv_now = 0;
	float bianyi_gailv_now = 1.0*rand() / (RAND_MAX);//生成变异概率
	//bianyi_gailv_now = 0;
	if (jiaocha_gailv_now < gailv_jiaocha)
	{
		jiaocha(fu_now, mu_now);//交叉互换父母性状
		zhengchang(fu_now, mu_now, new_now);//进行繁殖
	}
	else {
		zhengchang(fu_now, mu_now, new_now);
	}
	if (bianyi_gailv_now < gailv_bianyi)
	{
		bianyi(new_now);//新个体变异
	}
}

void newg()//新生代函数
{
	int fu = 0;
	int mu = 0;
	for (int i = 0; i < qun_number; i++)
	{
		if (dead[i] == 1)//若此个体被淘汰
		{
			while (fu == mu)//无法自交
			{
				fu = 100 * rand() / (RAND_MAX);
				while (dead[fu] == 1)//保证父亲是活的
					fu = 100 * rand() / (RAND_MAX);
				mu = 100 * rand() / (RAND_MAX);
				while (dead[mu] == 1)//保证母亲还活着
					mu = 100 * rand() / (RAND_MAX);
			}//挑选新个体的父母
			fanzhi(swarm[fu], swarm[mu], newge[i]);//繁殖函数
			fu = 0;
			mu = 0;
		}
	}
	for (int i = 0; i<qun_number; i++)
	{
		if (dead[i] == 1)
		{
			for (int j = 0; j < length; j++)
			{
				swarm[i][j] = newge[i][j];//将种群中死去的个体由新生代替换
				newge[i][j] = 0;//归0新生代
			}
			dead[i] = 0;//该个体状态变为活
		}
	}

}