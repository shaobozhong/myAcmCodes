#include<stdio.h>
void myread(int *p,int n)
{
	int i;
	for(i=0;i<=n-1;i++)
		scanf("%d",p+i);
}

void process(int * p,int n)
{
	int max=0,min=0,i;
	for(i=1;i<=n-1;i++)
	{
		if (*(p+max)<*(p+i)) max=i;
		if (*(p+min)>*(p+i)) min=i;
	}
i=*(p+n-1);*(p+n-1)=*(p+max);*(p+max)=i;
i=*(p);*(p)=*(p+min);*(p+min)=i;
}

void myprint(int a[],int n)
{
int i;
for(i=0;i<=n-1;i++)
printf("%d ",a[i]);
printf("\n");
}

int main()
{
	int n,p[101];
	scanf("%d",&n);
     myread(p,n);
	 process(p,n);
     myprint(p,n);
	return 0;
}