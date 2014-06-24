#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

bool cmp(int a,int b)
{
	return a<b;
}

int main()
{
	int a[1025],n,i,mid;
	int sum;
	
	while(scanf("%d",&n),n>=0)
	{
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n,cmp);
		mid=a[n/2];
		for(i=0;i<n;++i)
		{
			sum+=(int)abs((double)(a[i]-mid));
		}
		cout<<sum<<endl;
	}
	return 0;
}