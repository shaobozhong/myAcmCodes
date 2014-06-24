#include<iostream>
#include<cmath>
using namespace std;

const double pspeed=100;
const double rspeed=350;
const double eps=1e-6;
const double pi=acos(-1.0);
struct point 
{
	double x,y;
};


void Solve_X(int &Root_n,double a,double b,double c,double &x1,double &x2)//解1元2次方程  根的数目 ax+by+c=0
{	double disc=b*b-4*a*c;
if(disc<0){Root_n=0;return;}
if(fabs(disc)<1e-6){
	Root_n=1;
	x1=-b/(2*a);
	return ;
}
Root_n=2;
x1=(-1*b+sqrt(disc))/(2*a);
x2=(-1*b-sqrt(disc))/(2*a);
return;
}
void Circle_Cross(const point &o1,const point &o2,double r1,double r2,int &Cross_n,point &Cross1,point &Cross2) //求两圆的交点
{
	double a,b,c;
	//ax+by+c=0 交线方程
	a=o2.x-o1.x;
	b=o2.y-o1.y;
	c=1.0/2*(o1.x*o1.x -o2.x *o2.x +o1.y*o1.y -o2.y *o2.y +r2*r2-r1*r1);
	if(a==0 && b==0)
	{
		Cross_n=0;return;
	}
	if(a==0)
	{
		double ky=-1*c/b;
		double tmp=r1*r1-(ky-o1.y )*(ky-o1.y);
		if(tmp<0)
		{Cross_n=0;
		return;
		}
		if(fabs(tmp)<1e-6)
		{
			Cross_n=1;
			Cross1.x=o1.x;
			Cross1.y=ky;
			return;
		}
		else
		{
			Cross_n=2;
			Cross1.x=o1.x+sqrt(tmp);
			Cross1.y=ky;
			Cross2.x=o1.x-sqrt(tmp);
			Cross1.y=ky;
			return;
		}
	}
	if(b==0){
		double kx=-1*c/a;
		double tmp=r1*r1-(kx-o1.x )*(kx-o1.x);
		if(tmp<0){Cross_n=0;return;}
		if(fabs(tmp)<1e-6){
			Cross_n=1;
			Cross1.x=kx;
			Cross1.y=o1.y ;
			return;
		}
		else
		{
			Cross_n=2;
			Cross1.y=o1.y+sqrt(tmp);
			Cross1.x=kx;
			Cross2.y=o1.y-sqrt(tmp);
			Cross1.x=kx;
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
	Solve_X(root_n,a,b,c,y1,y2);	
	if(root_n==0)
	{
		Cross_n=0;
		return;
	}
	if(root_n==1)
	{
		Cross_n=1;
		Cross1.x=k*y1+m;
		Cross2.y=y1;
		return;
	}
	Cross_n=2;	
	Cross1.y=y1;
	Cross1.x=k*y1+m;
	Cross2.y=y2;
	Cross2.x=k*y2+m;
}

double distance1(const point &a,const point &b)
{
	double res=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	return res;
}
int main()
{
	int n;
	point des;
	point o[2];
	double r[2];
	double at;//到达接收装置的时间
	double t;//发射的时间
	double dis;//卫星从基准时间移动的距离
	int i,j;
	int Cross_n;
	bool la;
	point Cross[2];
	double x,y,degree;
	int casenum=0;
	//freopen("2.txt","w",stdout);
	while(cin>>n>>at>>des.x>>des.y,n!=0||abs(at-0)>=1e-6||abs(des.x-0)>=1e-6||abs(des.y-0)>=1e-6)
	{
		++casenum;
		printf("Trial %d: ",casenum);
		if (n==1) 
		{
           cin>>x>>y>>degree>>t;
		   puts("Inconclusive.");
		   continue;
		}
		la=false;
		for(i=0;i<2;++i)
		{
			cin>>x>>y>>degree>>t;
			degree=90-degree;
			if (degree<0) degree+=360;
			degree=degree/180*pi;
			dis=pspeed*t;
			o[i].x=x+dis*cos(degree);
			o[i].y=y+dis*sin(degree);
			r[i]=(at-t)*rspeed;
		}
		Circle_Cross(o[0],o[1],r[0],r[1],Cross_n,Cross[0],Cross[1]);


		r[1]=0.1;
		for(;!la&&i<n;++i)
		{
			if (Cross_n==0) 
			{
				for(;i<n;++i)
				{
					cin>>x>>y>>degree>>t;
				}
				puts("Inconsistent.");
				la=true;
				break;
			}
			cin>>x>>y>>degree>>t;
			degree=90-degree;
			if (degree<0) degree+=360;
			degree=degree/180*pi;
			dis=pspeed*t;
			o[0].x=x+dis*cos(degree);
			o[0].y=y+dis*sin(degree);
			r[0]=(at-t)*rspeed;
			for(j=0;j<Cross_n;++j)
			{
				/*o[1].x=Cross[j].x;
				o[1].y=Cross[j].y;
				int cross_n;
				point cross[2];
				Circle_Cross(o[0],o[1],r[0],r[1],cross_n,cross[0],cross[1]);

				if (cross_n==0)
				{
				if (j==0)
				{
				Cross[0]=Cross[1];
				j=-1;
				}
				Cross_n-=1;
				}*/
				dis=distance1(Cross[j],o[0]);
				if (abs(dis-r[0])-0.000001>=0.1)
				{
					if (j==0)
					{
						Cross[0]=Cross[1];
						j=-1;
					}
					Cross_n-=1;
				}
			}
		}

		if (la) continue;

		if (Cross_n==2)
		{
			puts("Inconclusive.");
		}
		else
		{
			if (Cross_n==0)
			{
				puts("Inconsistent.");
			}
			else 
			{
				if (distance1(Cross[0],des)-0.000001<=0.1)
				{
					puts("Arrived.");
				}
				else 
				{
					x=des.x-Cross[0].x;
					y=des.y-Cross[0].y;
					r[0]=sqrt(x*x+y*y);
					degree=acos(x/r[0]);
					if (y<0) degree=2*pi-degree;
					degree=degree/pi*180;
					degree=90-degree;
					if (degree<0) degree+=360;
					printf("%.0lf degrees\n",degree);
				}

			}
		}
	}
	return 0;
}


