#include<iostream>
using namespace std;

int main()
{
	int f[101][101];
	int n,p,m,t,i,j;
	while(scanf("%d%d%d%d",&n,&p,&m,&t)!=EOF)
	{
		memset(f,0,sizeof(f));
		f[0][p]=1;
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				if (j==1) f[i][j]=f[i-1][j+1];
				else if (j==n) f[i][j]=f[i-1][j-1];
				else 
				{
					f[i][j]=f[i-1][j-1]+f[i-1][j+1];
				}
			}
		}
		printf("%d\n",f[m][t]);
	}
	return 0;
}