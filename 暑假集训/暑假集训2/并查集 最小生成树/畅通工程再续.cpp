#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

struct point 
{
	int x,y;
};

struct Edge
{
	int x,y;
	double d;
};

int father[105];

bool cmp(const Edge &a,const Edge &b)
{
	return a.d<b.d;
}


int find1(int x)
{
	int i=x,j;
	while(father[x]!=x)
	{
		x=father[x];
	}

	/*while(father[i]!=x)//不进行压缩 速度还快一些
	{
	j=i;
	i=father[i];
	father[j]=x;
	}*/
	return x;
}


int main()
{
	int n,m;
	int i,j;
	int loc1,loc2;
	point p[101];
	Edge edge[10001];
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;++i)
		{
			scanf("%d%d",&p[i].x,&p[i].y);
			father[i]=i;
		}
		m=n*(n-1)/2;
		int la=0;
		for(i=0;i<n-1;++i)
		{
			for(j=i+1;j<n;++j)
			{

				double dis=sqrt(double((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y)));
				if (dis<10 || dis>1000 ) continue;
					edge[la].x=i;
				    edge[la].y=j;
					edge[la++].d=dis;
			}
		}
		sort(edge,edge+la,cmp);
		double sum=0;
		for(i=0,j=0;j!=n-1&&i<la;++i)
		{
			loc1=find1(edge[i].x);
			loc2=find1(edge[i].y);
			if (loc1!=loc2)
			{
				sum+=edge[i].d;
				father[loc2]=father[loc1];
				++j;
			}
		}
		if (j==n-1) printf("%.1lf\n",sum*100);
		else 
		{
			puts("oh!");
		}
	}
}


