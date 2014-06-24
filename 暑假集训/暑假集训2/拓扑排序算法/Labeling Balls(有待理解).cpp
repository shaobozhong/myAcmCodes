#include<iostream>
using namespace std;

struct node
{
	int num;
	struct node *next;
};

struct Elem
{
	int degree;
	struct node *next;
};
int n,m;
Elem t[205];
int res[205];

void topsort()
{
	int i;
	int count1;
	node *p;
	int lable;
	count1=n;

	while(1)
	{
		lable=-1;
		for(i=n;i>=1;--i)
		{
			if (t[i].degree==0) {break;}
		}
		if (i==0) break;
		res[i]=count1--;
		--(t[i].degree);
		p=t[i].next;
		while(p)
		{
			--(t[p->num].degree);
			p=p->next;
		}
	}


	if (count1>0) puts("-1");
	else 
	{
		for(i=1;i<n;++i)
		{
			printf("%d ",res[i]);
		}
		printf("%d\n",res[i]);
	}

}

int main()
{
	int casenum;
	int i,a,b;
	node *q;
	scanf("%d",&casenum);
	while(casenum--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;++i)
		{
			t[i].degree=0;
			t[i].next=NULL;
		}
		while(m--)
		{
			scanf("%d%d",&a,&b);
			++t[a].degree;
			q=new node;
			q->num=a;
			q->next=t[b].next;
			t[b].next=q;
		}
		topsort();
	}
	return 0;
}
