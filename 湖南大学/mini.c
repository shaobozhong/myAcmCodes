#include<stdio.h>
int n,m;
void work(int i,int j,int s,int a[][1000])
{
	int j;
	if (i==j&&s!=0) {if (min>s) min=s;return;}
	 for(j=0;j<=m-1;j++)
		 if a[]
}

int main()
{
	int t,z,i,a[1000][1000];
	scanf("%d",&t);
	for(z=1;z<=t;z++)
	{
        scanf("%d%d",&n,&m);
		for(i=0;i<=n-1;i++)
			for(j=0;j<=m-1;j++)
				a[i][j]=-1;
		for(i=0;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			scanf("%d",&a[x][y]);
		}
		for(i=0;i<=m-1;i++)
			work(i,i,s,a);
        
	}
	return 0;
}