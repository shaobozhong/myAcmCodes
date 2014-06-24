#include<iostream>
#include<vector>
using namespace std;

int link[301];
bool vis[301];

struct COURSE
{
	vector <int> stu;
};

COURSE c[101];

bool can(int r)
{
	int i;
	if (r==-1) return false;
	for (i=0;i<(int)(c[r].stu).size();++i)
	{
		if (vis[c[r].stu[i]])
		{
			vis[c[r].stu[i]]=false;
				if (link[c[r].stu[i]]==-1||can(link[c[r].stu[i]]))
				{
					link[c[r].stu[i]]=r;
				    vis[c[r].stu[i]]=false;
				    return true;
				}
		}
	}
	return false;
}

int main()
{
	int t,n,p,m,temp,i,j,_count;
	
	scanf("%d",&t);
	while (t--)
	{
		_count=0;
		scanf("%d%d",&p,&n);
		for (i=0;i<=n;++i)
		{
			link[i]=-1;
		}
		for (i=1;i<=p;++i)
		{
			scanf("%d",&m);
			for (j=0;j<m;++j)
			{
				scanf("%d",&temp);
				c[i].stu.push_back(temp);
			}
		}
		for (i=1;i<=p;i++)
		{
			for (j=0;j<=n;++j)
			{
				vis[j]=true;
			}
			if (can(i)) _count++;
			else break;
		}
		if (i<=p) puts("NO");
		else puts("YES");
		for (i=1;i<=p;++i)
		{
			c[i].stu.clear();
		}
	}
	return 0;
}