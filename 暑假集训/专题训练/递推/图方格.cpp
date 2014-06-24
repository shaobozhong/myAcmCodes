#include<stdio.h>
int main()
{
	__int64 f[51];
	int i,n;
	f[1]=3;
	f[2]=6;
	f[3]=6;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=4;i<=n;i++)
			f[i]=f[i-1]+f[i-2]*2;
		printf("%I64d\n",f[n]);
	}
	return 0;
}