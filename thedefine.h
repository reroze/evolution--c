#define qun_number 100//种群数目100
//#define length 14//个体基因长度14
#define length 10
#define max_diedai 400//最大迭代次数200
extern float max_guzhi;
extern float min_guzhi;
extern float xuanze_guzhi;
extern float gailv_jiaocha;
extern float gailv_bianyi;
extern float max_guzhi_whole;
extern int dead[qun_number];
extern int newge[qun_number][length];
extern float cities[length][2];
extern int swarm[qun_number][length];
extern float swarm_guzhi[qun_number];
extern int cishu;
//extern int cities[length][2] = { { 1,1 },{ 2,2 },{ 3,3 },{ 1,3 },{ 2,3 },{ 5,6 },{ 8,7 },{ 9,4 },{ 5,3 },{ 4,7 },{ 5,5 },{ 4,9 },{ 7,1 },{ 6,7 } };//初始化城市坐标
//extern int swarm[qun_number][length] = { 0 };//初始化种群

#pragma once
