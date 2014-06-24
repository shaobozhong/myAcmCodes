#include<iostream>
using namespace std;

struct node
{
	int num;
	struct node *next;
};

struct Elem
{
	int degree;
	struct node *next;
};

Elem a[505];
int res[505];
int n,m;

void topsort()
{
	
	int i,count1;
	struct node *p;
	bool la;
	count1=0;
	la=true;
	while(la)
	{
		la=false;
		for(i=1;i<=n;++i)
		{
			if (a[i].degree==0) {la=true;break;}
		}
		if (!la) break;
		a[i].degree-=1;
			p=a[i].next;
		res[count1++]=i;
		while(p)
		{
			--(a[p->num].degree);
			p=p->next;
		}
	}

	for(i=0;i<n-1;++i)
	{
		printf("%d ",res[i]);
	}
	printf("%d\n",res[i]);
}
int main()
{
	int i;
	int pre,next;
	node *q;

	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=1;i<=n;++i)
		{
			a[i].degree=0;
			a[i].next=NULL;
		}
		while(m--)
		{
			scanf("%d%d",&pre,&next);
			++a[next].degree;
			q=new node;
			q->num=next;
			q->next=a[pre].next;
			a[pre].next=q;
			/*p=a[pre].next;
			if (p->num>next) {q->num=a[pre].next;a[pre].next=q;}
			while(p->next && p->next->num>next)
			{
				p=p->next;
			}
			q->next=p->next;
			p->next=q;*/
		}

		topsort();
	}
	return 0;
}