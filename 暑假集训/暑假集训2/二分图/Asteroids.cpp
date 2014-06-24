#include<iostream>
#include<vector>
using namespace std;
int link[605];
bool vis[605];

struct node
{
	vector <int> follow;
};


node map[605];

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
	int n,m;
	int x,y;
	int count1;
	int i,j;

	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=1;i<=n;++i)
		{
			link[i]=-1;
		}
		while(m--)
		{
			scanf("%d%d",&x,&y);
			map[x].follow.push_back(y);
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

		printf("%d\n",count1);

		/*for(i=1;i<=n;++i)
		{
			map[i].follow.clear();
		}*/
	}
	return 0;
}