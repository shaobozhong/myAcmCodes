#include<iostream>
using namespace std;

int main()
{
	int min,tmin;
	int n,i,j;
	int f[201][201];
	int r[201][201];
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<n;++i)
		{
			for(j=i+1;j<=n;++j)
			{
				scanf("%d",&r[i][j]);
			}
		}
		min=r[1][n];
		f[1][1]=0;
		for(i=2;i<=n;++i)
		{
			tmin=r[1][i];
			for(j=2;j<=i-1;++j)
			{
				if (f[1][j]+r[j][i]<tmin) tmin=f[1][j]+r[j][i];
			}
			f[1][i]=tmin;
		}
		printf("%d\n",f[1][n]);
	}
	return 0;
}