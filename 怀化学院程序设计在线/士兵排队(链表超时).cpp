#include <iostream>
using namespace std;


struct Node
{
	struct Node *next;
	int s;
};

struct Point
{
	Node *begin,*end;
};


int n,m;
void work(Point *a,int p,int i)
{
	Node *q;
	int j;
	if (!a[p].end)
	{
        q=new Node;
		q->s=i;
		q->next=NULL;
		a[p].begin=q;
		a[p].end=q;
	}
	else 
	{
		
		
		q=new Node;
		q->s=i;
		q->next=a[p].begin;
		a[p].begin=q;
		if(p>1&&a[p-1].end)
		{
			a[p-1].begin->next=q;
		}
		q=q->next;
		j=p+1;
		while (q&&j<=m)
		{
			if (a[j].begin) {a[p].end->next=a[j].begin;a[p].end=a[j].end;}
			a[j].begin=q;
		    //a[j].end=a[p].end; 
			q=q->next;
	        j++;
		}
	}
}

int main()
{
	Point *a;
	int i,p;
	Node *q;
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		a=new Point[m+1];
		for (i=0;i<=m;++i)
		{
			a[i].begin=NULL;
			a[i].end=NULL;
		}
		for (i=1;i<=n;++i)
		{
			scanf("%d",&p);
			work(a,p,i);
		}
        q=NULL;
		for (i=1;i<=m;++i)
		{
			if (!a[i].begin) puts("0");
			else 
			{
				q=a[i].begin;
				printf("%d\n",q->s);
				q=q->next;
			}
			while (q)
			{
				i++;
				if (a[i].begin==a[i].end) break;
				printf("%d\n",q->s);
				q=q->next;
			}
		}
	}
	return 0;
}
