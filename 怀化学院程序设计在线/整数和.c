#include<stdio.h>
int main()
{
	int n,m,k,i,sum=0;
    scanf("%d%d%d",&n,&m,&k);
	for(i=n;i<=m&&sum<=k;i++)
		if (i%2==0&&i%3==0&&i%5==0) sum+=i;
	 printf("%d\n",sum);
	return 0;
}
