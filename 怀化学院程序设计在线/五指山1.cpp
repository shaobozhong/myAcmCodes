#include<iostream>
#include<cmath>
using namespace std;

long long n,v,x,y;
long long c,d,xx,yy;


long long modd(long long a,long long b)
{
	if (a>=0)
		return a%b;
	else 
		return a%b+b;
}

long long exgcd(long long a,long long b)
{
	long long r,t;
	if (b==0)
	{
		xx=1;
		yy=0;
		return a;
	}
	r=exgcd(b,a%b);
	t=xx;
	xx=yy;
	yy=t-a/b*yy;
	return r;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&n,&v,&x,&y);
		if (x>n||y>n) {puts("Impossible");continue;}
		d=exgcd(v,n);
		c=modd(y-x,n);
		if (c%d!=0) 
		{
			puts("Impossible");
			continue;
		}
		n=n/d;
		xx=modd(xx*c/d,n);
		printf("%lld\n",xx);
	}
	return 0;
}