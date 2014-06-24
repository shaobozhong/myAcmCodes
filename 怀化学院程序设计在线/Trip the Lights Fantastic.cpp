#include<iostream>
using namespace std;
#define inf 99999999 
struct Light
{
	int sum,allow;
};
Light l[105];
int map[105][105];
int n,m,s,e;
int Dijkstra()
{
	int arraval[105];
	int dis[105];
	bool vis[105];
	int i,j;
	int pos;
	int min1,tmp,step,arravaltmp;
	for(i=0;i<n;++i)
	{
		arraval[i]=inf;
		dis[i]=inf;
		vis[i]=false;
	}
	arraval[s]=0;
	dis[s]=5;
	vis[s]=true;
	for(i=1;i<n;++i)
	{
		if (map[s][i]!=inf) 
		{
			arraval[i]=map[s][i]+dis[s];
			tmp=arraval[i]%l[i].sum;
			if (tmp<l[i].allow) tmp=0;
			else tmp=l[i].sum-tmp+5;
			dis[i]=arraval[i]+tmp;
		}
	}

	for(step=2;step<n;++step)
	{
		min1=INT_MAX;
		for(i=0;i<n;++i)
		{
			if (!vis[i]) 
			{
				if (dis[i]<min1) {min1=dis[i];pos=i;}
			}
		}
		vis[pos]=true;
		if (pos==e) break;
		for(i=0;i<n;++i)
		{
			if (!vis[i] && map[pos][i]!=inf )
			{
				arravaltmp=min1+map[pos][i];
				tmp=arravaltmp%l[i].sum;
				if (tmp<l[i].allow) tmp=0;
				else tmp=l[i].sum-tmp+5;
				tmp=arravaltmp+tmp;
				if (dis[i]>tmp) dis[i]=tmp;


				if (arraval[i]>min1+map[pos][i])
				{
				   arraval[i]=min1+map[pos][i];
				}
				
			}
		}
	}
	return arraval[e];
}

int main()
{
	int x,y,dis,ans;
	int i,j;
	int g,r;
	int h,m;
	while(scanf("%d%d%d%d",&n,&m,&s,&e),n!=0||m!=0||s!=0||e!=0)
	{
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{
				map[i][j]=inf;
			}
		}
		for(i=0;i<n;++i)
		{
			scanf("%d%d%d",&g,&y,&r);
			l[i].sum=g+y+r;
			l[i].allow=g+y;
		}

		while(m--)
		{
			scanf("%d%d%d",&x,&y,&dis);
			map[x][y]=dis;
			map[y][x]=dis;
		}
		ans=Dijkstra(); 
		h=ans/60;
		m=ans%60;
		if (m>=10) printf("%d:%d\n",h,m);
		else printf("%d:0%d\n",h,m);
	}
	return 0;
}

