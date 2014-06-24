#include<iostream>
#include<cmath>
using namespace std;

struct TPoint
{
	double x,y;
};
void fangcheng2(int &jie_n,double a,double b,double c,double &x1,double &x2)
{	double disc=b*b-4*a*c;
	if(disc<0){jie_n=0;return;}
	if(fabs(disc)<1e-6){
		jie_n=1;
		x1=-b/(2*a);
		return ;
	}
	jie_n=2;
	x1=(-1*b+sqrt(disc))/(2*a);
	x2=(-1*b-sqrt(disc))/(2*a);
   return;
}
void Circle2cross(int &cross_n,TPoint o1,TPoint o2,double r1,double r2,TPoint &p1,TPoint &p2){
	double a,b,c;
	//ax+by+c=0 交线方程
	a=o2.x-o1.x;
	b=o2.y-o1.y;
	c=1.0/2*(o1.x*o1.x -o2.x *o2.x +o1.y*o1.y -o2.y *o2.y +r2*r2-r1*r1);
	if(a==0 && b==0){cross_n=0;return;}
if(a==0){
		double ky=-1*c/b;
		double tmp=r1*r1-(ky-o1.y )*(ky-o1.y);
	if(tmp<0){cross_n=0;return;}
		if(fabs(tmp)<1e-6){
			cross_n=1;
			p1.x=o1.x;
			p1.y=ky;
			return;
		}else{
		cross_n=2;
			p1.x=o1.x+sqrt(tmp);
			p1.y=ky;
			p2.x=o1.x-sqrt(tmp);
			p1.y=ky;
			return;
		}
	}
if(b==0){
		double kx=-1*c/a;
		double tmp=r1*r1-(kx-o1.x )*(kx-o1.x);
		if(tmp<0){cross_n=0;return;}
		if(fabs(tmp)<1e-6){
			cross_n=1;
			p1.x=kx;
			p1.y=o1.y ;
			return;
		}else{
			cross_n=2;
			p1.y=o1.y+sqrt(tmp);
			p1.x=kx;
			p2.y=o1.y-sqrt(tmp);
			p1.x=kx;
			return;
		}
	}
//x=ky+m
	double k=-1.0/a*b;
	double m=-1.0/a*c;
	double tmp=m-o1.x ;
	a=k*k+1;
	b=2*k*tmp-2*o1.y;
	c=tmp*tmp+o1.y*o1.y -r1*r1;
    double y1,y2;
	int root_n;	
    fangcheng2(root_n,a,b,c,y1,y2);	
    if(root_n==0){
       cross_n=0;
	   return;
	}
}
int main()
{
	return 0;
}