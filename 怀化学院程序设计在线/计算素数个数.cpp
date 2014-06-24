#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n,count,i,j;
	cin>>n;
	count=0;
	for(i=2;i<=n;i++)
	{
		for(j=2;j<=sqrt((double)i);j++)
		{
			if (i%j==0) break;
		}
		if (j>sqrt((double)i)) count++;
	}
	cout<<count<<endl;
	return 0;
}