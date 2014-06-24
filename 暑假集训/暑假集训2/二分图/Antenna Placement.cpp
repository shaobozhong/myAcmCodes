#include<iostream>
#include<vector>
using namespace std;
int link[401];
bool vis[401];
char G[41][11];
int x,y;
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
struct node
{
	vector <int> follow;
};


node map[401];

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
	int h,w;
	int count1;
	int i,j,k;
	int t;
	int n;

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&h,&w);
		getchar();
		for(i=0;i<h;++i)
		{
			for(j=0;j<w;++j)
			{
				G[i][j]=getchar();
			}
			getchar();
		}

		for(i=0;i<h*w;++i)
		{
			link[i]=-1;
	
		}
		for(i=0;i<h;++i)
		{
			for(j=0;j<w;++j)
			{
				if (G[i][j]=='*')
				{
					for(k=0;k<4;++k)
					{
						if (i+dir[k][0]<0 || j+dir[k][1]<0 || i+dir[k][0]>=h || j+dir[k][1]>=w || G[i+dir[k][0]][j+dir[k][1]]!='*') continue;
						map[i*w+j].follow.push_back((i+dir[k][0])*w+j+dir[k][1]);
					}
				}
			}
		}
		count1=0;
		n=0;
		for(i=0;i<h*w;++i)
		{
			x=i/w;
			y=(i+1)%w;
			if (y==0) y=w;
			y-=1;
			if (G[x][y]=='*')
			{
				++n;

					for(j=0;j<h*w;++j)
					{
						vis[j]=true;
					}
					if (can(i)) ++count1;
			}
		}

		printf("%d\n",n-count1/2);

		for(i=1;i<h*w;++i)
		{
			map[i].follow.clear();
		}
	}
	return 0;
}