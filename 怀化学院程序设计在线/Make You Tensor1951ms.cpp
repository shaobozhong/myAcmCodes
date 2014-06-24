#include<iostream>
#include<cmath>
using namespace std;
#define eps 1e-6
int map[505][505];
bool vis[505][505];
int n,m;
int Judge(int r,int c,int n,int m)
{
	int i,j;
	double rate,trate;
	int tmpr,tmpc;

	for(i=0;i<n;i+=r)
	{
		for(j=0;j<m;j+=c)
		{
			rate=(double)map[i][j]/map[0][0];
			for(tmpr=i;tmpr<i+r;++tmpr)
			{
				for(tmpc=j;tmpc<j+c;++tmpc)
				{
					trate=double(map[tmpr][tmpc])/map[tmpr-i][tmpc-j];
					if (fabs(trate-rate)>=eps) return 0;
				}
			}
		}
	}


	int count2=1;
	i=r;
	j=c;
	for(i=1;i<=r;++i)
	{
		for(j=1;j<=c;++j)
		{
			if (vis[i][j]||(i==1 && j==1)|| (r%i!=0) || (c%j!=0) || (r/i==1 && c/j==1)) continue;
			{
			vis[i][j]=true;
			count2+=Judge(i,j,r,c);
			}
		}
	}
	return count2;
}

int calc(int r,int c)
{
	int i,j,k;
	bool flag;
	int count2;
	int sum,min1;
	sum=Judge(r,c,n,m);
	if (!sum) return 0;
	min1=INT_MAX;
	for(i=0;i<r;++i)
	{
		for(j=0;j<c;++j)
		{
			if (min1>map[i][j]) min1=map[i][j];
		}
	}
	count2=1;
	for(i=2;i<=min1;++i)
	{
		flag=true;
		for(j=0;flag&&j<n;j+=r)
		{
			for(k=0;k<m;k+=c)
			{
				if (map[j][k]%i!=0)
				{
					flag=false;
					break;
				}
			}
		}
		if (flag) ++count2;
	}

	return count2*sum;
}



int main()
{

	int i,j;
	int count1;

	while(scanf("%d%d",&n,&m),n!=0||m!=0)
	{
		count1=0;
		for(i=0;i<n;++i)
		{
			for(j=0;j<m;++j)
			{
				scanf("%d",&map[i][j]);
			}
		}
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=m;++j)
			{
				vis[i][j]=false;
			}
		}
		for(i=n;i>=1;--i)
		{
			for(j=m;j>=1;--j)
			{
				if (vis[i][j]||(i==1 && j==1)|| (n%i!=0) || (m%j!=0) || (n/i==1 && m/j==1)) continue;
				count1+=calc(i,j);
			}
		}
		printf("%d\n",count1);
	}
	return 0;
}