#include<iostream>
#include <set>
using namespace std;
 int map[1001][1001];
 int dis[1001],rdis[1001];

 void work(int *dis,int n,int d)
 {
	 int i,j,minl;
	 set<int> vis;
	 dis[0]=INT_MAX;
	 dis[d]=0;
	 for (i=1;i<=n-1;++i)
	 {
		 minl=0;
		 for (j=1;j<=n;++j)
		 {
			 if (dis[j]<dis[minl]&&vis.find(j)==vis.end()) {minl=j;}
		 }
         vis.insert(minl);
		 for (j=1;j<=n;++j)
		 {
	
			 if (map[minl][j]!=0&&dis[j]>dis[minl]+map[minl][j]) dis[j]=dis[minl]+map[minl][j];
		 }
	 }
	 vis.clear();
 }

int main()
{
    int n,m,x,i,j,s,d,w,temp,max;
	while (scanf("%d%d%d",&n,&m,&x)!=EOF)
	{
		max=0;
		for (i=1;i<=n;++i)
		{
			for (j=1;j<=n;++j)
			{
				map[i][j]=0;
			}
		}

		for (i=1;i<=m;++i)
		{
			scanf("%d%d%d",&s,&d,&w);
			if (!map[s][d]||map[s][d]>w) map[s][d]=w;
		}
         
		for (i=1;i<=n;++i)
		{
			dis[i]=INT_MAX;
			rdis[i]=INT_MAX;
		}

	work(dis,n,x);
	for (i=1;i<=n;++i)
	{
		for (j=i+1;j<=n;++j)
		{
			temp=map[i][j];
			map[i][j]=map[j][i];
			map[j][i]=temp;
			
		}
	}
	work(rdis,n,x);
    for (i=1;i<=n;++i)
    {
	    if (j==x) continue;
		if (max<dis[i]+rdis[i])
		{
			max=dis[i]+rdis[i];
		}
    }
	printf("%d\n",max);
	}
	return 0;
}