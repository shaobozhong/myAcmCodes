#include<stdio.h>
int main()
{
	int f[41],t,n,i;
	scanf("%d",&t);
	f[1]=0;
	f[2]=1;
	f[3]=2;
	while(t--)
	{
      scanf("%d",&n);
	  for(i=4;i<=n;i++)
	  {
		  f[i]=f[i-1]+f[i-2];
	  }
	  printf("%d\n",f[n]);
	}
	return 0;
}