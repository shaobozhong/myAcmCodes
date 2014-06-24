#include<iostream>
#include<string>
using namespace std;


int main()
{
	int t,n;
    int price,tmpp;
	string name,tmpname;
	cin>>t;
	while(t--)
	{
		cin>>n;
		price=0;
		while(n--)
		{
			cin>>tmpp>>tmpname;
			if (price<tmpp) {price=tmpp;name=tmpname;}
		}
		cout<<name<<endl;
	}
	return 0;
}