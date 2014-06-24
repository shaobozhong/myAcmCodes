#include<iostream>
#include<cmath>
using namespace std;
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
const double pi=acos(-1.0);
struct point
{
	double x,y;
};
struct line{
	point a,b;
};
point a[35],b[35],c[35],d[35];

int n;


point intersection(point u1,point u2,point v1,point v2)//求直线交点
{ 
	point ret=u1; 
	double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))/((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
	ret.x+=(u2.x-u1.x)*t; 
	ret.y+=(u2.y-u1.y)*t;
	return ret;
}

void init()
{
	int i;
	for(i=1;i<=n;++i)
	{
		cin>>a[i].x;
		a[i].y=0;
	}

	for(i=1;i<=n;++i)
	{
		cin>>b[i].x;
		b[i].y=1;
	}
	for(i=1;i<=n;++i)
	{
		cin>>c[i].y;
		c[i].x=0;
	}
	for(i=1;i<=n;++i)
	{
		cin>>d[i].y;
		d[i].x=1;
	}
}


double Area(const point &one,const point &two)//计算面积
{
    double p1x,p1y,p2x,p2y,result;
    p1x=one.x-0;
    p1y=one.y-0;
    p2x=two.x-0;
    p2y=two.y-0;
    result=(p1x*p2y-p2x*p1y)/2;
  return result;
}

double calc(point f[],point l[])
{
	double res;
	double temp;
	int i;
	res=0;
	for(i=0;i<=n;++i)
	{
		temp=Area(f[i],f[i+1])+Area(f[i+1],l[i+1])+Area(l[i+1],l[i])+Area(l[i],f[i]);
		if (res<temp) res=temp;
	}
	return res;
}

double work()
{
	double temp;
	int i,j;
	point inter[35][35];
	double res;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			inter[i][j]=intersection( a[j],b[j],c[i],d[i]);
		}
	}

	a[0].x=0;
	a[0].y=0;
	a[n+1].x=1;
	a[n+1].y=0;
	b[0].x=0;
	b[0].y=1;
	b[n+1].x=1;
	b[n+1].y=1;

	for(i=1;i<=n;++i)
	{
		inter[i][0]=c[i];
		inter[i][n+1]=d[i];
	}
	res=0;
	temp=calc(a,inter[1]);
	if (res<temp) res=temp;
	for(i=1;i<n;++i)
	{
		temp=calc(inter[i],inter[i+1]);
        if (res<temp) res=temp;
	}
	temp=calc(inter[n],b);
	if (res<temp) res=temp;
    return res;
}

int main()
{
    double res;
	
	while(cin>>n,n!=0)
	{
		res=0;
		init();
		res=work();
		printf("%.6lf\n",res);
	}
}