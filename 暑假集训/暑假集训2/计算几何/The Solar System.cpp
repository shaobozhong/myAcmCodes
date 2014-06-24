#include<iostream>
#include<cmath>
#include<stdio.h>//保证scanf printf 合法
using namespace std;
double a1,b1,t1,a2,b2,t2,t,c;
double S,G_S;
double s,e;
const double pi=acos(-1.0);
void calc(double &mid,double &y)
{
	double S_S;
	double angle;
	s=-1*a2;
	e=a2;
	while(1)
	{
		mid=(s+e)/2;
		angle=asin(1.0);

		S_S=G_S;
		S_S+=a2*b2*(angle/2+(sin(2*angle))/4);


		angle=asin(mid/a2);
		S_S-=a2*b2*(angle/2+(sin(2*angle)/4));
		y=sqrt((1-(mid*mid)/(a2*a2))*b2*b2);
		S_S+=(mid-c)*y/2;


		if (fabs(S_S-S)<1e-6) return;
		if (S_S<S) e=mid;
		else s=mid;
	}
}



void calc1(double &mid,double &y)
{
	double S_S;
	double angle;
	s=-1*a2;
	e=a2;
	while(1)
	{

		mid=(s+e)/2;
		angle=asin(mid/a2);

		S_S=G_S;
		S_S+=a2*b2*(angle/2+(sin(2*angle))/4);

		angle=asin(-1.0);
		S_S-=a2*b2*(angle/2+(sin(2*angle)/4));
		y=sqrt((1-(mid*mid)/(a2*a2))*b2*b2);
		S_S+=(c-mid)*y/2;//加上小三角形

		if (fabs(S_S-S)<0.000001) return;
		if (S_S>S) e=mid;
		else s=mid;
	}
}




int main()
{
    double x,y;
	int casenum;
	casenum=0;
	//freopen("1.txt","w",stdout);
	while(scanf("%lf%lf%lf%lf%lf%lf",&a1,&b1,&t1,&a2,&b2,&t),a1!=0||b1!=0||t1!=0||a2!=0||b2!=0||t!=0)
	{
		++casenum;
		t2=sqrt((t1*t1)*(a2*a2*a2)/(a1*a1*a1));//周期
		
		t=fmod(t,t2);//时间
		S=t*(pi*a2*b2)/t2;//面积
		c=sqrt(a2*a2-b2*b2);//c
		if (t<t2/2)
		{
			G_S=0;
			calc(x,y);
		}
		else 
		{
			G_S=pi*a2*b2/2;
			calc1(x,y);
			if (y!=0) y*=-1;
		}
		if (fabs(x)<0.000001) x=0;
		if (fabs(y)<0.000001) y=0;
		printf("Solar System %d: %.3lf %.3lf\n",casenum,x,y);
	}
	return 0;
}