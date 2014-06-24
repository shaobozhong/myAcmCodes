#include<iostream>
using namespace std;

int n,m,k;
long long sum;
long long calc(int num1,int num2)
{
	int i;
	long long res=1;
	if (num2==0) return 1;
	int num=num1-num2;
	if (num>num2) num=num2;
	for(i=num1;i>=num1-num+1;--i)
	{
		res*=i;
	}
	for(i=num;i>=1;--i)
	{
		res/=i;
	}
	return res;
}

void work(int num,int i,long long v)
{
	int j;
	if (i==m-1)
	{
		if (num>=k)
		{
			sum+=v;
		}
		return ;
	}
	if (num<k) return;
	for(j=k;j<=num;++j)
	{
		work(num-j,i+1,v*calc(num,j));
	}
}

long long aa(int m)
{
	long long res;
	res=1;
	for(int i=2;i<=m;++i)
	{
		res*=i;
	}
	return res;
}

int main()
{
	//freopen("·ÅÇò.in","r",stdin);
	//freopen("·ÅÇò.out","w",stdout);
	long long f[16][16];
	int i,j;
	while(scanf("%d%d%d",&n,&m,&k),n!=0||m!=0||k!=0)
	{

		if (n<m*k) {puts("0");continue;}
		if (m==1) {puts("1");continue;}

		if (k==0) 
		{
			for(i=0;i<=n;++i)
			{
				f[0][i]=0;
				f[i][0]=0;
				f[i][i]=1;
			}
			for(i=1;i<=n;++i)
			{
				f[i][1]=1;
			}
			for(i=1;i<=n;++i)
			{
				for(j=1;j<=n;++j)
				{
					f[i][j]=j*f[i-1][j]+f[i-1][j-1];
				}
			}
			sum=0;
			for(i=1;i<=m&&i<=n;++i)
			{
				sum+=f[n][i]*aa(i)*calc(m,i);
			}
			printf("%lld\n",sum);
			continue;

		}
		sum=0;
		work(n,0,1); 
		printf("%lld\n",sum);
	}

	return 0;
}
