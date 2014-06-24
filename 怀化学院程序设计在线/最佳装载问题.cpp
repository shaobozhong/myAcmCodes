#include<iostream>
using namespace std;

int r[501][51];
char res[51];
int main()
{
	int n,c,i,j,t=0;
	int v[51],w[51],temp;
	while(scanf("%d%d",&n,&c)!=EOF)
	{
		t++;
		for(i=0;i<501;i++)
		{
			for(j=0;j<51;j++)
			{
				r[i][j]=0;
			}
		}
		for(i=n;i>=1;i--)
		{
			scanf("%d",&v[i]);
		}
		for(i=n;i>=1;i--)
		{
			scanf("%d",&w[i]);
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
		 printf("Case %d\n",t);
		printf("%d ",r[c][n]);
		
		/*for(i=1;i<=n;i++)
		{
			for(j=1;j<=c;j++)
			{
				cout<<r[j][i]<<" ";
			}
			cout<<endl;
		}*/
		for(i=n;i>=1;i--)
		{
			if (r[c][i]!=r[c][i-1]) {res[i]='1';c-=w[i];}
			else 
				res[i]='0';
		}
		for(i=n;i>=1;i--)
		{
			putchar(res[i]);
		}
		putchar('\n');
	}
	return 0;
}