#include<iostream>
using namespace std;

typedef struct node
{
	int speed;
	struct node *next;
}horse;


void insert(horse *head,int speed)
{
	horse *p=head->next,*q;
	q=new horse;
	q->speed=speed;
	if (p==NULL||p->speed<=speed)
	{
		head->next=q;
		q->next=p;
		return;
	}
    while(p->next)
	{
		if (p->next->speed<=speed) break;
		p=p->next;
	}
	q->next=p->next;
	p->next=q;
}

int main()
{
	horse my,op,*p,*q;
	int n,speed,money,i,count;
	
	while(cin>>n,n!=0)
	{
		count=0;
		my.next=NULL;
	    op.next=NULL;
		money=0;
		for(i=1;i<=n;i++)
		{
			cin>>speed;
			insert(&my,speed);
		}
		for(i=1;i<=n;i++)
		{
			cin>>speed;
			insert(&op,speed);
		}
		p=my.next;
		
		while(p)
		{
			q=op.next;
			while(q)
			{
				if (p->speed>=q->speed) {if (p->speed>q->speed) money+=200; op.next=q->next;count++;break;}
				q=q->next;
			}
			if (q==NULL) break;
			p=p->next;
		}
		cout<<money-(n-count)*200<<endl;
	}
	return 0;
}