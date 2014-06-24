#include<iostream>
using namespace std;
#define MAX 205
int G[MAX][MAX];


int Dijkstra(int n,int s,int k)
{
    int i,j,w,minc,d[MAX],mark[MAX];
    for (i=0;i<n;i++) mark[i]=0;
    for (i=0;i<n;i++)
        { 
			d[i]=G[s][i];
         }
    mark[s]=1;d[s]=0;w=s;
    for (i=1;i<=k;i++)
        {
       minc=INT_MAX;
        w=0;
        for (j=0;j<n;j++)
            if ((mark[j]==0)&&(minc>=d[j])) {minc=d[j];w=j;}
        mark[w]=1;
		if (i==k) break;
        for (j=0;j<n;j++)
        if ((mark[j]==0)&&(G[w][j]!=INT_MAX)&&(d[j]>d[w]+G[w][j]))
            { 
				d[j]=d[w]+G[w][j];
            }
        }
    return w;
}

int main()
{
	int n,m,k;
	int i,j,dis;
	while(scanf("%d",&n),n!=0)
	{
		scanf("%d",&m);
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{
				G[i][j]=INT_MAX;
			}
		}
		while(m--)
		{
			scanf("%d%d%d",&i,&j,&dis);//不存在两条连接相同城市的路
			G[i][j]=dis;
			G[j][i]=dis;
		}
		scanf("%d",&k);

		printf("%d\n",Dijkstra(n,0,k));
	}
	return 0;
}