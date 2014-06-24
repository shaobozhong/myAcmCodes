/*
ID:shaoboz2
PROG: milk2
LANG: C++
*/
#include <iostream>

#include <string>
using namespace std;

typedef struct node 
{
	struct node *next;
	int begin,end;
}List;


void insert(List *head,int begin,int end)
{
	List *q,*p=head->next;
	q=new List;
	q->begin=begin;
	q->end=end;
	if (p==NULL||begin<p->begin)
	{
		head->next=q;
		q->next=p;
		return;
	}
	while(p->next)
	{
		if (begin<p->next->begin)
			break;
		p=p->next;
	}
	q->next=p->next;
	p->next=q;
}

int main() 
{
	
	int n,begin,end,emax,nmax,etemp,ntemp,i,max;
	List head;
	List *p,*q;
	
	while(cin>>n)
	{
		head.next=NULL;
	for(i=1;i<=n;i++)
	{
		cin>>begin>>end;
		insert(&head,begin,end);
	}
	p=head.next;
	etemp=emax=p->end-p->begin;
	ntemp=nmax=0;
	max=p->end;
	q=p;
	p=p->next;
	while(p)
	{
		if (p->end>max)
		{
			if (p->begin<=max)
			{
				etemp+=p->end-max;
				ntemp=0;
			}
			else 
			{
				ntemp=p->begin-max;
				etemp=p->end-p->begin;
			}
			if (etemp>emax) emax=etemp;
			if (ntemp>nmax) nmax=ntemp;
			if (p->end>max) max=p->end;
		}
		p=p->next;
		q=q->next;
	}
	cout<<emax<<" "<<nmax<<endl;
	}
	return 0;
}