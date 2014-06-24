#include<iostream>
using namespace std;

#include<iostream>
#include<string>
using namespace std;

string dic[11]={"zero","one","two","three","four","five","six","seven","eight","nine","ten"};


int find1(const string &str)
{
	int i;
	for(i=1;i<=10;++i)
	{
		if (str==dic[i]) return i;
	}
	return 0;
}

int main()
{
	int casenum;
	string a,b;
	int a1,b1;
	int i;
	cin>>casenum;
	while(casenum--)
	{
		cin>>a>>b;
		a1=find1(a);
		b1=find1(b);
		for(i=a1;i<b1;++i)
		{
			cout<<dic[i]<<" ";
		}
		cout<<dic[i]<<endl;
	}
	return 0;
}
