#include<stdio.h>

int main()
{
    double n,sum;
	int i;
	double a[14]={0,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800};
	while(scanf("%lf",&n)>0&&n>=0)
	{
		sum=0;
		for(i=13;n!=0;i--)
		{
			if (n-a[i]>=0) {sum+=(int)((int)n/(int)a[i])*i;n-=(int)(((int)n/(int)a[i]))*a[i];}
		}
		printf("%.0f\n",sum);
	}
	return 0;
}