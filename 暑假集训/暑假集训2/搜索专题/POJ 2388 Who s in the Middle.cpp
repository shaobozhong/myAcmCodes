#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,i,a[50000];
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;++i)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		printf("%d\n",a[n/2]);
	}
	return 0;
}
