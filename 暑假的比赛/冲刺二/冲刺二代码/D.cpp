#include<iostream>
using namespace std;

int main()
{
	int i,n,t;__int64 result;
	cin>>t;
	while(t--)
	{
         cin>>n;
		 result=2;
		 if(n==0) result=0;
		for(i=1;i<n;++i)
		{
			result*=2;
		}
		result-=n;
		printf("%I64d\n",result);
	}
	return 0;
}