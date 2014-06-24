#include<iostream>
using namespace std;

typedef struct node
{
	struct node *front,*next;
	int data;
}Node;



void creat(Node *head,int n)
{
	int i;
	Node *p,*q;
	p=head;
	head->front=NULL;
	head->next=NULL;
	if (n>0)
	{
		cin>>head->data;
		for(i=2;i<=n;i++)
		{
           q=new Node;
		   cin>>q->data;
		   p->next=q;
		   q->front=p;
		   p=q;
		}
		p->next=NULL;
	}
}

void pri(Node *head)
{
  Node *p=head;
  do
  {
	  cout<<p->data<<" ";
	  p=p->next;
	  if (!p->next) cout<<p->data<<" "; 
  }while(p->next);
  do
  {
	  cout<<p->data<<" ";
	  p=p->front;
  }while(p);
}


int main()
{
	int n;
	Node *head; 
	head=new Node;
	cin>>n;
	creat(head,n);
	pri(head);
	return 0;
}