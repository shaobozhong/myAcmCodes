#include<iostream>
using namespace std;


struct node
{
	int num;
	struct node *next;
};

struct Elem 
{
	int degree,wage;
	struct node *next;
};


int n,m;
Elem t[10005];
int tmp[10005];
void topsort()
{

	bool la;
	int i,count1,count2, sum;;
	node *p;
	count2=0;
	sum=0;
	while(1)
	{
		count1=0;
		for(i=1;i<=n;++i)
		{
			if (t[i].degree==0) tmp[count1++]=i;
		}
		if (count1==0) break;
		count2+=count1;
		for(i=0;i<count1;++i)
		{
			sum+=t[tmp[i]].wage;
			p=t[tmp[i]].next;
			--(t[tmp[i]].degree);
			while(p)
			{
				--(t[p->num].degree);
				if (t[p->num].wage<t[tmp[i]].wage+1) t[p->num].wage=t[tmp[i]].wage+1;
				p=p->next;
			}
		}
	}

	if (count2<n) puts("-1");
	else printf("%d\n",sum);

}

int main()
{

	int a,b,i;
	node *q;
	while(scanf("%d%d",&n,&m)!=EOF)
	{

		for(i=1;i<=n;++i)
		{
			t[i].degree=0;
			t[i].wage=888;
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