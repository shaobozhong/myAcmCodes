#include<stdio.h>
void main()
{
	int a[100],i,s[100];
	s[0]=a[0]=1;
	s[1]=2;
	a[1]=1;
	for(i=2;i<=99;i++)
	{
		a[i]=a[i-1]+a[i-2];
		s[i]=s[i-1]+a[i];
	}
	while(scanf("%d",&i)>0&&i!=0)
	{
		printf("%d\n",s[i-1]);
		
	}

}