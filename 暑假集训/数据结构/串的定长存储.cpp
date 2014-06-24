#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s,t;
	char op;
	cin>>s;
	while(cin>>op)
	{
		cin>>t;
		if (op=='A') 
		{
			cout<<s<<t<<endl;
		}
		else 
		{
			if (s>t) puts("1");
			else 
			{
				if (s<t) puts("-1");
				else
				{
					puts("0");
				}
			}
		}
	}
	return 0;
}