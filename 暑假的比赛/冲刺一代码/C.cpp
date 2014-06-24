#include<iostream>
using namespace std;

int main()
{
	__int64 a[10001];
	int t,n;
	a[1]=2;
	freopen("C.in","r",stdin);
	cin>>t;
	for(n=2;n<=10000;++n)
	{
		a[n]=a[n-1]+(n-1)*6;
	}
	while(t--)
	{
		cin>>n;
		printf("%I64d\n",a[n]);
	}
	return 0;
}