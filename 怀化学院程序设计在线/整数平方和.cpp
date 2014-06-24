#include<iostream>
using namespace std;

int main()
{
	int t,a,b,sum;
	cin>>t;
	while(t--)
	{
		sum=0;
		cin>>a>>b;
		for(;a<=b;a++)
		{
			if (a%7==0) sum+=a*a;
		}
		cout<<sum<<endl;
	}
	return 0;
}