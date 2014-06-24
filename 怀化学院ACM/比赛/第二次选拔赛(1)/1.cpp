#include<stdio.h>

int main()
{
	int n,m,i,sum,sum1;
	//freopen("problem1.in","r",stdin);
	while(scanf("%d%d",&n,&m)>0&&(n||m))
	{
		sum=m;
		sum1=m;
       for(i=1;(__int64)sum*m<=n;i++)
	   {
		   sum*=m;
		   sum1=sum;
	   }
	   printf("%d\n",n/sum);
	   for(i=sum;i<=n-sum;i+=sum)
	   {
		   printf("%d ",i);
	   }
	   printf("%d\n",i);
	}

	return 0;
}