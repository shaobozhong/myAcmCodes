#include<iostream>
#include<vector>
using namespace std;
int link[10001];
bool vis[10001];

struct node
{
	vector <int> follow;
};


node map[10001];

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
				    return true;
				}
		}
	}
	return false;
}


int main()
{
	int n;
	int x,y;
	int i,j,k;
	int count1;
    while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;++i)
		{
			link[i]=-1;
		}

		for(i=0;i<n;++i)
		{
			scanf("%d",&x);
			getchar();
			getchar();
			getchar();
			scanf("%d",&k);
			getchar();
			for(j=0;j<k;++j)
			{
				scanf("%d",&y);
				y-=n;
				map[x].follow.push_back(y);
			}
		}
        count1=0;
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{
				vis[j]=true;
			}
			if (can(i)) ++count1;
		}
		printf("%d\n",count1);
		for(i=0;i<n;++i)
		{
			map[i].follow.clear();
		}
	}
	return 0;
}

