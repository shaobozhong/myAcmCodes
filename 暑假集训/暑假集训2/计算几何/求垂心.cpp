#include<iostream>
#include <math.h> 
using namespace std;
struct point{double x,y;}; 
struct line{point a,b;}; 
double distance(point p1,point p2)
{ 
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
point intersection(line u,line v)
{ 
	point ret=u.a; 
	double t=((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))/((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x)); 
	ret.x+=(u.b.x-u.a.x)*t; 
	ret.y+=(u.b.y-u.a.y)*t;
	return ret; 
}

//垂心
point perpencenter(point a,point b,point c)
{ 
	line u,v; u.a=c; 
	u.b.x=u.a.x-a.y+b.y;
	u.b.y=u.a.y+a.x-b.x;
	v.a=b; 
	v.b.x=v.a.x-a.y+c.y; 
	v.b.y=v.a.y+a.x-c.x;
	return intersection(u,v); 
}

int main()
{
	point a[3];//存储3个顶点


	point oo;
	int t;//测试样例数
	int i;
	cin>>t;
	while(t--)
	{
		for(i=0;i<3;++i)//输入三个点的坐标
		{
			cin>>a[i].x>>a[i].y;
		}

		oo=perpencenter(a[0],a[1],a[2]);
		if((abs(oo.x)-0<0.000001))oo.x=0;
		if((abs(oo.y)-0<0.000001))oo.y=0;
		printf("%.4lf %.4lf\n",oo.x,oo.y);
	}
	return 0;
}