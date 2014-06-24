#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(const int a,const int b)
{
	return abs(a)>abs(b);
}
int main()
{
	int a[101],n,i;
	while(cin>>n,n!=0)
	{
		for(i=0;i<=n-1;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n,cmp);
		for(i=0;i<n-1;i++)
			cout<<a[i]<<" ";
		cout<<a[i];
		cout<<endl;
	}
}