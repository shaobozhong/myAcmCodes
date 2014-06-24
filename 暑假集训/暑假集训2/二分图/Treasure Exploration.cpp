#include<iostream>
#include<vector>
using namespace std;
int link[505];
bool vis[505];
bool map[505][505];

	int n,m;


bool can(int r)
{
	int i;
	if (r==-1) return false;
	for (i=1;i<=n;++i)
	{
		if (map[r][i] && vis[i])
		{
			vis[i]=false;
				if (link[i]==-1||can(link[i]))
				{
					link[i]=r;
				    return true;
				}
		}
	}
	return false;
}


int main()
{

	int x,y;
	int count1;
	int i,j,k;
	int t;
	while(scanf("%d%d",&n,&m),n!=0||m!=0)
	{

		for(i=1;i<=n;++i)
		{
			link[i]=-1;
		}
	    for(i=1;i<=n;++i)
		{
			for(j=1;j<=n;++j)
			{
				map[i][j]=false;
			}
		}
		while(m--)
		{
			scanf("%d%d",&x,&y);
			map[x][y]=true;
		}

		for(k=1;k<=n;++k)//需要用foloyd做一次 传递闭包
		{
			for(i=1;i<=n;++i)
			{
				for(j=1;j<=n;++j)
				{
					if (map[i][j]&&map[j][k]) map[i][k]=true;
				}
			}
		}
		count1=0;
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=n;++j)
			{
				vis[j]=true;
			}
			if (can(i)) ++count1;
		}

		printf("%d\n",n-count1);
	}
	return 0;
}