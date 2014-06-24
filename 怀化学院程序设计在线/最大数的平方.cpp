#include<iostream>
using namespace std;

int main()
{
	int a,b,c,max;
	cin>>a>>b>>c;
	if (a<b) a=b;
	if (a<c) a=c;
	cout<<a*a<<endl;
	return 0;
}