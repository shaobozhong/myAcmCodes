#include<iostream>
#include<cmath>
//#include<stdio.h>
using namespace std;

struct point 
{
	double x,y;
};

int main()
{
	int t;
	point p1,p2,p3;
	point p4;
	double p;
	double S;
    scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y);
		p4=p1;
		p2.x-=p1.x;
		p2.y-=p1.y;
		p3.x-=p1.x;
		p3.y-=p1.y;
		p1.x=0;
		p1.y=0;//将顶点平移到原点

		p=(p2.x*p2.x)/(-2*p2.y);

		S=((p3.x*p3.x*p3.x)  / (-6*p))+p4.y*p3.x;
		S-=((p2.x*p2.x*p2.x) / (-6*p))+p4.y*p2.x;
        S-=((p3.y+p4.y)+(p2.y+p4.y))*(p3.x-p2.x)/2;
		/*
		S-=(p3.y-p2.y)/((p3.x-p2.y)*2) * p3.x*p3.x +  (p3.y - p3.x*(p3.y-p2.y)/(p3.x-p2.x))*p3.x+p4.y*p3.x;
		S+=(p3.y-p2.y)/((p3.x-p2.y)*2) * p2.x*p2.x +  (p3.y - p3.x*(p3.y-p2.y)/(p3.x-p2.x))*p2.x+p4.y*p2.x;
		*/
		printf("%.2lf\n",S);
	}
	return 0;
}