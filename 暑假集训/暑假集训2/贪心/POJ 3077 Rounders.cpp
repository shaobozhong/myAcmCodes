#include<iostream>
#include<string>
using namespace std;

int main()
{
	string num;
    int t;
	int i;
	int temp;
	int add;
	cin>>t;
	
	while(t--)
	{
		cin>>num;
		add=0;
		for(i=int(num.size())-1;i>0;--i)
		{
			if (num[i]>='5') ++num[i-1];
			num[i]='0';
		}
		if (num[i]>'9') {add=1;num[i]='0';}
		if (add) cout<<add;
		cout<<num<<endl;
	}
	return 0;
}