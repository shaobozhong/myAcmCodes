#include<iostream>
using namespace std;
#define inf 999999999

struct Node
{
	struct Node *next;
	int la;
	int dis;
};


int n,m,x;
void dij(Node *map,int *dis)
{
	bool *vis;
	int i,times,min1,la;
	Node *p;
	vis=new bool[n+1];
	for(i=1;i<=n;++i)
	{
		vis[i]=false;
	}
	for(i=1;i<=n;++i)
	{
		dis[i]=inf;
	}
    dis[x]=0;
	vis[x]=false;
	p=map[x].next;
	while(p)
	{
		dis[p->la]=p->dis;
		p=p->next;
	}


	for(times=1;times<=n-1;++times)
	{
		min1=inf;
		la=-1;
        for(i=1;i<=n;++i)
		{
			if (min1>dis[i]&&!vis[i])  
			{
              min1=dis[i];
			  la=i;
			} 
		}
		vis[la]=true;
		p=map[la].next;
		while(p)
		{
			if (!vis[p->la]&&dis[p->la]>dis[la]+p->dis)
			{
				dis[p->la]=dis[la]+p->dis;
			}
			p=p->next;
		}
	}


}
int main()
{
    Node map[1005];
	int dis[1005];
	int dis1[1005];
    Node map1[1005];
	int a,b,distance;
	int ans;
	Node *q;
	int i;
    while(scanf("%d%d%d",&n,&m,&x)!=EOF)
	{
		for(i=1;i<=n;++i)
		{
			map[i].next=NULL;
			map1[i].next=NULL;
		}
         while(m--)
		 {
			 scanf("%d%d%d",&b,&a,&distance);
			 q=new Node;
			 q->la=b;
			 q->dis=distance;
			 q->next=map[a].next;
			 map[a].next=q;

			 q=new Node;
			 q->la=a;
			 q->dis=distance;
			 q->next=map1[b].next;
			 map1[b].next=q;
		 }

		 dij(map,dis);
		 dij(map1,dis1);
		 ans=dis[1]+dis1[1];
		 for(i=1;i<=n;++i)
		 {
			 
            if (ans<dis[i]+dis1[i]) ans=dis[i]+dis1[i];
		 }

		 printf("%d\n",ans);
	}
	return 0;
}