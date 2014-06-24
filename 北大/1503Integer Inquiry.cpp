#include<iostream>
#include<string>
using namespace std;

string plus(const string &a,const string &b)
{
	string result,ttemp;
	int alen,blen,i,j;
	int add,temp;
	alen=a.size();
	blen=b.size();
	add=0;
	for(i=alen-1,j=blen-1;i>=0&&j>=0;i--,j--)
	{
		temp=add+((int)a[i]-48)+((int)b[j]-48);
		add=temp/10;
		ttemp.push_back(temp%10+48);
		result.insert(0,ttemp);
		ttemp.clear();
	}

	while(i>=0)
	{
		for(;i>=0;i--)
		{
			temp=add+(a[i]-48);
			add=temp/10;
			ttemp.push_back(temp%10+48);
			result.insert(0,ttemp);
			ttemp.clear();
		}
	}

	while(j>=0)
	{
		for(;j>=0;j--)
		{
			temp=add+(b[j]-48);
			add=temp/10;
			ttemp.push_back(temp%10+48);
			result.insert(0,ttemp);
			ttemp.clear();
		}
	}
	if (add!=0)
	{ttemp.push_back(add+48);
	result.insert(0,ttemp);
	ttemp.clear();
	}
	return  result;
}
int main()
{
	string a,b;
	a="";
	while(cin>>b&&b!="0")
	{
		a=plus(a,b);
	}
	cout<<a<<endl;
	return 0;
}