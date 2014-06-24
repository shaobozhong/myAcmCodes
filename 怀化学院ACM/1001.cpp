#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double a,b,c;
	while(cin>>a>>b>>c)
	{
		cout<<setiosflags(ios::fixed)<<a+b+c<<endl;
		cout<<setiosflags(ios::fixed)<<700000000;
	}
	return 0;
}