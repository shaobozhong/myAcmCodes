#include<iostream>
using namespace std;

int main()
{
	int i,j,n,max_m,count;
	cin>>i>>j;
	max_m=0;
	for(;i<=j;i++)
	{
		n=i;
		count=1;
		while(n!=1)
		{
			if (n%2==0) n/=2;
			else n=3*n+1;
			count++;
		}
		if (max_m<count) max_m=count;
	}
	cout<<max_m<<endl;
	return 0;
}