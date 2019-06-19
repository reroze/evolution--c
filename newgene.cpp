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
void zhengchang(int fu[length], int mu[length], int new_now[length])//������ֳ
{
	
	for (int i = 0; i < length; i++)
	{
		if (i % 2 == 0)//��ż��λ��Ⱦɫ���Ŵ����Ӵ�
		{
			new_now[i] = fu[i];
		}
	}
	int mu_zuobiao = 0;
	int panduan = 0;
	for (int i = 0; i < length; i++)
	{
		if (i % 2 != 0)//��ĸ�׵���״�У�������û���Ŵ���Ⱦɫ�尴������ĸ��Ⱦɫ�����г��ֵ�˳���Ŵ����Ӵ����Ӷ���֤�Ӵ���Ⱦɫ�岻�ظ�
		{
			while (1)
			{
				if (jiancha_new(mu[mu_zuobiao], new_now) == 1)//��λ��Ӧ��Ⱦɫ�常��δ�����Ӵ�
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
			if (count == 2)//ͬһ��i���������Σ�Ϊ�ظ�Ⱦɫ��
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
void jiaocha(int fu_now[length], int mu_now[length])//���溯��
{
	int temp = 0;
	int left = 0;
	int zuobiao_fu[length]= { 0 };
	int zuobiao_mu[length] = { 0 };
	int right = length-1;
	while ((right - left > 4) || (right - left<0))//���ѡ��4��������Ⱦɫ��
	{
		left = length * rand() / (RAND_MAX);
		right = length * rand() / (RAND_MAX);
		if (right == length)
			right--;
		if (left == length)
			left--;
	}
	for (int i = left; i <= right; i++)//���н���
	{
		temp = fu_now[i];
		fu_now[i] = mu_now[i];
		mu_now[i] = temp;
		temp = 0;
	}
	chachong(fu_now, zuobiao_fu);//�õ��������ظ�Ⱦɫ���λ�ã�����ߣ�
	chachong(mu_now, zuobiao_mu);//�õ�ĸ�����ظ�Ⱦɫ���λ�ã�����ߣ�
	int mu_zuo = 0;
	int panduan = 0;
	for (int i = 0; i < length; i++)//��֪��ĸ�ظ���������Ŀһ�£�����ĸ�ظ���Ⱦɫ���ٽ��и���
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
void bianyi(int new_now[length])//�����ȡ����Ⱦɫ��λ�û���
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
	int fu_now[length] = { 0 };//���ݸ�����״
	for (int i = 0; i < length; i++)
		fu_now[i] = fu[i];
	int mu_now[length] = { 0 };//����ĸ����״
	for (int i = 0; i < length; i++)
		mu_now[i] = mu[i];

	f = fu_now;
	m = mu_now;

	float jiaocha_gailv_now =1.0*rand() / (RAND_MAX);//���ɽ������
	//jiaocha_gailv_now = 0;
	float bianyi_gailv_now = 1.0*rand() / (RAND_MAX);//���ɱ������
	//bianyi_gailv_now = 0;
	if (jiaocha_gailv_now < gailv_jiaocha)
	{
		jiaocha(fu_now, mu_now);//���滥����ĸ��״
		zhengchang(fu_now, mu_now, new_now);//���з�ֳ
	}
	else {
		zhengchang(fu_now, mu_now, new_now);
	}
	if (bianyi_gailv_now < gailv_bianyi)
	{
		bianyi(new_now);//�¸������
	}
}

void newg()//����������
{
	int fu = 0;
	int mu = 0;
	for (int i = 0; i < qun_number; i++)
	{
		if (dead[i] == 1)//���˸��屻��̭
		{
			while (fu == mu)//�޷��Խ�
			{
				fu = 100 * rand() / (RAND_MAX);
				while (dead[fu] == 1)//��֤�����ǻ��
					fu = 100 * rand() / (RAND_MAX);
				mu = 100 * rand() / (RAND_MAX);
				while (dead[mu] == 1)//��֤ĸ�׻�����
					mu = 100 * rand() / (RAND_MAX);
			}//��ѡ�¸���ĸ�ĸ
			fanzhi(swarm[fu], swarm[mu], newge[i]);//��ֳ����
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
				swarm[i][j] = newge[i][j];//����Ⱥ����ȥ�ĸ������������滻
				newge[i][j] = 0;//��0������
			}
			dead[i] = 0;//�ø���״̬��Ϊ��
		}
	}

}