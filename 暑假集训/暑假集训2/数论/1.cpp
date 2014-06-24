#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	double x,y,c;
	double z1,z2,c1;
	double f;
	double mid;
    double tmp;
	while(scanf("%lf%lf%lf",&x,&y,&c)!=EOF)
	{
		if (x<y) 
		{
			tmp=x;
			x=y;
			y=tmp;
		}
		z1=0;
		z2=y;

		while(1)
		{
			mid=(z1+z2)/2;
			f=(sqrt(x*x-mid*mid)*sqrt(y*y-mid*mid))/(sqrt(x*x-mid*mid)+sqrt(y*y-mid*mid));  
			//if (f-c>-0.00001&& f-c<0 || f-c<0.00001 && f-c>0) break;
			if (abs(f-c)<0.00001) break;
			if (f>c) z1=mid;
			else z2=mid;
		}
		printf("%.3lf\n",mid);
	}
	return 0;
}