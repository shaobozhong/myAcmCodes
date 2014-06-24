#include<iostream>
using namespace std;
#define MAX 105
double G[MAX][MAX];

double Dijkstra(int n,int s,int t)
{
	int i,j,w;
	double minc,d[MAX],mark[MAX];
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
		minc=0.0;
		w=0;
		for (j=1;j<=n;j++)
		{
			if ((mark[j]==0)&&(minc<d[j])) {minc=d[j];w=j;}
		}
		mark[w]=1;
		if (w==t) break;
		for (j=1;j<=n;j++)
		{
			if ((mark[j]==0)&&(G[w][j]!=0.0)&&(d[j]<d[w]*G[w][j]))
			{ 
				d[j]=d[w]*G[w][j];
			}
		}
	}
	return d[t];
}





int main()
{
	double dis;
	int n,m;
	int i,j;
	while(scanf("%d",&n),n!=0)
	{
		scanf("%d",&m);
		for(i=0;i<=n;++i)
		{
			for(j=0;j<=n;++j)
			{
				G[i][j]=0.0;
			}
		}
		while(m--)
		{
			scanf("%d%d%lf",&i,&j,&dis);
			    dis/=100;
				G[i][j]=dis;
				G[j][i]=dis;
		}
		dis=Dijkstra(n,1,n);
		printf("%.6lf percent\n",dis*100);
	}

	return 0;
}