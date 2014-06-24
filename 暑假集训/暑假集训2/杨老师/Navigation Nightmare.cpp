/*
首先确定基本算法是使用并查集
然后有两个很关键的地方  
1、求集合中某一个点的坐标 可以从代表点 传递递推来得到 
2、合并两个集合的时候 两个直接关联点的距离 加上 在各自集合中相对代表点的距离  就是 两个代表点的距离
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

struct Question//存储各条问题   起点终点  限制时间   
{int x , y , z , t , a;};
struct Information//存储各条信息
{int x , y , z;char c;};
struct nodeC//用来存储点的坐标
{int x , y;};

const int dx[4] = {1 , -1 , 0 , 0};//方向
const int dy[4] = {0 , 0 , 1 , -1};

const int nx = 40010;
const int mx = 10010;

Information E[nx];//存储信息
Question Q[mx];//存储问题
nodeC con[nx];
int fa[nx] , tmp[nx];
int n , m , L , len;

bool cmp_1(const Question &i , const Question &j)//按照限制时间 进行排序
{
	return (i.z < j.z);
}

bool cmp_2(const Question &i , const Question &j)//按问题的顺序进行排序
{
	return (i.t < j.t);
}

void init()
{
	scanf("%d %d" , &n , &L);// 输入地的数量和信息数
	for (int i = 1 ; i <= L ; ++i)//输入信息
		scanf("%d %d %d %c" , &E[i].x, &E[i].y , &E[i].z , &E[i].c);
	for (int i = 1 ; i <= n ; ++i)//初始化父亲为本身 坐标为 0 ，0
	{
		fa[i] =i;
		con[i].x = con[i].y = 0;
	}
	scanf("%d" , &m);//问题数量
	for (int i = 0 ; i < m ; ++i)//输入问题 和限制
	{
		scanf("%d %d %d" , &Q[i].x , &Q[i].y , &Q[i].z);
		Q[i].t = i;
	}
	sort(Q , Q + m , cmp_1);//对问题的限制进行排序 可以从小的开始问 那样图就只要建一次
}

int find(int t)
{
	len = 0;
	while (fa[t] != t)//一直到可以代表这个点集的点
	{
		tmp[len++] = t;
		t = fa[t];
	}
	for (int i = len - 2 ; i >= 0 ; --i)//计算点集中点的坐标 全部直接跟 t点关联起来  以t点为标准计算坐标 与代表点建了关联的点就不会算了
	{
		con[tmp[i]].x += con[tmp[i + 1]].x;
		con[tmp[i]].y += con[tmp[i + 1]].y;
		fa[tmp[i]] = t;
	}//从代表点的前一个点开始 往后递推 得到寻找点的坐标  //代表点的坐标是  0,0 所以就算是已经与代表点关联了的点加了 也不要紧
	return t;
}

void work()
{
	int j = 0 , x , y , t;
	while (j < m && Q[j].z == 0)//限制为0条信息的情况排除掉 并赋值为-1 
	{
		Q[j++].a = -1;
	}

	for (int i = 1 ; i <= L ; ++i)//所有信息
	{
		x = find(E[i].x);//搜代表x所在有关联的点的结合的一个的顶点  一个集合第一次出现的那个点就是代表点
		y = find(E[i].y);//搜代表y所在有关联的点的结合的一个的顶点 
		fa[y] = x;//将这两个集合关联起  因为 E[i].x 和 E[i].y是有关系的
		if (E[i].c == 'E') t = 0;//上面有数组对应
		else if (E[i].c == 'W') t = 1;
		else if (E[i].c == 'N') t = 2;
		else if (E[i].c == 'S') t = 3;//con[E[i]].x-con[E[i].y].x 是E[i].x的原坐标 减去 y的原坐标 再加上 这两个点的真实距离 可以得到 y以x为标准的坐标
		con[y].x = -dx[t] * E[i].z - con[E[i].y].x + con[E[i].x].x;// 通过x点计算y点的坐标因为是从x扩展到y所以x不变   E[i].x点和 E[i].y点的距离坐标原点 也即坐标的距离 加上 他们之间的实际距离距离  就能表示两个代表点之间的距离 
		con[y].y = -dy[t] * E[i].z - con[E[i].y].y + con[E[i].x].y;
		while (j < m && Q[j].z == i)//当要求的限制时间到了时 就可以得到该问题的答案
		{
			x = find(Q[j].x);//找x所在集合的代表点
			y = find(Q[j].y); //找终点所在点集的代表点
			if (x != y)//没有关联起来
				Q[j].a = -1;
			else Q[j].a = abs(con[Q[j].x].x - con[Q[j].y].x) + abs(con[Q[j].x].y - con[Q[j].y].y);//计算答案
			++j;
		}
	}

	sort(Q , Q + m , cmp_2);// 按问题的先后排序

	for (int i = 0 ; i < m ; ++i)
		printf("%d\n" , Q[i].a);//输出所有答案
}

int main()
{
	init();//数据输入
	work();//主程序
}


