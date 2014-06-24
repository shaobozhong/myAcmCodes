#include<iostream>
#include<vector>
using namespace std;

struct point 
{
	int x,y;
};

struct Node
{
	vector <point> follow;
};
int n;
Node a[25];
bool panduan(int p,int s,int e)
{
	int len=e-s+1;
	int x,y;
	int i,j;
	if (len!=int(a[p].follow.size())) return false;
	x=a[p].follow[0].x-a[n].follow[s].x;
	y=a[p].follow[0].y-a[n].follow[s].y;
	for(i=s,j=0;i<=e;++i , ++j)
	{
		if (a[p].follow[j].x!=a[n].follow[i].x+x || a[p].follow[j].y!=a[n].follow[i].y+y) break;
	}
	if (i>e) return true;


	for(i=s,j=int(a[p].follow.size())-1;i<=e;++i,--j)
	{
		if (a[p].follow[j].x!=a[n].follow[i].x || a[p].follow[j].y!=a[n].follow[i].y) break;
	}
	if (i>e) return true;


	x=a[p].follow[0].x-a[n].follow[s].y;
	y=a[p].follow[0].y-a[n].follow[s].x;


	for(i=s,j=0;i<=e;++i,++j)
	{
		if (a[p].follow[j].x!=a[n].follow[i].y+x || a[p].follow[j].y!=a[n].follow[i].x+y) break;
	}
	if (i>e) return true;

	for(i=s,j=int(a[p].follow.size())-1;i<=e;++i,--j)
	{
		if (a[p].follow[j].x!=a[n].follow[i].y+x || a[p].follow[j].y!=a[n].follow[i].x+y) break;
	}
	if (i>e) return true;
	return false;
}


int main()
{
	
	point tmp;
	int i,j,k;
	int count1,count2,len;
	int res[35];
	while(scanf("%d",&n),n!=0)
	{
        count1=0;
		for(i=0;i<n;++i)
		{
			scanf("%d%d",&tmp.x,&tmp.y);
			a[i].follow.push_back(tmp);
			while(scanf("%d%d",&tmp.x,&tmp.y),tmp.x!=a[i].follow[0].x || tmp.y!=a[i].follow[0].y)
			{
				a[i].follow.push_back(tmp);
			}
			a[i].follow.push_back(tmp);
			count1+=int(a[i].follow.size());
		}

		for(i=0;i<count1;++i)
		{
			scanf("%d%d",&tmp.x,&tmp.y);
			a[n].follow.push_back(tmp);
		}
		count2=1;
		for(i=0;i<count1;++i)
		{
			for(j=i+1;j<count1;++j)
			{
				if (a[n].follow[j].x==a[n].follow[i].x && a[n].follow[j].y==a[n].follow[i].y) break;
			}
			for(k=0;k<n;++k)
			{
				if (panduan(k,i,j)) 
				{
					res[k]=count2++;
					break;
				}
			}
		}

		for(i=0;i<n;++i)
		{
			printf("%d ",res[i]);
		}
	}
	return 0;
}