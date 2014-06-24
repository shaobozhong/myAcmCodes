#include<stdio.h>
int main()
{
	double s,sum;
	int m,n,t,i,j;
	scanf("%d",&t);
for(i=1;i<=t;i++)
{
	s=1;sum=0;
	scanf("%d%d",&m,&n);
	for(j=1;j<=n;j++)
	{
		s*=j;
		if (j>=m) sum+=s;
	}
	printf("%.0f\n",sum);
		
}
	return 0;
}
