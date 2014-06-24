#include<iostream>
#include<string>
using namespace std;

char a[64]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','/'};

string lcode(char ch)
{
	char ch_1[2];
	string result;
	int num;
	num=(int)ch;
	ch_1[1]=0;
	while(num)
	{
		ch_1[0]=num%2+'0';
		result.insert(0,ch_1);
		num/=2;
	}
	while(result.size()<8)
	{
		result.insert(0,"0");
	}
	return result;
}

char transform(const string &s)
{

	string::reverse_iterator i;
	string str;
	int t=1,num=0;
	str=s.substr(0,6);
	for(i=str.rbegin();i!=str.rend();i++)
	{
		num+=(*i-'0')*t;
		t*=2;
	}
    return a[num];
}

string code(const string &s)
{
	string::const_iterator i;
	string temp,result;
	for(i=s.begin();i!=s.end();i++)
	{
		temp.append(lcode(*i));
	}
	while(temp.size()%6!=0)
	{
		temp.push_back('0');
	}
	while(temp.size()>=6)
	{
		result.push_back(transform(temp));
		temp.erase(0,6);
	}
	return result;
}

int main()
{
	string s,result;
	string str;
	int t,len;
	cin>>t;
	getchar();

	while(t--)
	{
		getline(cin,s);
		len=3-(int)s.size()%3;
		if (len==3) len=0;
		while(s.size()>=3)
		{
			str=s.substr(0,3);
			cout<<code(str);//result.append(code(str));
			s.erase(0,3);
		}
		while(s.size()>0)
		{
			str=s.substr(0);
			cout<<code(str);//result.append(code(str));
		    s.clear();
		}
		while(len--)
		{
			cout<<'=';//result.push_back('=');
		}
		cout<<endl;//cout<<result<<endl;
		//result.clear();
	}
	return 0;
}