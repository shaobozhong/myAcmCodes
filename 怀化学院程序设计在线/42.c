#include<stdio.h>
void main()
{
	int a,b,i,s,n,j;
	
	
	
	while(scanf("%d%d",&a,&b)>0&&a!=0||b!=0)
	{
		s=0;
		for(j=a;j<=b;j++)
			s+=j;
		printf("%d\n",s);
	}
	
}