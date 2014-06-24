#include<iostream>
using namespace std;

int main()
{
	int i;
	double s,e,rate;
	while(cin>>s>>rate>>e)
	{
	for(i=1;s<e;i++)
	{
       s*=(1+rate/100);
	}
	cout<<i-1<<endl;
	}
	return 0;
}