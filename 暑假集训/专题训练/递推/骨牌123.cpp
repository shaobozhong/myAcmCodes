#include<stdio.h>
int main()
{
	__int64 f[51];
	int i;
	int n;
	f[1]=1;
	f[2]=2;
	f[3]=4;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=4;i<=n;i++)
		{
			f[i]=f[i-1]+f[i-2]+f[i-3];
		}
		printf("%I64d\n",f[n]);
	}

	return 0;
}