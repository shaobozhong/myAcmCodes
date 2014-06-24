#include<iostream>
using namespace std;

int main()
{
	int a,b,c;
	while(cin>>a>>b>>c)
	{
	if (a<b) a=b;
	if (a<c) a=c;
	cout<<c*c<<endl;
	}
	return 0;
}