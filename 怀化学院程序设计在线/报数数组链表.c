#include<stdio.h>
struct baoshu
{
	int v;
	struct baoshu *next;
};
struct baoshu a[1000001];

void quan(int n)
{
	int i;
	for(i=0;i<=n-1;i++)
	{
		a[i].next=&a[i+1];
		a[i].v=i+1;
	}	
	a[n-1].next=&a[0];
} 


void baoshu(int k)
{ 
	struct baoshu *p1;
	int i=1;
	p1=a;
	while(p1->next!=p1)
	{
		if ((i+1)%k==0) {p1->next=(p1->next)->next;i++;}
		p1=p1->next;
		i++;
	}
	printf("%d\n",p1->v);
}

int main()
{int n,k;
   
	
	while(scanf("%d%d",&n,&k)>0&&n!=0||k!=0)
	{   if (k==1) {printf("%d\n",n);continue;}
		quan(n);
	    baoshu(k);
	}
	return 0;
}