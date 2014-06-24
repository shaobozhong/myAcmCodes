/*
描述

Maxwell是一个顽皮的男孩。 
一天，他把又白又干净的墙用墨水弄脏了，这时他的妈妈很快就要回来了。Maxwell想找一块白色的凸多边形去盖住这些墨水点。你能告诉他如何用最小面积的凸多边形来盖住这些墨水点吗？ 
现在，给出这些墨水点的坐标，你需回答出能盖住所有墨水点的凸多边形使面积最小。 

输入

输入的第一行是一个确定的正整数T，T是测试用例的数量。 
每个测试用例的第一行是一个正整数N（1≤N≤105），N是墨水的点数，随后有N行，第i行包括两整数Xi和Yi(0≤Xi,Yi<20000)表示第i个墨水点的坐标。整数之间用空格分开。

输出

程序每个测试用例的输出由一行组成，即每个用例输出最小的面积，是一实数，保留小数点后一位。

样例输入

2
4
0 0
1 0
0 1
1 1
2
0 0
0 1

样例输出

1.0
0.0

题目语言

CN(CN:中文 EN:英文 JP:日文)
*/
#include <iostream>   //cout, cin
#include <algorithm>  //copy sort
#include <iterator>   //ostream_iterator
#include <vector>     //vector
#include <queue>      //queue
#include <stdlib.h>   //srand rand
#include <time.h>     //time
#include <limits>     //numeric_limits
#include <math.h>     //sqrt
#include <assert.h>   //assert

class Point
{
public:
	Point( double x=0, double y=0 ) : m_x(x), m_y(y) {}
public:
	double m_x;
	double m_y;
};

double area;

std::istream& operator>> (std::istream& in, Point& p)
{
	return (in>>p.m_x>>p.m_y);
}

std::ostream& operator<< (std::ostream& out, const Point& p)
{
	return (out<<"x="<<p.m_x<<" y="<<p.m_y);
}

class CmpXY
{
public:
	bool operator() (const Point& l, const Point& r)
	{
		bool ret;
		if ( l.m_x<r.m_x )
		{
			ret=true;
		}
		else if ( l.m_x==r.m_x )
		{
			if ( l.m_y<r.m_y )
			{
				ret=true;
			}
			else
			{
				ret=false;
			}
		}
		else
		{
			ret=false;
		}
		return ret;
	}
};

void findup(std::vector<Point>& in, const Point& p1, const Point& p2, std::vector<Point>& out)
{
	std::vector<Point> up;  //新上包点
	Point upp; //极点
	double uph=0; //极高
	double h;
	std::vector<Point>::iterator iter=in.begin();
	while ( iter!=in.end() )
	{
		h=p1.m_x*p2.m_y+iter->m_x*p1.m_y+p2.m_x*iter->m_y-iter->m_x*p2.m_y-p2.m_x*p1.m_y-p1.m_x*iter->m_y;
		if ( h>0 )  //p3在直线p1p2左边 在上包中
		{
			up.push_back(*iter);
			if ( h>uph )
			{
				uph=h;
				upp=*iter;
			}
		}
		++iter;
	}
	if ( uph>0 )
	{
		area+=uph;
		out.push_back(upp);
	}
	//递归构造新上包
	if ( !up.empty() )
	{
		findup(up, p1, upp, out);
		findup(up, upp, p2, out);
	}
}

void finddown(std::vector<Point>& in, const Point& p1, const Point& p2, std::vector<Point>& out)
{
	std::vector<Point> down; //新下包点
	Point downp;  //极点
	double downh=0;  //极高 
	double h;
	std::vector<Point>::iterator iter=in.begin();
	while ( iter!=in.end() )
	{
		h=p1.m_x*p2.m_y+iter->m_x*p1.m_y+p2.m_x*iter->m_y-iter->m_x*p2.m_y-p2.m_x*p1.m_y-p1.m_x*iter->m_y;
		if ( h<0 ) //p3在直线p1p2右边 在下包中
		{
			down.push_back(*iter);
			if ( h<downh )
			{
				downh=h;
				downp=*iter;
			}
		}
		++iter;
	}
	if ( downh<0 )
	{
		area+=-downh;
		out.push_back(downp);
	}
	//递归构造新下包
	if ( !down.empty() )
	{
		finddown(down, p1, downp, out);
		finddown(down, downp, p2, out);
	}
}

void FindPoint(std::vector<Point>& in, std::vector<Point>& out)
{
	//排序
	std::sort(in.begin(), in.end(), CmpXY());
	Point p1=in.front(); //凸包一点
	Point p2=in.back();  //凸包一点
	out.push_back(p1);
	out.push_back(p2);
	//迭代变量
	std::vector<Point>::iterator iter=in.begin()+1;
	std::vector<Point> up; //上凸包点 
	std::vector<Point> down; //下凸包点
	Point upp, downp;  //凸包极点
	double uph=0, downh=0;    //极点离基线高度
	double h;
	while ( iter!=in.end()-1 )
	{
		h=p1.m_x*p2.m_y+iter->m_x*p1.m_y+p2.m_x*iter->m_y-iter->m_x*p2.m_y-p2.m_x*p1.m_y-p1.m_x*iter->m_y;
		if ( h>0 ) //p3在直线p1p2左边 在上包中
		{
			up.push_back(*iter);
			if ( h>uph )
			{
				uph=h;
				upp=*iter;
			}
		}
		if ( h<0 ) //p3在直线p1p2右边 在下包中
		{
			down.push_back(*iter);
			if ( h<downh )
			{
				downh=h;
				downp=*iter;
			}
		}
		++iter;
	}
	if ( uph>0 )
	{
		area+=uph;
		out.push_back(upp);
	}
	if ( downh<0 )
	{
		area+=-downh;
		out.push_back(downp);
	}
	//构造上包
	if ( !up.empty() )
	{
		findup(up, p1, upp, out);
		findup(up, upp, p2, out);
	}
	//构造下包
	if ( !down.empty() )
	{
		finddown(down, p1, downp, out);
		finddown(down, downp, p2, out);
	}
}

std::vector<Point> in;
std::vector<Point> out;

int main(int argc, char* argv[])
{
	int t;
	std::cin>>t;
	int n;
	Point p;
	while (t--)
	{
		std::cin>>n;
		if (n!=1)
		{	
			in.clear();
			out.clear();
			area=0;
			for (int i=0; i<n; ++i)
			{
				std::cin>>p.m_x>>p.m_y;
				in.push_back(p);
			}
			FindPoint(in, out);
		}
		else
		{
			std::cin>>p.m_x>>p.m_y;
			area=0;
		}
		printf("%.1f\n", area/2);
	}
	return 0;
}