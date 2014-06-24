/*
描述

所谓凸多边形，就是把一个多边形任意一边向两方无限延长成为一条直线，如果多边形的其他各边均在此直线的同旁，那么这个多边形就叫做凸多边形。如图1，多边形ABCDEF，把线段AF向两方无限延长，此多边形的其他各边AB、BC、CD、DE、EF均在此直线的同旁，所以多边形ABCDEF是凸多边形。 




值得注意的是，在凸多边形的定义中，延长的这一边是凸多边形的任意一边。图2中的多边形ABCDEF，若分别把AB、BC、CD、DE各边延长为直线，这时均满足凸多边形的定义，但这时并不能说多边形是凸多边形。因为，延长线段AF为直线后，多边形其他各边并不在此直线的同旁。同样，把线段FE延长为直线后，又有类似的情况出现。 
把一个各边不自交的多边形任意一边向两方无限延长成为一直线，如果多边形的其他各边不在此直线的同旁，那么这个多边形就叫做凹多边形。图2中的多边形ABCDEF就是一个凹多边形。需要注意的是，在定义凹多边形时，我们加上了“各边不自交”的定语。这个限制是很重要的。事实上，在图3的多边形ABCD中，边AD与边BC自交，这不是凹多边形。如果一个多边形各边中，有某些边自交，这样的多边形就叫做折多边形。多边形分为凸多边形、凹多边形和折多边形。图3中的多边形ABCD就是一个折多边形。 
你的任务是，依次给你多边形的顶点坐标，请编程判定多边形的类型，如果为凸多边形计算他的面积。 

输入

输入中有多个用例。第一行为用例的个数N（1<=N<=10000），每个用例的开始行为一个正整数m（1<=m<=1000），表示顶点的个数。接下来的m行的每行由一个空格分开的两了实数，分别表示顶点的坐标x和y。

输出

对每个用例首先输出用例数，如：Case 1: 
接下来输出多边形的类型，如果是凸多边形就直接输出他的面积（结果保留2位小数），如果为凹多边形就输出：“Concave polygon.”。如果为折多边形就输出：“Fold polygon”。 

样例输入

3
5
0 0
0 1
0.5 0.5
1 1
1 0
4
0 0
0 1
1 0
1 1
3
0 0
2 2.5
4 0

样例输出

Case 1:
Concave polygon.
Case 2:
Fold polygon.
Case 3:
5.00

题目语言

CN(CN:中文 EN:英文 JP:日文
*/

#include <iostream>  
#include <vector>
#include <math.h>
#include <stdio.h>
#include <list>
#define PRECISION 1e-8

class Point
{
public:
	Point( double x=0, double y=0 ) : m_x(x), m_y(y) {}
public:
	double m_x;
	double m_y;
};

bool operator==(const Point& l, const Point& r)
{
	return l.m_x==r.m_x && l.m_y==r.m_y;
}

Point operator-(const Point& l, const Point& r)
{
	return Point(l.m_x-r.m_x, l.m_y-r.m_y);
}

struct Line
{
	Point s, e;
};

double linesqr(double x1,double y1,double x2,double y2)
{ return (x2-x1)*(y1+y2)/2.0; }

//clockwise +
double anyS(std::vector<Point>& v)
{
	double fx,fy,x1,y1,x2,y2;
	double s=0.0;
	int n,i;
	n=v.size();
	x1=v[0].m_x;
	y1=v[0].m_y;
	fx=x1;fy=y1;
	x2=v[1].m_x;
	y2=v[1].m_y;
	s=linesqr(x1,y1,x2,y2);
	for(i=2;i<n;++i)
	{
		x1=x2;y1=y2;
		x2=v[i].m_x;
		y2=v[i].m_y;
		s+=linesqr(x1,y1,x2,y2);
	}
	s+=linesqr(x2,y2,fx,fy);//首尾相连

	return s;
}

int dbcmp(double d)
{
	if (fabs(d) < PRECISION)
		return 0;
	return d > 0 ? 1 : -1;
}//三叉口函数,避免精度误差

double length(double x, double y)
{
	return sqrt(x*x + y*y);
}//向量的模

double dotdet(double x1, double y1, double x2, double y2)
{
	return x1*x2 + y1*y2;
}//向量点积

double det(double x1, double y1, double x2, double y2)
{
	return x1*y2 - x2*y1;
}//向量叉积

int cross(Point a, Point c, Point d)
{
	return dbcmp( det(a.m_x-c.m_x, a.m_y-c.m_y, d.m_x-c.m_x, d.m_y-c.m_y) );
}//右手螺旋定则,a在cd右侧返回1,左侧返回-1,共线返回0

bool between(Point a, Point c, Point d)
{
	return dbcmp( dotdet(c.m_x-a.m_x, c.m_y-a.m_y, d.m_x-a.m_x, d.m_y-a.m_y) ) != 1;
}//在cross(a, c, d)==0的前提下,点a在线段cd内部返回true

int segIntersect(Point a, Point b, Point c, Point d)
{
	int a_cd = cross(a, c, d);
	if (a_cd == 0 && between(a, c, d))
		return 2;

	int b_cd = cross(b, c, d);
	if (b_cd == 0 && between(b, c, d))
		return 2;

	int c_ab = cross(c, a, b);
	if (c_ab == 0 && between(c, a, b))
		return 2;

	int d_ab = cross(d, a, b);
	if (d_ab == 0 && between(d, a, b))
		return 2;

	if ((a_cd ^ b_cd) == -2 && (c_ab ^ d_ab) == -2)
		return 1;

	return 0;
}//两线段相交情况,0--不相交,1--规范相交,2--不规范相交(交于端点或重合)

bool theSame(const Line& newl, const Line& oldl)
{
	Point v1=newl.e-newl.s;
	Point v2=oldl.e-oldl.s;

	if (cross(newl.e, oldl.s, oldl.e)==0)
		return dotdet(v1.m_x, v1.m_y, v2.m_x, v2.m_y)<0;
	else
		return false;
}

bool Do(std::list<Line>& ls, const Line& l)
{
	bool ok=true;
	std::list<Line>::reverse_iterator iter=ls.rbegin();

	ok=!theSame(l, *iter);
	if (!ok)
		return ok;

	++iter;
	while (iter!=ls.rend())
	{
		if (segIntersect(l.s, l.e, iter->s, iter->e)!=0)
		{
			ok=false;
			break;
		}
		++iter;
	}

	return ok;
}

bool cmp(const std::vector<Point>& v)
{
	Point c, d;
	c=v[0];
	for (int i=1; i<v.size(); ++i)
	{
		d=v[i];
		for (int j=0; j<v.size(); ++j)
			if (!(v[j]==c || v[j]==d))
			{
				if (cross(v[j], c, d)!=1)
					return false;
			}
			c=d;
	}
	return true;
}

int main()
{
	int tt=0;
	int n;
	bool ok;
	Point p1, p2;
	int cases;
	std::cin>>cases;
	for (int qq=0; qq<cases; ++qq)
	{
		std::cin>>n;
		++tt;
		printf("Case %d:\n", tt);
		std::vector<Point> v(n);
		if (n>=3)
		{
			ok=true;
			std::cin>>v[0].m_x>>v[0].m_y;
			std::cin>>v[1].m_x>>v[1].m_y;
			p1=v[0];
			p2=v[1];
			if (p1==p2)
				ok=false;
			Line l;
			Line fi;
			l.s=p1;
			l.e=p2;
			fi=l;
			std::list<Line> ls;
			ls.push_back(l);
			if (ok)
			{
				for (int i=2; i<n; ++i)
				{
					std::cin>>v[i].m_x>>v[i].m_y;
					if (ok)
					{			
						p1=p2;
						p2=v[i];
						l.s=p1;
						l.e=p2;
						if (!Do(ls, l))
							ok=false;
						ls.push_back(l);
					}
				}
				if (ok)
				{
					p1=p2;
					p2=v[0];
					l.s=p1;
					l.e=p2;
					ls.pop_front();
					ok=Do(ls, l);
					ok=(segIntersect(p1, p2, fi.s, fi.e)==2)&&ok;
				}
			}
		}
		if (ok)
		{
			if (cmp(v))
				printf("%.2f\n", anyS(v));
			else
				printf("Concave polygon.\n");
		}
		else
			printf("Fold polygon.\n");
	}
	return 0;
}