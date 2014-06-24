#include<stdio.h>
int main()
{int i,n;char a[9];
	while(scanf("%d",&n)+1)
	{
		for(i=0;i<=n-1;i++)
		{getchar();
		scanf("%c",&a[i]);
		}
	for(i=0;i<=n-1;i++)
		printf("%c ",a[i]);
	printf("\n");
	}
}