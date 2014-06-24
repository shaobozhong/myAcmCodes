#include<iostream>
using namespace std;

typedef struct node
{
	struct node *next;
	int number;
}elem;

int main()
{
	elem head;
	elem *a,*p;
	int n,m,k,i,count;
	while(scanf("%d%d%d",&n,&k,&m)>0&&n!=0||k!=0||m!=0)
	{
		a=new elem[n];
		for(i=1;i<n;i++)
		{
			a[i-1].number=i;
			a[i-1].next=&a[i];
		}
		a[i-1].number=n;
		a[i-1].next=a;

		count=0;
		p=&a[n-1];
		while(p->next!=p)
		{
			count++;
			if (count==m) {p->next=p->next->next;count=0;break;}
			p=p->next;
		}

		while(p->next!=p)
		{
			count++;
			if (count==k){p->next=p->next->next;count=0;continue;}
			p=p->next;
		}
		printf("%d\n",p->number);
	}
	return 0;
}