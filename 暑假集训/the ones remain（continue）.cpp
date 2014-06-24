#include<iostream>
using namespace std;

int n,m;

typedef struct node
{
	struct node *next;
	int number;
}elem;

void creat(elem head)
{
	int i;
	elem *p,*q;
	p=&head;
	head.next=NULL;
	for(i=1;i<=n;i++)
	{
		q=new elem;
		q->number=i;
		p->next=q;
		p=q;
	}
	p->next=NULL;
}

int main()
{
	int count=1;
    elem head,*p;
	while(scanf("%d%d",&n,&m)!=EOF&&(n!=0||m!=0))
	{
	creat(head);
	p=head.next;
	while(p->next!=p)
	{
		if (count==m-1) {p->next=p->next->next;count=0;}
		count++;
		p=p->next;
	}
	printf("%d\n",p->number);
	}
	return 0;
}