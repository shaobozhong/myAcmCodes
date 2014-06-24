#include<iostream>
using namespace std;

int main()
{
	int a[501];
	int t,i,j,n,min=2100000000,sum;
	cin>>t;
	while(t--)
	{
		cin>>n;
		min=2100000000;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<n;i++)
		{
			sum=0;
			for(j=0;j<n;j++)
			{
				sum+=abs(a[i]-a[j]);
			}
			if (min>sum) min=sum;
		}
		cout<<min<<endl;
	}
	return 0;
}
