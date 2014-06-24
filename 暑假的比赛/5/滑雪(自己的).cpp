#include<iostream>
using namespace std;

int result[101][101];
int map[101][101];
int n,m;
void work(int i,int j)
{
	if (result[i][j]!=-1) return;
	if (i>1&&map[i][j]>map[i-1][j])//ио
	{
		if (result[i-1][j]==-1) work(i-1,j);
		result[i][j]=result[i-1][j]+1;

	}
	if (i<n&&map[i][j]>map[i+1][j])//об
	{
		if (result[i+1][j]==-1) work(i+1,j);
		if (result[i+1][j]+1>result[i][j])  result[i][j]=result[i+1][j]+1;
	}
	if (j>1&&map[i][j]>map[i][j-1])//вС
	{
		if (result[i][j-1]==-1) work(i,j-1);
		if (result[i][j-1]+1>result[i][j])  result[i][j]=result[i][j-1]+1;
	}
	if (j<m&&map[i][j]>map[i][j+1])//ср
	{
		if (result[i][j+1]==-1) work(i,j+1);
		if (result[i][j+1]+1>result[i][j])  result[i][j]=result[i][j+1]+1;
	}
	if (result[i][j]==-1) result[i][j]=1;
}

int main()
{
	int max,i,j;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		max=-1;
		memset(result,-1,sizeof(result));
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=m;++j)
			{
				scanf("%d",&map[i][j]);
			}
		}
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=m;++j)
			{
				work(i,j);
				if (max<result[i][j]) max=result[i][j];
			}
		}
		printf("%d\n",max);
	}
	return 0;
}