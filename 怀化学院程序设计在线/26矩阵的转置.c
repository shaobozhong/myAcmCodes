#include<stdio.h>
void main()
{
	int a[101][101],n,i,j;
    scanf("%d",&n);
	for(i=0;i<=n-1;i++)
		for(j=0;j<=n-1;j++)
			scanf("%d",&a[i][j]);
		for(i=0;i<=n-1;i++)
		{
			for(j=0;j<=n-1;j++)
				printf("%d ",a[j][i]);
			printf("\n");
		}
}