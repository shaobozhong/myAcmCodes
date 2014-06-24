#include<iostream>
using namespace std;

int work(int n)
{
	if (n==1) return 2;
	else return (work(n-1))+4*(n-1)+1;
}

int main()
{
	int i,n,t;
    cin>>t;
	while(t--)
	{
	cin>>n;
	cout<<work(n)<<endl;
	}
	return 0;
}