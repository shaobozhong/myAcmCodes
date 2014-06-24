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
	//if (r==-1) return false;
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
	int n,m,k;
	int x,y;
	int count1;
	int i,j;
    bool flag;
	while(scanf("%d",&n),n!=0)
	{
		flag=false;
		scanf("%d%d",&m,&k);
		for(i=0;i<m;++i)
		{
			link[i]=-1;
		}
		while(k--)
		{
			scanf("%d%d%d",&i,&x,&y);
			if (x==0||y==0) continue;//flag=true;
			map[x].follow.push_back(y);
		}
		count1=0;
		for(i=0;i<n;++i)
		{
			for(j=0;j<m;++j)
			{
				vis[j]=true;
			}
			if (can(i)) ++count1;
		}
        //if (flag) --count1;
		printf("%d\n",count1);

		for(i=0;i<n;++i)
		{
			map[i].follow.clear();
		}
	}
	return 0;
}