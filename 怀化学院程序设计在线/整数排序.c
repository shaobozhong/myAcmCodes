#include<stdio.h>
int main()
{
	int t,n,a[21],i,j,k,temp;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		
		scanf("%d",&n);
		for(j=0;j<=n-1;j++)
			scanf("%d",&a[j]);
		for(j=0;j<=n-2;j++)
		{
			for(k=0;k<=n-2-j;k++)
			{
				if (a[k]>a[k+1])
				{
					temp=a[k];
					a[k]=a[k+1];
					a[k+1]=temp;
				}
			}
		}
		for(j=0;j<=n-1;j++)
			printf("%d ",a[j]);
		printf("\n");
		
	}
	return 0;
}