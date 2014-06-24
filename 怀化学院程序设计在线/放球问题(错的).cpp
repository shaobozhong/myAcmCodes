#include<iostream>
using namespace std;


long long  work(int n,int i,int k,int m)
{
	int temp;
	long long  res;
	res=1;
	temp=n-(i*k);
	while(k--)
	{
		res*=temp;
		temp-=1;
	}
	return res;
}

int main()
{
	long long  result;
	int n,m,k,i,temp;

	while(scanf("%d%d%d",&n,&m,&k),n!=0||m!=0||k!=0)
	{
		if (n<k*m) {puts("0");continue;}
		if (m==1) {puts("1");continue;}
		result=1;
		for(i=1;i<=n-k*m;++i)
		{
			result*=m;
		}
		temp=1;
		for (i=2;i<=k;i++)
		{
			temp*=k;
		}
		for(i=0;i<m;++i)
			result*=work(n,i,k,m)/temp;
		printf("%lld\n",result);
	}
	return 0;
}