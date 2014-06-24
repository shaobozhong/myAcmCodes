#include<iostream>
using namespace std;

struct Node
{
	struct Node *next;
	int s;
};

int *begin,_count;

struct para
{
	int begin,end;
	Node *next;
	Node *thelast;
};

para *a;
int n,m,i;

void Go_to(int l,int k)
{
	Node *p,*q;
	int i,temp;
	if (a[l].begin==-1)
	{
		begin[_count]=l;
		a[l].begin=_count;
		//a[l].end=l;
		q=new Node;
		q->s=k;
		q->next=NULL;
		a[l].next=q;
		a[l].thelast=q;
		a[l].thelast->next=NULL;
		_count++;
	}
	else
	{
		while (a[begin[a[l].begin]].end+1<=m&&a[a[begin[a[l].begin]].end+1].begin!=-1)
		{
			temp=begin[a[a[begin[a[l].begin]].end+1].begin];
			for (i=0;i<_count;++i)
			{
				if (begin[i]==temp)
				{
					begin[i]=begin[a[l].begin];
				}
			}
			a[begin[a[l].begin]].thelast->next=a[a[begin[a[l].begin]].end+1].next;
			a[begin[a[l].begin]].thelast=a[a[begin[a[l].begin]].end+1].thelast;
			a[begin[a[l].begin]].end=a[a[begin[a[l].begin]].end+1].end;
		}
		if (l==begin[a[l].begin])
		{
			q=new Node;
			q->s=k;
			q->next=a[begin[a[l].begin]].next;
			a[begin[a[l].begin]].next=q;
		}
		else 
		{
			p=a[begin[a[l].begin]].next;
			i=1;
			while (i<=l-begin[a[l].begin]-1)
			{
				p=p->next;
				i++;
			}
			q=new Node;
			q->s=k;
			q->next=p->next;
			p->next=q;
		}
		a[begin[a[l].begin]].end++;
		if (a[begin[a[l].begin]].end<=m) a[a[begin[a[l].begin]].end].begin=a[l].begin;
	}
}
int main()
{
	int i,p;
	Node *q;
	//freopen("1.txt","r",stdin);
	//freopen("2.txt","w",stdout);
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		_count=0;
		a=new para[m+1];
		begin=new int[m+1];
		memset(begin,0,sizeof(begin));
		for (i=1;i<=m;++i)
		{
			a[i].next=NULL;
			a[i].thelast=NULL;
			a[i].begin=-1;
			a[i].end=i;
		}

		for (i=1;i<=n;++i)
		{
			scanf("%d",&p);
			Go_to(p,i);
		}

		for (i=1;i<=m;++i)
		{
			if (a[i].begin==-1) puts("0");
			else 
			{
				q=a[i].next;
				printf("%d\n",q->s);
				q=q->next;
				while (q)
				{
					i++;
					printf("%d\n",q->s);
					q=q->next;
				}
			}
		}
	}
	return 0;
}