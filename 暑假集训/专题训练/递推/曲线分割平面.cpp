#include<stdio.h>
int main()
{
	__int64 n;
	__int64 sum;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%I64d",&n);
		sum=2+n*(n-1);
		printf("%I64d\n",sum);
	}
  return 0;
}