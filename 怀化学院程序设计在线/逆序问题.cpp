#include<iostream>
using namespace std;

int main()
{
	int n,m,i,j,k;
	__int64  f[21][201];
	for(i=0;i<201;++i)
	{
		f[0][i]=0;
		f[1][i]=0;
	}
	f[1][0]=1;
	for(i=2;i<21;++i)
	{
		for(j=0;j<201;j++)
		{
			f[i][j]=0;
			for(k=0>=j-i+1?0:j-i+1;k<=j;++k)
			{
				f[i][j]+=f[i-1][k];
			}
		}
	}
	while (scanf("%d%d",&n,&m),n!=0||m!=0)
	{
		printf("%I64d\n",f[n][m]);
	}
	return 0;
}