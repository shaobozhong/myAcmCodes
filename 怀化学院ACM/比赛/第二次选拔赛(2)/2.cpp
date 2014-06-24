#include<stdio.h>

int main()
{
	int t,n,a[10000],i,j,count;
	scanf("%d",&t);
	while(t--)
	{
		count=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=1;i<n;i++)
		{
			for(j=0;j<i;j++)
			{
				if (a[i]<a[j]) count++;
			}
		}
	    printf("%d\n",count);
	}
	return 0;
}