#include<iostream>
#include<math.h>
using namespace std;
int r[1000000];
int a[3000008];
int pre=0;
int pre_sum=1;




double calc(int n)
{
	int i,m,sum=1;
	m=3*n+8;
	sum*=a[pre_sum];
	for(i=pre_sum+1;i<m-2;i++)
	{
		sum*=i;
		sum%=1000005;
		a[i]=sum;
	}
	pre_sum=m-3;
	if (sum%m==0) return 1;
	return 0;
}

void work(int n)
{
	int i;
	for(i=pre+1;i<=n;i++)
	{
		r[i]=(int)calc(i);
		r[i]+=r[i-1];
	}
	pre=n;
}
int main()
{
	int t;
	int n;
	r[0]=0;
	a[1]=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
	    if (n>pre) work(n);
		printf("%d\n",r[n]);
	}
	return 0;
}