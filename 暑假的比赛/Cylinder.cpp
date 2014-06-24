#include<stdio.h>
#include<math.h>

#define PI acos(double(-1))

int main()
{
	double x,y,s,r,V,tmp;
	while(scanf("%lf%lf",&x,&y),x || y)
	{
		if(x < y)
		{
			tmp = x;
			x = y; 
			y = tmp;
		}
		s = x/(PI+1);
		r = s/2;
		if(s > y)
		{
			r = y/2;
		}
		V = PI*r*r*y;
		r = y/(2*PI);
		if(V < (x-2*r)*PI*r*r)
		{
			V = (x-2*r)*PI*r*r;
		}
		printf("%.3lf\n",V);
	}
	return 0;
}
