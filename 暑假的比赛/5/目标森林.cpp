#include<iostream>
#include<string>
using namespace std;

int main()
{
	int i,j;
	string s;
	char temp,ttemp;
	while(getline(cin,s))
	{
		for(i=s.size();i>=1;i--)
		{
			if (i%2==0)
			{
				temp=s[i-1];
				for(j=2*i;j<=s.size();j+=i)
				{
	                ttemp=s[j-1];
					s[j-1]=temp;
					temp=ttemp;
				}
				s[i-1]=temp;
			}
			else 
			{
				temp=s[i-1];
				for(j=2*i;j<=s.size();j+=i)
				{
					s[j-i-1]=s[j-1];
				}
				if (j-i<=s.size())s[j-i-1]=temp;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}