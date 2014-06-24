#include<stdio.h>
int sum;
void work(int m,int j,int s,int a[][101])
{
	s+=a[m][j];
	if (m==0) {if (sum<s) sum=s;return;}
	if (j>0) work(m-1,j-1,s,a);
	if (j<=m-1) work(m-1,j,s,a);
}
int main()
{
	int i,j,k,m,n;
	int a[101][101];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		sum=0;
		scanf("%d",&m);
		for(j=0;j<=m-1;j++)
			for(k=0;k<=j;k++)
				scanf("%d",&a[j][k]);
			for(j=0;j<=m-1;j++)
				work(m-1,j,0,a);
			printf("%d\n",sum);
	}
	return 0;
}