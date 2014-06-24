#include<iostream>
#include<vector>
using namespace std;
int link[1050];
bool vis[1050];
int  G[40][40];

int dir[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
struct node
{
	vector <int> follow;
};


node map[1050];

bool can(int r)
{
	int i;
	if (r==-1) return false;
	for (i=0;i<(int)(map[r].follow).size();++i)
	{
		if (vis[map[r].follow[i]])
		{
			vis[map[r].follow[i]]=false;
				if (link[map[r].follow[i]]==-1||can(link[map[r].follow[i]]))
				{
					link[map[r].follow[i]]=r;
				    vis[map[r].follow[i]]=false;
				    return true;
				}
		}
	}
	return false;
}


int main()
{
	int n,m,k;
	int x,y;
	int cnt;
	int i,j;
   
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=m;++j)
			{
				G[i][j]=0;
			}
		}

		while(k--)
		{
			scanf("%d%d",&x,&y);
			G[y][x]=-1;
		}
        cnt=0;
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=m;++j)
			{
				if (G[i][j]==0) 
				{
					G[i][j]=++cnt;
				}
				
			}
		}


		for(i=1;i<=n;++i)
		{
			for(j=1;j<=m;++j)
			{
				if (G[i][j]<0) continue;
				for(k=0;k<4;++k)
				{
					x=i+dir[k][0];
					y=j+dir[k][1];
					if (x<=0 || y<=0  || x>n || y>m  || G[x][y]<0) continue;
					{
						map[G[i][j]].follow.push_back(G[x][y]);
					}
				}
			}
		}


		for(i=1;i<=cnt;++i)
		{
			link[i]=-1;
		}

	

		for(i=1;i<=cnt;++i)
		{
			for(j=1;j<=cnt;++j)
			{
				vis[j]=true;
			}
			if (!can(i)) break;  
		}



		if (i<=cnt) puts("NO");
		else puts("YES");

		for(i=1;i<=cnt;++i)
		{
			map[i].follow.clear();
		}
	}
	return 0;
}