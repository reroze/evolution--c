#include "thedefine.h"
extern float max_guzhi = 0;//当前种群的最大估值
extern float min_guzhi = 0;//当前种群的最小估值
extern float xuanze_guzhi = 0;//自然选择阈值
extern float gailv_jiaocha = 1.0;//交叉互换的概率
extern float gailv_bianyi = 1.0;//变异的概率
extern float max_guzhi_whole = 0;//整个迭代过程中种群估值的最大值
extern int dead[qun_number] = { 0 };//被自然选择淘汰的个体
extern int newge[qun_number][length] = { 0 };//新生代
//extern float cities[length][2] = { { 1,1 },{ 2,2 },{ 3,3 },{ 1,3 },{ 2,3 },{ 5,6 },{ 8,7 },{ 9,4 },{ 5,3 },{ 4,7 },{ 5,5 },{ 4,9 },{ 7,1 },{ 6,7 } };//初始化城市坐标
extern float cities[length][2] = { {0,0},{12,32},{5,25},{8,45},{33,17},{25,7},{15,15},{15,25},{25,15},{41,12} };//城市的坐标
extern int swarm[qun_number][length] = { 0 };//初始化种群
extern float swarm_guzhi[qun_number] = { 0 };//初始化种群估值
extern int cishu = 0;//初始化判定阈值
