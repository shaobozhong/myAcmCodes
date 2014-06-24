#include<iostream>
#include<cmath>
using namespace std;
const double pi=acos(-1.0);
struct point{double x,y;};

point rot(point a,point b,double ang)//第一个是旋转点  另一点 旋转的角度  返回另一点的坐标  不过要注意返回的点的值可能是负-0 要处理
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

	return 0;
}

1.向量
向量的旋转
其中（x1， y1）就是（x0， y0）旋转角B后得到的点，也就是位置向量R最后指向的点。
向量围绕圆点的逆时针旋转公式
x1 = x0 * cosB - y0 * sinB
y1 = x0 * sinB + y0 * cosB
顺时针旋转就把角度变为负
x1 = x0 * cosB + y0 * sinB
y1 = -x0 * sinB + y0 * cosB
