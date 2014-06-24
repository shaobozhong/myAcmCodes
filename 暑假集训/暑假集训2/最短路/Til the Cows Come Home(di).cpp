#include<iostream>
using namespace std;
#define MAX 1005

int G[MAX][MAX];

int Dijkstra(int n,int s,int t)
{
	int i,j,w,minc,d[MAX],mark[MAX];
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
	for (i=2;i<=n;i++)
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
			if ((mark[j]==0)&&(G[w][j]!=INT_MAX)&&(d[j]>d[w]+G[w][j]))
			{ 
				d[j]=d[w]+G[w][j];
			}
		}
	}
	return d[t];
}





int main()
{
	int n,m;
	int i,j,dis;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		for(i=0;i<=n;++i)
		{
			for(j=0;j<=n;++j)
			{
				G[i][j]=INT_MAX;
			}
		}
		while(m--)
		{
			scanf("%d%d%d",&i,&j,&dis);
			if (G[i][j]>dis)
			{
				G[i][j]=dis;
				G[j][i]=dis;
			}
		}
		dis=Dijkstra(n,1,n);
		printf("%d\n",dis);
	}

	return 0;
}