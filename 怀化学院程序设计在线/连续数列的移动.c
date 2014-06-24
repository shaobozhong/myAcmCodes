#include<stdio.h>


void myread(int *p,int n)
{
	int i;
	for(i=0;i<=n-1;i++)
		scanf("%d",p+i);
}

process(int *p,int n,int m)
{int i,t,j;
for(i=1;i<=m;i++)
{
	t=*(p+n-1);
	for(j=n-1;j>=1;j--)
	{
		*(p+j)=*(p+j-1);
	}
	*p=t;

}
}

myprint(int a[],int n)
{
	int i;
	for(i=0;i<=n-1;i++)
		printf("%d ",*(a+i));
	printf("\n");
}
int main()
{
	int n,m,a[101];
	scanf("%d%d",&n,&m);
	myread(a,n);
    process(a,n,m);
    myprint(a,n);
	return 0;
}