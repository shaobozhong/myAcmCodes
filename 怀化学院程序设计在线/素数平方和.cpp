#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n,m,i,sum=0;;
	cin>>n>>m;
	for(;n<=m;n++)
	{
		if (n<=1) continue;
		for(i=2;i<=(int)sqrt(double(n));i++)
		{
			if (n%i==0) break;
		}
		if (i>(int)sqrt(double(n))) sum+=n*n;
	}
	cout<<sum<<endl;
	return 0;
}