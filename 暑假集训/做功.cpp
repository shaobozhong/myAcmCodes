#include<iostream>
using namespace std;

int main()
{
	double d,h;
	double res;
	while(scanf("%lf%lf",&d,&h)&&(d!=0||h!=0))
	{
		res=3.14*d*d/12.0*h*9.8*h/4.0;
		printf("%.2f\n",res);
	}
	return 0;
}
