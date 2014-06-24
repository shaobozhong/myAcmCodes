#include<stdio.h>
void main()
{
	int a[56],n,i;
	a[1]=1;
	while(scanf("%d",&n)>0&&n!=0)
	{
	   for(i=2;i<=n;i++)
	   {
		   if (i<5) a[i]=a[i-1]+1;
		   else a[i]=a[i-1]+a[i-3];
	   }
	   printf("%d\n",a[n]);
	}
}