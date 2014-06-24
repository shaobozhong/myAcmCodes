#include<iostream>
#include<vector>
using namespace std;
int link[505];
bool vis[505];

struct Task
{
	int ex,ey;
	int ss,ee;//起始 和到达时间
};

struct node
{
	vector <int> follow;
};


node map[505];

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
	int n;
	int i,j;
    int t;
	int h,mi;
	char ch;
	int count1;
	int sx,sy;
	int cost;
	Task task[505];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;++i)
		{
			link[i]=-1;
		}
		
		for(i=0;i<n;++i)
		{
			scanf("%d%c%d",&h,&ch,&mi);
			task[i].ss=h*60+mi;
			scanf("%d%d",&sx,&sy);
            scanf("%d%d",&task[i].ex,&task[i].ey);
			task[i].ee=task[i].ss+abs(task[i].ey-sy)+abs(task[i].ex-sx);
			for(j=0;j<i;++j)
			{
				cost=abs(sx-task[j].ex)+abs(sy-task[j].ey);
				if (task[j].ee+cost<task[i].ss)
				{
					map[i].follow.push_back(j);
				}
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

		printf("%d\n",n-count1);

		for(i=0;i<n;++i)
		{
			map[i].follow.clear();
		}
	}
	return 0;
}

