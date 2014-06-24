#include<iostream>
using namespace std;

int main()
{
	__int64 f[31];
	int t,n,i;
	cin>>t;
	f[0]=3;
	while(t--)
	{
		cin>>n;
       for(i=1;i<=n;i++)
		   f[i]=(f[i-1]-1)*2;
	   cout<<f[n]<<endl;
	}
	
}