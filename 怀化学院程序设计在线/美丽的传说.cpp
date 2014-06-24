#include<iostream>
#include<queue>
using namespace std;




struct node
{
	int num;
	int dis;
	struct node *next;
};

struct Map
{
	int dis;
	struct node *next;
};



int main()
{
	int n;
	Map m[10005];
	int count2[10005];
	bool vis[10005];
	int i,j,a,b,dis;
	int max1;
	node *q;
	queue<int> que;
	int top;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		max1=0;
		for(i=0;i<=n;++i)
		{
			count2[i]=0;
			m[i].next=NULL;
		}
		for(i=1;i<n;++i)
		{
			scanf("%d%d%d",&a,&b,&dis);
			q=new node;
			q->num=b;
			q->dis=dis;
			q->next=m[a].next;
			m[a].next=q;

			q=new node;
			q->num=a;
			q->dis=dis;
			q->next=m[b].next;
			m[b].next=q;
			++count2[a];
			++count2[b];
		}

		for(i=1;i<=n;++i)
		{

			if (count2[i]>=2) continue;
			for(j=1;j<=n;++j)
			{
				vis[j]=true;
			}
			m[i].dis=0;
			vis[i]=false;
			que.push(i);
			while(!que.empty())
			{
				top=que.front();
				que.pop();
				q=m[top].next;
				while(q)
				{
					if (vis[q->num])
					{
						vis[q->num]=false;
						m[q->num].dis=m[top].dis+q->dis;
						if (max1<m[q->num].dis) max1=m[q->num].dis;
						que.push(q->num);
					}
					q=q->next;
				}
			}
		}

		printf("%d\n",max1);
	}
	return 0;
}