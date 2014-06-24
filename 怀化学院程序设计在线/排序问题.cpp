#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


vector <string> s;
char a[]={'a','A','b','B','c','C','d','D','e','E','f','F','g','G','h','H','i','I','j','J','k','K','l','L','m','M','n','N','o','O','p','P','q','Q','r','R','s','S','t','T','u','U','v','V','w','W','x','X','y','Y','z','Z'};


int find(char ch)
{
	int i;
	for(i=0;i<52;++i)
	{
		if (ch==a[i]) return i;
	}
	return 0;
}

bool compare(const string &a,const string &b)
{
	int i,fre,last;
	for(i=0;i<(int)a.size()&&i<(int)b.size();i++)
	{
		fre=find(a[i]);last=find(b[i]);
		if (fre<last) return true;
		else if (fre>last) return false;
	}
	if (i<(int)a.size()) return true;
	return false;
}

bool cmp(const string &a,const string &b)
{
	return compare(a,b);
}

int main()
{
	string temp;
	
	int n,i;
	while(cin>>n)
	{
		for(i=1;i<=n;++i)
		{
			cin>>temp;
			s.push_back(temp);
		}
		sort(s.begin(),s.end(),cmp);
		for(i=0;i<s.size();++i)
		{
			cout<<s[i]<<endl;
		}
	}
	return 0;
}