#include<iostream>
using namespace std;

int gy(int a,int b)
{
	int temp;
	if (a<b)  {temp=a;a=b;b=temp;}
	while(a%b!=0)
	{
		temp=b;
		b=a%b;
		a=temp;
	}
	return b;
}
int main()
{
	int test,n,m;
	cin>>test;
	while(test--)
	{
		cin>>n>>m;
		if (gy(n,m)==1) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}