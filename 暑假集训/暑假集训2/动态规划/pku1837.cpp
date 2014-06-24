#include<stdio.h>
#include<string.h>
int dp[21][15001];
int main()
{
 int n,m,i,j,k;
 int w[21],p[21];
 //freopen("input.txt","r",stdin);
 while(scanf("%d%d",&n,&m)!=EOF)
 {
  for(i=1;i<=n;i++)
   scanf("%d",&w[i]);
  for(i=1;i<=m;i++)
   scanf("%d",&p[i]);
  memset(dp,0,sizeof(dp));
  for(i=1;i<=n;i++)
   dp[1][7500+w[i]*p[1]]++;

  for(i=2;i<=m;i++)
   for(j=1;j<=n;j++)
 for(k=0;k<=15000;k++)
   if(dp[i-1][k])
  dp[i][k+w[j]*p[i]]+=dp[i-1][k];
   printf("%d\n",dp[m][7500]);
 }
 return 0;
}