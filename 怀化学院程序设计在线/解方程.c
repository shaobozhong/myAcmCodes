#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,x,n,k;
	while(scanf("%lf%lf",&k,&n)>0&&n!=0||k!=0)
	{
		a=0;b=1000000;
		while(abs((int)((a*1000000-b*1000000)))>1)
		{
			x=(a+b)/2;
			if ((pow(x,n)-k)*(pow(a,n)-k)<0) b=x;
			else a=x;
		}
		printf("%.4f\n",x);
	}
	
	return 0;
} 