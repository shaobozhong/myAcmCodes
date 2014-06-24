#include<iostream>
using namespace std;

struct node
{
	int num;
	struct node *next;
};

struct Elem
{
	int dis,degree;
	struct node *next;
};

int n,m;

	Elem a[5005];
	Elem b[5005];
void topsort(Elem *a)
{
	int i;
	bool la;
	node *p;
	la=true;
	while(la)
	{
		la=false;
		for(i=1;i<=n;++i)
		{
			if (a[i].degree==0) {la=true;break;}
		}
		if (!la) break;
		--(a[i].degree);
		if (a[i].dis==0) a[i].dis=1;
		p=a[i].next;
		while(p)
		{
			--(a[p->num].degree);
			a[p->num].dis+=a[i].dis;
			p=p->next;
		}
	}
}

int main()
{

	int i;
	int pre,next;
	int max1;
	node *q;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=1;i<=n;++i)
		{
			a[i].degree=0;
			a[i].next=NULL;
			a[i].dis=0;
			b[i].degree=0;
			b[i].dis=0;
			b[i].next=NULL;
		}

		while(m--)
		{
			scanf("%d%d",&pre,&next);
			++a[next].degree;
			q=new node;
			q->num=next;
			q->next=a[pre].next;
			a[pre].next=q;


			++b[pre].degree;
			q=new node;
			q->num=pre;
			q->next=b[next].next;
			b[next].next=q;
		}


		topsort(a);
		topsort(b);
		max1=0;
		for(i=1;i<=n;++i)
		{
			q=a[i].next;
			while(q)
			{
				if (max1<a[i].dis*b[q->num].dis)  max1=a[i].dis*b[q->num].dis;
			    q=q->next;
			}
		}
		printf("%d\n",max1);
	}
	return 0;
}
