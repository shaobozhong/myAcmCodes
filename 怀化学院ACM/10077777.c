#include<stdio.h>
int a[900000];
int main()
{
	
	int i,j,n,temp;
	while(scanf("%d",&n)+1)
	{
		for(i=0;i<=n-1;i++)
			scanf("%d",&a[i]);
		for(i=0;i<=2;i++)
		{for(j=i+1;j<=n-1;j++)
		 if (a[i]<a[j]) {temp=a[i];a[i]=a[j];a[j]=temp;}
		}
		for(i=0;i<=2;i++)
		printf("%d ",a[i]);
	    printf("\n");
	}
return 0;
}