#include<iostream>
using namespace std;
int n,m,k;
long long res[60][60];

long long gcd(long long a,long long b)
{
	long long r;
	while (b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

long long c(int a,int b)
{
	int i,j;
	long long x,y,r;
	x=1;y=1;
	for (i=0;i<b;++i)
	{
		x*=a-i;y*=b-i;
        r=gcd(x,y);
		x/=r;y/=r;
	}
	return x/y;
}
void work()
{
	int i,j,l;
	long long temp;
	for (i=0;i<=n;++i)
	{
		for (j=0;j<=m;++j)
		{
			res[i][j]=0;
		}
	}

	for (i=0;i<=n;++i)
	{
		res[i][0]=0;
	}
	res[0][0]=1;
	for (i=1;i<=m;++i)
	{
		for (j=k*i;j<=n;++j)
		{
			res[j][i]=0;
			for (l=k;l<=j-(i-1)*k;++l)
			{
				temp=c(j,l);
				res[j][i]+=temp*res[j-l][i-1];
			}
		}
	}
	printf("%lld\n",res[n][m]);
}


int main()
{

	while (scanf("%d%d%d",&n,&m,&k)&&(n!=0||m!=0||k!=0))
	{
		if (n<m*k) {puts("0");continue;}
		if (m==1) {puts("1");continue;}
		work();
	}
	return 0;
}