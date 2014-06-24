#include<iostream>
#include<cmath>
using namespace std;
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
const double pi=acos(-1.0);
struct point{double x,y;};
struct line{point a,b;};

point intersection(point u1,point u2,point v1,point v2)//求直线交点
{ 
point ret=u1; 
double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))/((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
ret.x+=(u2.x-u1.x)*t; 
ret.y+=(u2.y-u1.y)*t;
return ret;
}


point rot(point a,point b,double ang)//旋转点  另一点 旋转的角度  返回非旋转点旋转后的的坐标
{
	point ret;
	double ve[2];
	double angle;
	double r;
	ve[0]=b.x-a.x;
	ve[1]=b.y-a.y;
	r=sqrt(ve[0]*ve[0]+ve[1]*ve[1]);
	angle=acos(ve[0]/r);
	if (ve[1]<0) angle=2*pi-angle;//y为负值  要另外讨论
	angle+=ang;
	ve[0]=r*cos(angle);
	ve[1]=r*sin(angle);
	ret.x=a.x+ve[0];
	ret.y=a.y+ve[1];
	return ret;
}






int main()
{
	point a[3];//存储3个顶点
	point d[3];
	point b[6];
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


		for(i=0;i<3;++i)
		{
          b[2*i]=rot(a[i],a[(i+1)%3],pi/2);
		 b[2*i+1]=rot(a[(i+1)%3],a[i],-pi/2);
		}


		d[0].x=(b[0].x+b[5].x)/2;
		d[0].y=(b[0].y+b[5].y)/2;
		d[1].x=(b[1].x+b[2].x)/2;
		d[1].y=(b[1].y+b[2].y)/2;
		d[2].x=(b[3].x+b[4].x)/2;
		d[2].y=(b[3].y+b[4].y)/2;

        oo=intersection(d[0],a[0],d[1],a[1]);
		if (abs(oo.x-0)<0.000001) oo.x=0;
		if (abs(oo.y-0)<0.000001) oo.y=0;
		printf("%.4lf %.4lf\n",oo.x,oo.y);
	}
	return 0;
}

