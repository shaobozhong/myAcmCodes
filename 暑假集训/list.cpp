#include<iostream>
using namespace std;

typedef struct node 
{
	int num;
	struct node *next;
}list;

void creatlist(list &head)
{
	list *p,*q;
	int num;
    p=&head;
	while(cin>>num)
	{
		q=new list;
		q->num=num;
		p->next=q;
		p=q;
	}
	p->next=NULL;
}

void print(list &head)
{
	list *p;
	p=head.next;
	while(p)
	{
		cout<<p->num<<" ";
		p=p->next;
	}
	cout<<endl;
}

int main()
{
	list head;
	creatlist(head);
	print(head);
	return 0;
}