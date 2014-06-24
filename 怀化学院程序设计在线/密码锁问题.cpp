#include<iostream>
#include<string>
using namespace std;

int main()
{
	int i;
	string res;
	string change;
	cin>>res;
	while (cin>>change)
	{
		for (i=0;i<(int)res.size();++i)
		{
			res[i]+=(int)change[i]-48;
			if (res[i]>57) res[i]=((int)res[i]-48)%10+48;
		}
	}
	cout<<res<<endl;
	return 0;
}