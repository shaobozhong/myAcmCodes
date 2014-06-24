#include<stdio.h>
int main()
{
	__int64 f[10001];
	int t,n,i;
	f[1]=2;
	scanf("%d",&t);
	while(t--)
	{scanf("%d",&n);
	for(i=2;i<=n;i++)
		f[i]=f[i-1]+9*(i-1)+1;
	printf("%I64d\n",f[n]);
		
	}
	return 0;
}