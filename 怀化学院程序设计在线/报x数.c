#include<stdio.h>

int work(int a[],int n,int d)
{
	int i,j;
	for(i=0;i<=n-1;i++)
		a[i]=i+1;
	j=d-1;
	while(a[1]!=0)
	{if (j>n-1) j=j%(n-1)-1;
	for(i=j;i<=n-2;i++)
		*(a+i)=*(a+i+1);
	*(a+n-1)=0;
	n--;
	j=j+d-1;
	}
}

int main()
{int a[65536];
    int n,d;
	
	scanf("%d%d",&n,&d);
    work(a,n,d);
	printf("%d\n",*a);
    return 0;
}