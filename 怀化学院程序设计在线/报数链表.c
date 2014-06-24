#include<stdio.h>
#include<malloc.h>
#define null 0
#define  len sizeof (struct baoshu)  
struct baoshu
{   
	struct baoshu *next;
	int v;
};
struct baoshu *head;
struct baoshu *p1,*p2;

void creat(int n)
{

	int i;
	p1=p2=(struct baoshu*)malloc(len);
	p1->v=1;
	head=p1;
	for(i=2;i<=n;i++)
	{
		p2=p1;
		p1=(struct baoshu*)malloc(len);
		p2->next=p1;
		p1->v=i;
	}
	p1->next=head;
}

void baoshu(int k)
{
	int i=1;
	p1=head;
	while(p1->next!=p1)
	{
		if ((i+1)%k==0) {p1->next=(p1->next)->next;i=0;}
		p1=p1->next;
		i++;
	}
	printf("%d\n",p1->v);
}

int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k)>0&&n!=0||k!=0)
	{
		if (k==1) {printf("%d\n",n);continue;}
		creat(n);
		baoshu(k);
	}
	return 0;
}