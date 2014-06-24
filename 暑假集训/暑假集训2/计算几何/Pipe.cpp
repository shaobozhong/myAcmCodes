#include<iostream>
#include<cmath>
using namespace std;
#define eps 1e-6

struct point
{
	double x,y;
};
struct line
{
	point a,b;
};

point a[25];

int n;
point intersection(point u1,point u2,point v1,point v2)//求直线交点
{ 
	point ret=u1; 
	double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))/((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
	ret.x+=(u2.x-u1.x)*t; 
	ret.y+=(u2.y-u1.y)*t;
	return ret;
}


bool work(point u1,point u2,point &ret)
{
	int i;
	point x,y;
	for(i=1;i<n;++i)
	{
		x=a[i];
		y=a[i];
		y.y-=1;
		ret=intersection(u1,u2,x,y);	
		if (ret.y-eps>x.y)
		{
			x=a[i];y=a[i-1];
			ret=intersection(u1,u2,x,y);
			return false;
		}

		if (ret.y+eps<y.y)
		{
			x=a[i];
			y=a[i-1];
			x.y-=1;
			y.y-=1;
			ret=intersection(u1,u2,x,y);
			return false;
		}
	}
	return true;
}

double distance1(const point &a,const point &b )
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
	double dis;
	double res;
	bool la;
	int i,j;
	point x,y;
	point temp;
	while(cin>>n,n!=0)
	{
		for(i=0;i<n;++i)
		{
			cin>>a[i].x>>a[i].y;
		}
		la=false;
		res=0;
		for(i=0;!la&&i<n;++i)
		{
			for(j=0;!la&&j<n;++j)
			{
			        if (i==j) continue;
					x=a[i];
					y=a[j];
					y.y-=1;
					temp=a[0];
					temp.y-=1;
					if (i!=0 && j!=0) x=intersection(a[0],temp,x,y);
					else 
					{
						if (j==0)
						{
							temp=x;
							x=y;
							y=temp;
						}
					}

					if (x.y<=a[0].y && x.y>=a[0].y-1)
					{
					la=work(x,y,temp);
					if (la) {puts("Through all the pipe.");break;}
					else {
						dis=distance1(x,temp);
						if (res+eps<dis) res=dis;
					}
					}
			
			}
		}

		if (!la)printf("%.2lf\n",res);
	}

	return 0;
}