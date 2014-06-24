#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

bool cmp(int a,int b)
{
	return a<b;
}

int main()
{
	int a[20005];
	int n;
	__int64 sum;
	int sum1;
    int i,j;
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;
		for(i=0;i<n;++i)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n,cmp);
		for(i=1;i<n;++i)
		{
			sum+=a[i]+a[i-1];
			sum1=a[i]+a[i-1];
			for(j=i;j<n-1;++j)
			{

				if (sum1>a[j+1]) a[j]=a[j+1];
				else 
				{
					break;
				}
			}
			a[j]=sum1;
		}
		printf("%I64d\n",sum);
	}
	return 0;
}