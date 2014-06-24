#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s[120000],str,result[120000];

bool cmp(const string &a,const string &b)
{
	return a.length()>b.length();
}
bool cmpr(const string &a,const string &b)
{
	return a<b;
}
int main()
{

	con sloca;
	bool la;
	int count=0,i,j,k,zcount=0;
	while(cin>>s[count])
	{
		count++;
	}
   
	
	for(i=0;i<zcount;i++)
		cout<<result[i]<<endl;
	return 0;
}