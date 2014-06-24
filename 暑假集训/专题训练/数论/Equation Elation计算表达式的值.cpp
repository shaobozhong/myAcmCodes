#include<iostream>
#include<string>
#include<vector>
using namespace std;

int calc(int a,int b,char sign)
{
	switch(sign)
	{
	case '+':return a+b;break;
	case '-':return a-b;break;
	case '*':return a*b;break;
	case '/':return a/b;break;
	}
	return 0;
}

bool PRI(char a,char b)
{
	if (a=='*'||a=='/'||b=='+'||b=='-') return true;
	return false;
}
int main()
{
	int i,j;
	bool space_1;
	vector<int>a;
	string s,sign;
	string str;
	while(getline(cin,s))
	{
		space_1=false;
		cout<<s;
		for(i=0;i<(int)s.size();i++)
		{
			if (s[i]==' ') {i++;}
			if (s[i]=='=') {if (s[i+1]==' '){ i++;space_1=true;}break;}
			if (isdigit(s[i]))
			{
				for(j=i+1;isdigit(s[j]);j++){}
				str=s.substr(i,j-i);
				a.push_back(atoi(str.c_str()));
				i=j;
			}
			else {sign.push_back(s[i]);}
		}
		str=s.substr(i);
		while(!sign.empty())
		{
          for(i=0;i<sign.size();i++)
		  {
			  if (i==sign.size()-1||PRI(sign[i],sign[i+1])) 
			  {
				  a[i]=calc(a[i],a[i+1],sign[i]);
				  a.erase(i+1,1);
				  sign.erase(i,1);
			  }
		  }
				  
		}
	}
	return 0;
}