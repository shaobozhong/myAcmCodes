#include<iostream>
using namespace std;

int main()
{
	int a,b,i,max,maxi;
	max=0;maxi=0;
	for(i=1;i<=7;i++)
	{
		cin>>a>>b;
		if (a+b>8&&a+b>max) {max=a+b;maxi=i;}
	}
	if (max==0) {puts("0");return 0;}
	cout<<maxi<<endl;
	return 0;
}