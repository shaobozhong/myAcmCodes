#include<iostream>
using namespace std;

int main()
{
	__int64  f[51];
	int n,i;
	f[1]=1;
	f[2]=2;
	while(cin>>n)
	{
		for(i=3;i<=n;i++)
		{
			f[i]=f[i-1]+f[i-2];
		}
		cout<<f[n]<<endl;
	}
	return 0;
}