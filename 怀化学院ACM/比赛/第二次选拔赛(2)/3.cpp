#include <iostream>  
#include <vector>
#include <math.h>
#include <stdio.h>
#include <list>
using namespace std;
#define PRECISION 1e-8
//网上的类 
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

//clockwise 
double anyS(vector<Point>& v)
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

bool Do(list<Line>& s, const Line& l)
{
	bool t=true;
	list<Line>::reverse_iterator iter=s.rbegin();

	t=!theSame(l, *iter);
	if (!t)
		return t;

	++iter;
	while (iter!=s.rend())
	{
		if (segIntersect(l.s, l.e, iter->s, iter->e)!=0)
		{
			t=false;
			break;
		}
		++iter;
	}

	return t;
}

bool cmp(const vector<Point>& v)
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
	bool t;
	Point p1, p2;
	int cases;
	cin>>cases;
	for (int qq=0; qq<cases; ++qq)
	{
		cin>>n;
		++tt;
		printf("Case %d:\n", tt);
		vector<Point> v(n);
		if (n>=3)
		{
			t=true;
			cin>>v[0].m_x>>v[0].m_y;
			cin>>v[1].m_x>>v[1].m_y;
			p1=v[0];
			p2=v[1];
			if (p1==p2)
				t=false;
			Line l;
			Line fi;
			l.s=p1;
			l.e=p2;
			fi=l;
			list<Line> s;
			s.push_back(l);
			if (t)
			{
				for (int i=2; i<n; ++i)
				{
					cin>>v[i].m_x>>v[i].m_y;
					if (t)
					{			
						p1=p2;
						p2=v[i];
						l.s=p1;
						l.e=p2;
						if (!Do(s, l))
							t=false;
						s.push_back(l);
					}
				}
				if (t)
				{
					p1=p2;
					p2=v[0];
					l.s=p1;
					l.e=p2;
					s.pop_front();
					t=Do(s, l);
					t=(segIntersect(p1, p2, fi.s, fi.e)==2)&&t;
				}
			}
		}
		if (t)
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