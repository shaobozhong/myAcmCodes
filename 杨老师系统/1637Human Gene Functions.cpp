#include<stdio.h>
int stand[6][6]={
	{0,0,0,0,0,0},
	{0,5,-1,-2,-1,-3},
	{0,-1,5,-3,-2,-4},
	{0,-2,-3,5,-2,-2},
	{0,-1,-2,-2,5,-1},
	{0,-3,-4,-2,-1,-10000}
};
char ch;
int f[105][105];
int a[105],b[105];
int main()
{
	int N,n1,n2,i,j;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d%c",&n1,&ch);
		for(i=1;i<=n1;i++)
		{
			scanf("%c",&ch);
			if(ch=='A') a[i]=1;
			else if(ch=='C') a[i]=2;
			else if(ch=='G') a[i]=3;
			else if(ch=='T') a[i]=4;
		}
		scanf("%d%c",&n2,&ch);
		for(i=1;i<=n2;i++)
		{
			scanf("%c",&ch);
			if(ch=='A') b[i]=1;
			else if(ch=='C') b[i]=2;
			else if(ch=='G') b[i]=3;
			else if(ch=='T') b[i]=4;
		}
		f[0][0]=0;
		for(i=1;i<=n1;i++)
		{
			f[i][0]=f[i-1][0]+stand[a[i]][5];

		}
		for(i=1;i<=n2;i++)
		{
			f[0][i]=f[0][i-1]+stand[5][b[i]];
		}
		for(i=1;i<=n1;i++)
		{
			for(j=1;j<=n2;j++)
			{
				f[i][j]=f[i-1][j-1]+stand[a[i]][b[j]];
				if(f[i-1][j]+stand[a[i]][5]>f[i][j])
					f[i][j]=f[i-1][j]+stand[a[i]][5];
				if(f[i][j-1]+stand[5][b[j]]>f[i][j])
					f[i][j]=f[i][j-1]+stand[5][b[j]];
			}
		}
		printf("%d\n",f[n1][n2]);
	}
	return 0;
}

