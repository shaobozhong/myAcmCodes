#include<iostream>
#include<string>
using namespace std;

int main()
{
	int i,slen;
	string z="",j="",o="",z7="",s="";
	while(getline(cin,s),s!="")
	{
		z="";j="";o="";z7="";
		slen=s.size();
		for(i=slen-1;i>=0;i--)
		{
			if (s[i]=='Z') {z.push_back('Z');s.erase(i,1);}
			else if (s[i]=='O') {o.push_back('O');s.erase(i,1);}
			else if (s[i]=='J') {j.push_back('J');s.erase(i,1);}
			else if (s[i]=='7') {z7.push_back('7');s.erase(i,1);}
		}
		cout<<z<<o<<j<<z7<<s<<endl;
		s.clear();
	}
	return 0;
}