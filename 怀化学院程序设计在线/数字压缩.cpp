#include<iostream>
#include<string>
#include<string.h>
using namespace std;

string c;
int f,r,len1,len2;
string strf,strr;


string __itoa(int n)
{
	char temp[2];
	int r;
	string res;
	res="";
	temp[1]='\0';
	if (n==0) res.insert(0,"0");
	while(n)
	{
		r=n%10;
		temp[0]=r+48;
		res.insert(0,temp);
		n/=10;
	}
	return res;
}
int _transform(const string &s)
{
	int res,i,weight=1;
	res=0;
	for(i=(int)s.size()-1;i>=0;--i)
	{
		res+=(s[i]-48)*weight;
		weight*=10;
	}
    return res;
}

string _MSD(int n,const string &s)
{          
	char temp[2];
	int i;
	string res;
	temp[1]='\0';
	for(i=n-1;i>=0;--i)
	{
		temp[0]=s[i];
		res.insert(0,temp);
	}
    return res;
}


string _LSD(int n,const string &s)
{
	int i;
	string res;
	char temp[2];
	temp[1]='\0';
	for(i=(int)s.size()-1;i>=0&&i>=(int)s.size()-n;--i)
	{

		temp[0]=s[i];
		res.insert(0,temp);
	}
	for(;i>=(int)s.size()-n;--i)
	{
		res.push_back('0');
	}
    return res;
}

bool _judge()
{
	char s[40];
	int i,weight;
	string strr_1;
	string tempr;
	int temp;
	temp=_transform(c);
	if (temp>f) {if (temp==r) return true;else return false;}
	tempr=_LSD((int)c.size(),strr);
	if (tempr!=c) return false;
	if (_transform(_LSD((int)c.size(), strf))<temp) 
	{
		strr_1=_MSD((int)(strf.size()-c.size()), strf);
		strr_1.append(c);
		if (strr_1==strr) return true;
		else return false;
	}
	else 
	{
		weight=1;
		for(i=1;i<=(int)c.size();++i)
		{
             weight*=10;
		}
		strr_1=_MSD((int)(strf.size() - c.size()), strf);
		strr_1.append(c);
		weight+=_transform(strr_1);
		strr_1="";
		strr_1=__itoa(weight);                      
		if (strr_1==strr) return true;
		else return false;
	}
    return false;
}
int main()
{
	int i;
	char ch,temp[2];
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	while(scanf("%d%c%d",&f,&ch,&r)!=EOF)
	{
		strf="";
		strr="";
		c="";
		strf=__itoa(f);
		strr=__itoa(r);
		temp[1]='\0';
		cout<<strf<<"-";
		for(i=(int)strr.size()-1;i>=0;--i)
		{
			temp[0]=strr[i];
			c.insert(0,temp);
			if (_judge()) break;
		}
		cout<<c<<endl;
	}
	return 0;
}
