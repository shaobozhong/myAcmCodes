#include<stdio.h>
int main()
{
	__int64 f[1001];
	int i,n;
	f[1]=1;
	f[2]=2;
	f[3]=4;
	f[4]=7;
	for(i=5;i<=998;i++)
		f[i]=f[i-1]+f[i-2]+f[i-4];
		while(scanf("%d",&n)!=EOF)
		{
		if (n<=998)
		printf("%I64d\n",f[n]);
		}
	
	return 0;
}