#include<stdio.h>
int main()
{
	int i,sum,n;
	scanf("%d",&n);

 sum=0;

	for(i=1;i<=n;i++)
		if (i%3==0&&i%5==0) sum++;
		printf("%d\n",sum);

	return 0;
}