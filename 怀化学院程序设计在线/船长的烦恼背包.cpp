#include<iostream>
using namespace std;

int r[501][51];
char res[51];
int main()
{
	int n,c,i,j,t=0;
	int v[51],w[51],temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&c);
		for(i=0;i<501;i++)
		{
			for(j=0;j<51;j++)
			{
				r[i][j]=0;
			}
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			w[i]=v[i];
		}
		 for(j=1;j<=n;j++)
		{
		for(i=1;i<=c;i++)
		{
		if (w[j]<=i)
		{
			r[i][j]=v[j]+r[i-w[j]][j-1];
		}
		//取最大值
		r[i][j]=r[i][j]>r[i][j-1]?r[i][j]:r[i][j-1];
		r[i][j]=r[i][j]>r[i-1][j]?r[i][j]:r[i-1][j];
		}
		}
		printf("%d\n",r[c][n]);
	}
	return 0;
}