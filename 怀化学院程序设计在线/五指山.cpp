#include<iostream>
#include<cmath>
using namespace std;
__int64 n,v,x,y;
__int64 c,d,xx,yy;


__int64 modd(__int64 a,__int64 b)
{
	if (a>=0)
		return a%b;
	else 
		return a%b+b;
}

__int64 exgcd(__int64 a,__int64 b)
{
	__int64 r,t;
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
		scanf("%I64d%I64d%I64d%I64d",&n,&v,&x,&y);
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
		printf("%I64d\n",xx);
	}
	return 0;
}