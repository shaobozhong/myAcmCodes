#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(const int &a,const int &b)
{
	return a<b;
}

int main()
{
	int n,k,a[100000],i;
	while(scanf("%d%d",&n,&k)>0&&n!=0||k!=0)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n,cmp);
		for(i=0;i<n-k;i+=k)
		{
			printf("%d ",a[i]);
		}
		printf("%d\n",a[i]);
	}
	return 0;
}
