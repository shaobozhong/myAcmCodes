#include<iostream>
#include<algorithm>
using namespace std;

struct Edge
{
	int x,y,d;
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
	Edge edge[5000];
	int state;
	while(scanf("%d",&n),n!=0)
	{
		for(i=0;i<=n;++i)
		{
			father[i]=i;
		}
		m=n*(n-1)/2;
		for(i=0;i<m;++i)
		{
			scanf("%d%d%d%d",&edge[i].x,&edge[i].y,&edge[i].d,&state);
			if (state==1) edge[i].d=0;
		}
		sort(edge,edge+m,cmp);
		int sum=0;
		for(i=0,j=0;j!=n-1&&i<m;++i)
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
		printf("%d\n",sum);
	}
}


