#include<iostream>
#include<string>
using namespace std;

void del0( string &s)
{
	int i;
	while(s[0]=='0')
	{
		s.erase(0,1);
	}
	i=s.length()-1;
	while(s[i]=='0'||s[i]=='.')
	{
		if (s[i]=='.') {s.erase(i,1);break;}
		s.erase(i,1);
		i--;
	}
}

string interger_1(const string &s)
{
	int loca;
	string sz;
	loca=s.find(".");
	if (loca==-1) sz=s;
	else 
	{
		sz=s.substr(0,loca);
	}
	return sz;
}

string point_1(const string &s)
{
	int loca;
	string sx;
	loca=s.find(".");
	if (loca==-1) sx="";
	else 
	{
		sx=s.substr(loca+1);
	}
	return sx;
}

void add0(string &a,int rest)
{
   while(rest--)
   {
	   a.push_back('0');
   }
}
string plus_1(const string &a,const string &b)
{
	string az,ax,bz,bx,resultx="",result="",tresult;
	int axlen,bxlen,rest,i,j,add,temp;
	az=interger_1(a);
	bz=interger_1(b);
	ax=point_1(a);
	bx=point_1(b);
	axlen=ax.length();
	bxlen=bx.length();
	if (axlen>bxlen)
	{
		rest=axlen-bxlen;
		add0(bx,rest);
	}
	else if (bxlen>axlen)
	{
		rest=bxlen-axlen;
		add0(ax,rest);
	}
	i=ax.length()-1;
	add=0;
	while(i>=0)
	{
		temp=ax[i]+bx[i]-96+add;
		add=temp/10;
		tresult.push_back(temp%10+'0');
		resultx.insert(0,tresult);
		i--;
	}
	i=az.length()-1;j=bz.length()-1;
	while(i>=0&&j>=0)
	{
      temp=az[i]+bz[i]-96+add;
		add=temp/10;
		tresult.push_back(temp%10+'0');
		result.insert(0,tresult);
		i--;j--;
	}
	while(i>=0)
	{
		temp=az[i]+add-48;
		add=temp/10;;
		tresult.push_back(temp%10+'0');
		result.insert(0,tresult);
		i--;
	}
	while(j>=0)
	{
		temp=bz[j]+add-48;
		add=temp/10;
		tresult.push_back(temp%10+'0');
		result.insert(0,tresult);
		j--;
	}
	
	if (add!=0) 
	{tresult.push_back(add+'0');
		result.insert(0,tresult);
	}
	if (!resultx.empty()) del0(resultx);
	if (!resultx.empty())
	{
		result.push_back('.');
		result.append(resultx);
	}
	return result;
}

int main()
{
	string a,b;
	while(cin>>a>>b)
	{
		cout<<plus_1(a,b)<<endl;
	}
	return 0;
}