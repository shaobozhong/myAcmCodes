#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

struct node
{
	struct node *next;
	int a[6];
};
node sum[100001];

bool compare(int a[6],int b[6])
{
	for(int i=0;i<6;++i)
	{
		if (a[i]!=b[i]) return false;
	}
	return true;
}

bool panduan(int a[6],int la)
{
	int i;
	node *p;
	p=sum[la].next;
	while(p)
	{
		for(i=1;i<=6;++i)
		{
			rotate(a,a+1,a+6);
		    if (compare(a,p->a)) return true;
		}

		reverse(a,a+6);
		for(i=1;i<=6;++i)
		{
			rotate(a,a+1,a+6);
		    if (compare(a,p->a)) return true;
		}
        reverse(a,a+6);
		p=p->next;
	}
	return false;
}

int main()
{
    int n;
	int i;
	node *q;
	int sum1;
    int a[6];
	
	scanf("%d",&n);
	for(i=0;i<100001;++i)
	{
		sum[i].next=NULL;
	}
	bool res=false;
	while(n--)
	{
		scanf("%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5]);
		sum1=a[0]+a[1]+a[2]+a[3]+a[4]+a[5];
		int la=sum1%99991;
		if (panduan(a,la))
		{
			res=true;
			while(n--)
			{
				scanf("%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5]);
			}
			break;
		}
		
        q=new node;
		for(i=0;i<6;++i)
		{
			q->a[i]=a[i];
		}
		q->next=sum[la].next;
		sum[la].next=q;
	}
	if (res) puts("Twin snowflakes found.");
	else puts("No two snowflakes are alike.");
	return 0;
}