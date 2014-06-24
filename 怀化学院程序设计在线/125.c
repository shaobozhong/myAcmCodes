#include<stdio.h>

int main()
{
    int i,sum=0,n;
	int f[20];
	f[0]=1;
	f[1]=1;
	for(i=2;i<=20;i++)
	{
		f[i]=f[i-1]+f[i-2];
	}
	scanf("%d",&n);
	for(i=0;i<=n-1;i+=2)
		sum+=f[i];
	printf("%d\n",sum);

	return 0;
}
