#include<iostream>
using namespace std;

int main()
{
	int n,max,i,j;
	cin>>n;
	max=1+(n-1)*2;
	for(i=1;i<=max;i+=2)
	{
		for(j=1;j<=(max-i)/2+1;++j)
			cout<<" ";
		for(j=1;j<=i;++j)
		cout<<"*";
		cout<<endl;
	}
	return 0;
}