#include<iostream>
using namespace std;
int sum[1000001];
int main()
{
	int n;
	int count1,i;


	sum[0]=0;
	sum[1]=1;
	count1=1;
	
	while(scanf("%d",&n)!=EOF)
	{
		if (n<=count1) printf("%d\n\n",sum[n]);
		else 
		{
			for(i=count1+1;i<=n;++i)
			{
				sum[i]=sum[i-1]+i;
			}
			count1=n;
			printf("%d\n\n",sum[n]);
		}
	}
	return 0;
}


