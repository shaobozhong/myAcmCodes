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
	int t;
	int m,f,k,num;
	int i,j;
	int step,count1,tmp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&f);
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
			++step;
			if (step>1)
			{
				for(i=0;i<m;++i)
				{
					tmp=int(map[i].follow.size())/(step-1);
					for(j=0;j<tmp;++j)
					{
						map[i].follow.push_back(map[i].follow[j]+f*(step-1));
					}
				}
			}

			for(i=0;i<step*f;++i)
			{
				link[i]=-1;
			}

			count1=0;
			for(i=0;i<m;++i)
			{
				for(j=0;j<step*f;++j)
				{
					vis[j]=true;
				}
				if (can(i)) ++count1;
			}
			if (count1==m) break;

		}

		printf("%d\n",step);
		for(i=0;i<m;++i)
		{
			map[i].follow.clear();
		}

	}

	return 0;
}

