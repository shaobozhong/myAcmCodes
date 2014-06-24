#include<iostream>
#include<cmath>
using namespace std;
#define eps 1e-6
int map[505][505];
int n,m;
int Judge(int r,int c)
{
	int min1;
	int i,j,k;
	double rate,trate;
	int tmpr,tmpc;
	min1=INT_MAX;
	for(i=0;i<r;++i)
	{
		for(j=0;j<c;++j)
		{
			if (min1>map[i][j]) min1=map[i][j];
		}
	}
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


    bool flag;
    int count2;
	count2=1;
	for(i=2;i<=min1;++i)
	{
			flag=true;
		for(j=0;flag&&j<n;++j)
		{
			for(k=0;k<m;++k)
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

	return count2;
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
				if ((i==1 && j==1)|| (n%i!=0) || (m%j!=0) || (n/i==1 && m/j==1)) continue;
				count1+=Judge(i,j);
			}
		}
		printf("%d\n",count1);
	}
	return 0;
}