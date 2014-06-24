#include<iostream>
#include<vector>
using namespace std;

struct node
{
	vector<int> follow;
};
bool vis[51];
int link[205][51];
bool vis1[205];

node map[205];

bool can(int step,int r)
{
	int i;
	if (r==-1) return false;
	for (i=0;i<(int)(map[r].follow).size();++i)
	{
		if (vis[map[r].follow[i]])
		{
			vis[map[r].follow[i]]=false;
			if (link[step][map[r].follow[i]]==-1||can(step,link[step][map[r].follow[i]]))
			{
				vis1[r]=true;
				link[step][map[r].follow[i]]=r;
				vis[map[r].follow[i]]=false;
				return true;
			}
		}
	}
	return false;
}


int main()
{
	int t;
	int m,f,k,num;
	int i,j;
	int step,count1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&f);
		for(i=0;i<m;++i)
		{
			vis1[i]=false;
		}
		for(i=0;i<f;++i)
		{
			scanf("%d",&k);
			while(k--)
			{
				scanf("%d",&num);
				map[num].follow.push_back(i);
			}
		}

		for(i=0;i<m;++i)
		{
			if (int(map[i].follow.size())==0) break;
		}

		if (i<m) {puts("impossible");continue;}
		step=0;
		while(1)
		{

			for(i=0;i<f;++i)
			{
				link[step][i]=-1;
			}
			count1=0;
			for(i=0;i<m;++i)
			{
				if (vis1[i]) continue;
				for(j=0;j<f;++j)
				{
					vis[j]=true;
				}
				if (can(step,i)) ++count1;
			}

			for(i=0;i<m;++i)
			{
				if (vis1[i]) continue;
				for(j=0;j<int(map[i].follow.size());++j)
				{
					for(k=0;k<step;++k)
					{
						if (can(step,link[k][map[i].follow[j]])) {vis1[i]=true;count1++;link[k][map[i].follow[j]]=i;}
					}
				}
			}
			if (count1==0) break;
			++step;
		}
		printf("%d\n",step);

		for(i=0;i<m;++i)
		{
			map[i].follow.clear();
		}

	}
	return 0;
}
