#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

	
double a[20];
bool vis[20];
int n;
double d;
double min1;
double calc1(double r1,double r2)
{
	return sqrt( (r1+r2)*(r1+r2) -  (d-(r1+r2))*(d-(r1+r2)));
}


void work(int step,double fre,double sum)
{
	int i;
	if (step==n)
	{
		sum+=fre;
		if (sum<min1) min1=sum;
	}
	for(i=0;i<n;++i)
	{
		if (vis[i])
		{
			vis[i]=false;
			work(step+1,a[i],sum+calc1(fre,a[i]));
			vis[i]=true;
		}
	}
}
int main()
{
	int i;


	while(scanf("%d%lf",&n,&d),n!=0||d!=0)
	{
		memset(vis,true,sizeof(vis));
		min1=21000000000;
		for(i=0;i<n;++i)
		{
			scanf("%lf",&a[i]);
		}
		for(i=0;i<n;++i)
		{
			vis[i]=false;
			work(1,a[i],a[i]);
			vis[i]=true;
		}
		printf("%.0f\n",min1);
	}
	return 0;
}
