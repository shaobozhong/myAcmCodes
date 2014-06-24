#include<iostream>
using namespace std;

int main()
{
	__int64 f[22][22];
	int i,m,n,j,inum,jnum;
	for(i=1;i<=21;i++)
	{
		f[i][0]=1;
	}
	for(i=1;i<=21;i++)
	{
		f[0][i]=0;
	}
	for(i=1;i<=21;++i)
	{
		for(j=1;j<=i;++j)
		{
			if (i-1>=j) inum=1;
			else 
			{
				if (i-1<j) inum=0;
			}
			f[i][j]=inum*f[i-1][j]+f[i][j-1];
		}
	}

	while(scanf("%d%d",&m,&n)!=EOF)
	{
		if (m<n) {printf("0\n");continue;}
		printf("%I64d\n",f[m][n]);
	}
	return 0;
}