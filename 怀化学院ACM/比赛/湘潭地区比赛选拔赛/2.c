#include<stdio.h>
int main()
{
	double a[102];
	int b,i,m,d;
	a[0]=1;
	while(scanf("%d%d",&m,&d)>0&&m!=0||d!=0)
	{
		for(i=1;i<=d;i++)
		{
			if (i>m) a[i]=a[i-1]+a[i-m];
			else 
				a[i]=a[i-1]+1;
		}
		printf("%.0f\n",a[d]);
	}
	return 0;
}