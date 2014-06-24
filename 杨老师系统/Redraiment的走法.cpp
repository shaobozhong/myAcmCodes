#include<iostream>
using namespace std;

int main()
{
	int n,h[10002],result[10002],i,j;
	int tmax,max;
	while(scanf("%d",&n)!=EOF)
	{
		max=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&h[i]);
		}
		result[1]=1;
		for(i=2;i<=n;i++)
		{
			tmax=-1;
			result[i]=1;
			for(j=1;j<=i-1;j++)
			{
				if (h[i]>h[j]&&result[j]>tmax) tmax=result[j]; 
			}
			if (tmax!=-1) result[i]+=tmax;
			if (max<result[i]) max=result[i];
		}
		printf("%d\n",max);

	}
	return 0;
}