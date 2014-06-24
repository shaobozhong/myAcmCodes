#include<iostream>
using namespace std;

typedef struct node
{
	struct node *next;
	int data;
}Node;

typedef struct 
{
	Node *top;
}stack;


void push(stack *s,int n)
{
	Node *p=new Node;
	p->next=s->top;
	p->data=n;
	s->top=p;
}

void pull(stack*s)
{
	Node *p=s->top;
    s->top=p->next;
	free(p);

}

int main()
{
	stack s;
	int num,n,m,i;
	s.top=NULL;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
	cin>>num;
	while(num)
	{
		push(&s,num%m);
		num/=m;
	}
	while(s.top)
	{
		cout<<s.top->data;
		pull(&s);
	}
	cout<<endl;
	}
	return 0;
}