#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int a,int b)
{
	return a<b;
}

int main()
{
	int a[20005];
	int n;
	long long sum;
    int i;
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
			a[i]=a[i]+a[i-1];
			sort(a+i,a+n,cmp);
		}
		printf("%lld\n",sum);
	}
	return 0;
}