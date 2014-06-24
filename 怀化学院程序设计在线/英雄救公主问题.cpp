#include<iostream>
#include<cmath>
#include<queue>
using namespace std;

bool map[105][105];
bool vis[105][105];
int tan1[105][105];
int dir[4][2]={{0,-1},{-1,0},{1,0},{0,1}};

struct node
{
	int x,y;
	int step;
};


int main()
{
	int sx,sy,ex,ey;
	node tmp;
	int n,m;
	int x,y;
	int k;
	int res;
	queue<node> q;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		while(!q.empty())
		{
			q.pop();
		}
		int i,j;
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=m;++j)
			{
				map[i][j]=false;
				vis[i][j]=true;
			}
		}
		
		scanf("%d",&k);
		
		for(i=0;i<k;++i)
		{
			scanf("%d%d",&x,&y);
			scanf("%d",&tan1[x][y]);
			map[x][y]=true;
		}

		scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
		
		if (k==0) 
		{
			res=abs(sx-ex)+abs(sy-ey);
			printf("%d\n",res);
			continue;
		}
		
		tmp.x=sx;
		tmp.y=sy;
		tmp.step=0;
		q.push(tmp);
		vis[sx][sy]=false;
		node top;
		bool la=false;
		while(!la&&!q.empty())
		{
			top=q.front();
			q.pop();
			for(i=0;!la&&i<4;++i)
			{
				tmp.x=top.x+dir[i][0];
				tmp.y=top.y+dir[i][1];
				if (tmp.x==ex && tmp.y==ey)
				{
					res=top.step+1;
					la=true;
					break;
				}
				if (tmp.x<1||tmp.x>n ||tmp.y<1 || tmp.y>m) continue;
				if (vis[tmp.x][tmp.y])
				{
					while(map[tmp.x][tmp.y])
					{
						int x=tmp.x;y=tmp.y;
						tmp.x=x+dir[i][0]*tan1[x][y];
						tmp.y=y+dir[i][1]*tan1[x][y];
						if (tmp.x>n) tmp.x=n;
						else if (tmp.x<1) tmp.x=1;
						else if (tmp.y>m) tmp.y=m;
						else if (tmp.y<1) tmp.y=1;
					}
					vis[tmp.x][tmp.y]=false;
					if (tmp.x==ex && tmp.y==ey)
					{
						res=top.step+1;
						la=true;
						break;
					}

					if (!map[tmp.x][tmp.y])
					{
						tmp.step=top.step+1;
						q.push(tmp);
					}
				}
			}
		}
		if (la) printf("%d\n",res);
		else puts("Impossible");
	}
	return 0;
}