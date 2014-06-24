#include<stdio.h>

int mod(int a,int b)
{
	return a%b;
}

int main()
{
	int res;
	int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
	{
		res=mod(a,b);
		printf("%d\n",res);
	}
	return 0;
}

