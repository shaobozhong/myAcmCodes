#include<iostream>
using namespace std;

int n;

int lowbit(int x)
{
	return x &(x^(x-1));
}

void change(int *c)
{
	int p,num;
	scanf("%d%d",&p,&num);
	while(p<=n)
	{
		c[p]+=num;
		p+=lowbit(p);
	}
}

void calcsum(int *c)
{
	int s,e;
	int sum;
	scanf("%d%d",&s,&e);
    sum=0;
	while(e>0)
	{
		sum+=c[e];
		e-=lowbit(e);
	}
	s-=1;
	while(s>0)
	{
		sum-=c[s];
		s-=lowbit(s);
	}
	printf("%d\n",sum);
}

int main()
{
	int *a,*c;
	int state;
    scanf("%d",&n);
	a=new int[n+1];
	c=new int[n+1];
	memset(c,0,(n+1)*sizeof(int));
	while(scanf("%d",&state),state!=3)
	{
		switch(state)
		{
		case 1:change(c);break;
		case 2:calcsum(c);
		}
	}
	return 0;
}