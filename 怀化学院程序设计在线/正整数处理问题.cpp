#include<iostream>
using namespace std;

int main()
{
	int a[10];
	int n,i,j;
	cin>>n;
    i=0;
	while(n)
	{
		a[i]=n%10;
		n/=10;
		i++;
	}

	cout<<i<<endl;
	for(j=i-1;j>=0;j--)
	{
		cout<<a[j]<<" ";
	}
	cout<<endl;

	for(j=0;j<i;j++)
	{
		cout<<a[j];
	}
	cout<<endl;
	return 0;
}