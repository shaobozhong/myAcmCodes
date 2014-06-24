#include<stdio.h>
int main()
{
	int n,a[102],i,j,k,t;
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
		scanf("%d",&a[i]);
	for(i=0;i<=n-2;i++)
		for(j=0;j<=n-2-i;j++)
		{
			if (a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
			if (a[j]==a[j+1])
			{
				for(k=j+1;k<=n-2;k++)
					a[k]=a[k+1];
				n--;
			}
		}
		printf("%d\n",n);
		for(i=0;i<=n-1;i++)
			printf("%d ",a[i]);
		printf("\n");
		return 0;
}