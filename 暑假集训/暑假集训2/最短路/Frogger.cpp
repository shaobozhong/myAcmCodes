#include<iostream>
#include<cmath>
using namespace std;
#define MAX 205

double G[MAX][MAX];

struct Point
{
	int x,y;
};

double Dijkstra(int n,int s,int t)
{
	int i,j,w,minc,mark[MAX];
	double d[MAX];
	for (i=1;i<=n;i++) 
	{
		mark[i]=0;
	}
    for (i=1;i<=n;i++) 
	{
		d[i]=G[s][i];
	}
	d[s]=0;
	mark[s]=1;
	for (i=1;i<=n;i++)
	{
		minc=INT_MAX;
		w=0;
		for (j=1;j<=n;j++)
		{
			if ((mark[j]==0)&&(minc>d[j])) {minc=d[j];w=j;}
		}
		mark[w]=1;
		if (w==t) break;
		for (j=1;j<=n;j++)
		{
			if ((mark[j]==0)&&(d[j]>d[w]&&d[j]>G[w][j]))
			{ 
				d[j]=d[w]>G[w][j]?d[w]:G[w][j];
			}
		}
	}
	return d[t];
}

double distance1(const Point &a,Point &b)
{
	return sqrt(double(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}



int main()
{
	int n,m;
	int i,j;
	double dis;
	Point a[205];
	int casenum=0;
	while(scanf("%d",&n),n!=0)
	{
		if (casenum) putchar('\n');
		++casenum;
		for(i=1;i<=n;++i)
		{
			cin>>a[i].x>>a[i].y;
		}
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=n;++j)
			{
				G[i][j]=distance1(a[i],a[j]);
			}
		}
		dis=Dijkstra(n,1,2);
		printf("Scenario #%d\n",casenum);
		printf("Frog Distance = %.3lf\n",dis);
	}

	return 0;
}