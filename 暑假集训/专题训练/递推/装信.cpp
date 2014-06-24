#include<iostream>
using namespace std;

int main()
{
	__int64 f[21];
	
	int n,i;
	f[1]=0;
	f[2]=1;
	while(cin>>n)
	{
		for(i=3;i<=n;i++)
			f[i]=(f[i-1]+f[i-2])*(i-1);
		cout<<f[n]<<endl;
	}
	return 0;
}