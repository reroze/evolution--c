#include "thedefine.h"
extern float max_guzhi = 0;//��ǰ��Ⱥ������ֵ
extern float min_guzhi = 0;//��ǰ��Ⱥ����С��ֵ
extern float xuanze_guzhi = 0;//��Ȼѡ����ֵ
extern float gailv_jiaocha = 1.0;//���滥���ĸ���
extern float gailv_bianyi = 1.0;//����ĸ���
extern float max_guzhi_whole = 0;//����������������Ⱥ��ֵ�����ֵ
extern int dead[qun_number] = { 0 };//����Ȼѡ����̭�ĸ���
extern int newge[qun_number][length] = { 0 };//������
//extern float cities[length][2] = { { 1,1 },{ 2,2 },{ 3,3 },{ 1,3 },{ 2,3 },{ 5,6 },{ 8,7 },{ 9,4 },{ 5,3 },{ 4,7 },{ 5,5 },{ 4,9 },{ 7,1 },{ 6,7 } };//��ʼ����������
extern float cities[length][2] = { {0,0},{12,32},{5,25},{8,45},{33,17},{25,7},{15,15},{15,25},{25,15},{41,12} };//���е�����
extern int swarm[qun_number][length] = { 0 };//��ʼ����Ⱥ
extern float swarm_guzhi[qun_number] = { 0 };//��ʼ����Ⱥ��ֵ
extern int cishu = 0;//��ʼ���ж���ֵ
