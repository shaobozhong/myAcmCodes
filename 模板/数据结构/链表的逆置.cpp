#include<iostream>
using namespace std;

typedef struct list
{
	list *next;
	int data;
}List;

void creat(List *head,int n)
{int i;
List *p,*q;
head->next=NULL;
p=head;
for(i=1;i<=n;i++)
{
	q=new List;
	cin>>q->data;
	p->next=q;
	p=q;
}
p->next=NULL;
}

void back(List *head,int n)
{
	int i;
	List *p,*q,*r;
	p=head->next;
	q=p->next;
	r=p;
	p->next=NULL;

	for(i=1;i<=n-1;i++)
	{
		p=q;
		q=p->next;
		p->next=r;
        r=p;
	}
head->next=p;
}


void pri(List *head)
{
	List *p;
	p=head->next;
	while(p)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

int main()
{
	List *head;
	int n;
	cin>>n;
	head=new List;
	creat(head,n);
	back(head,n);
	pri(head);
	return 0;
}