#include<iostream>
using namespace std;

typedef struct node 
{
	int s,e;
	struct node *next;
}ylength;

typedef struct 
{
	ylength *next;
}Xelem;

int calc(Xelem elem)
{
	int leny;
	ylength *p,*q;
	p=elem.next;
	while(p)
	{
		if (p->next&&(p->e>p->next->s)) 
		{
			p->e=p->e>p->next->e?p->e:p->next->e;
			q=p->next;
			p->next=p->next->next;
			free(q);
		}
		else
		{
			p=p->next;
		}
	}
	p=elem.next;
	leny=0;
	while(p)
	{
		leny+=p->e-p->s;
		p=p->next;
	}

	return leny;
}

int main()
{
	Xelem a[100001];
	ylength *p,*q;
	int t,n,x1,x2,y1,y2,i,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		sum=0;
		for(i=1;i<100001;i++)
		{
			a[i].next=NULL;
		}
		while(n--)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			for(i=x1;i<x2;i++)
			{
				if ((!a[i].next)||(a[i].next&&a[i].next->s>=y2))
				{
					q=(ylength *) malloc(sizeof(ylength));
					q->s=y2;
					q->e=y1;
					q->next=a[i].next;
					a[i].next=q;
					continue;
				}
				p=a[i].next;
				while(p->next&&p->next->s<y2)
				{
					p=p->next;
				}
				q=(ylength *) malloc(sizeof(ylength));
				q->s=y2;
				q->e=y1;
				q->next=p->next;
				p->next=q;
			}
		}
		for(i=1;i<100001;i++)
		{
			sum+=calc(a[i]);
		}

		printf("%d\n",sum);
	}
	return 0;
}