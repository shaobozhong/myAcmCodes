#include<iostream>
#include<string>
using namespace std;


int main()
{
    string s;
	int sg,i;

	while(cin>>s)
	{
		cin>>sg;
		while(sg)
		{
           for(i=0;i<(int)s.length();i++)
			{
				if (i==(int)s.length()-1) {s.erase(i,1);sg--;break;}
				if (s[i]>s[i+1]) {s.erase(i,1);sg--;break;}
			}
	}
		i=0;
		while(s[i]=='0'&&i<(int)s.length())
		{
			s.erase(0,1);
		}
		if (s.empty()) cout<<"0"<<endl;
		else cout<<s<<endl;
	}
	return 0;
}