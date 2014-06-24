#include<stdio.h>
int main()
{
	int a,b,i,j,sum,n;
	scanf("%d",&n);
	for(j=1;j<=n;j++)
	{sum=0;
	scanf("%d%d",&a,&b);
	for(i=a;i<=b;i++)
		if (i%3==0||i%5==0) sum+=i;
		printf("%d\n",sum);
	}
	return 0;
}