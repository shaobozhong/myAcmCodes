#include<iostream>
using namespace std;

typedef struct node
{
	struct node *next;
	int data;
}LNode;

int main()
{
	LNode a,b,c;
	LNode *p,*q,*r,*s;
	int t,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n;
		p=&a;
		while(n--)
		{
			q=new LNode;
			cin>>q->data;
			p->next=q;
			p=q;
		}
		p->next=NULL;
		cin>>m;
		p=&b;
		while(m--)
		{
			q=new LNode;
			cin>>q->data;
			p->next=q;
			p=q;
		}
		p->next=NULL;

		p=a.next;
		q=b.next;
		r=&c;
		while(p&&q)
		{

			if (p->data<q->data)
			{
				s=new LNode;
				s->data=p->data;
				r->next=s;
				r=s;
				p=p->next;
			}
			else 
			{
				if (p->data==q->data)
				{
					if (r->data!=p->data)
					{
						s=new LNode;
						s->data=p->data;
						r->next=s;
						r=s;
					}
					p=p->next;
					q=q->next;
				}
				else 
				{
					s=new LNode;
					s->data=q->data;
					r->next=s;
					r=s;
					q=q->next;
				}
			}
		}
        if (p)//其实是不能直接接上的
		{
			r->next=p;
		}
		else 
		{
			if (q)
			{
				r->next=q;
			}
			else
			{
				r->next=NULL;
			}
		}
		p=c.next;
		while(p)
		{
			cout<<p->data<<" ";
			p=p->next;
		}
		cout<<endl;
	}
	return 0;
}