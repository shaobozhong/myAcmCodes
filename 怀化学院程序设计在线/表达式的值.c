#include<stdio.h>
int main()
{
	int i;
	double s,n,a,b;
	while(scanf("%lf",&n)>0&&n!=0)
	{
		s=1;
		a=1;
		b=1;
		for(i=1;i<=n;i++)
		{
			a*=i;
			b*=2*i+1;
			s+=a/b;
		}
		printf("%.5f\n",s);
	}
	return 0;
}