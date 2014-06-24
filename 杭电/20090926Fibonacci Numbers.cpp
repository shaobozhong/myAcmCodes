#include<iostream>
#include<cmath>
using namespace std;
int a[15000];

int main()
{
	int i,n;
	double t;
	a[0]=0;
	a[1]=1;
	for(i=2;i<15000;i++)
	{
		a[i]=a[i-1]+a[i-2];
		a[i]%=10000;
	}
	while(scanf("%d",&n)!=EOF)
	{
		rest=a[n%15000];
    t=(log10 (1/sqrt(5.0)) + n*log10 (1+sqrt(5.0))/2)/(int)(log10 (1/sqrt(5.0)) + n*log10 (1+sqrt(5.0))/2); 
	pow(t,)
	}
return 0;
}