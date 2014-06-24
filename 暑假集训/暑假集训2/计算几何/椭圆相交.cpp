//方法椭圆对x积分具体见计算数学基础(一).ppt
#include<iostream>
#include<cmath>
using namespace std;
const double pi=acos(-1.0);
struct point
{
	double x,y;
};
double a,b,_a,_b;
void getCross(point &Cross)
{
	Cross.y=sqrt((_a*_a*_b*_b*b*b*(1-(a*a)/(_a*_a)))/(_a*_a*b*b-a*a*_b*_b));
	Cross.x=sqrt((1-(Cross.y*Cross.y)/(b*b))*a*a);
}

void Area(const point &Cross,double &S)
{
	double _angle;
	if (a<=_a) {S=pi*a*b;return;}
	if (_b<=b) {S=pi*_a*_b;return;}//这两种情况是包含
	_angle=asin(Cross.x/a);
	S=a*b*(_angle/2+(sin(2*_angle))/4);
	_angle=asin(Cross.y/_b);
	S+=_a*_b*(_angle/2+(sin(2*_angle)/4));//求两个积分
	S-=Cross.x*Cross.y;//减去公共部分
	S*=4;
}

int main()
{
	int t;
	double tmp;
	point Cross;
	double S;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf",&a,&b,&_a,&_b);
		getCross(Cross);
		Area(Cross,S);
		printf("%.3lf\n",S);
	}
	return 0;
}