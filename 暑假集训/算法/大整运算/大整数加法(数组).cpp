#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	char s[120];
	int t[120]={0};
	int i,len;
	while(cin>>s)
	{
		if (strcmp(s,"0")==0) break;
		len=(int)strlen(s);
		for(i=len-1;i>=0;i--)
		{
			t[len-1-i]+=(int)s[i]-48;
		}
	}
	for(i=0;i<=115;i++)
	{
		if (t[i]>=10)
		{
			t[i+1]+=t[i]/10;
			t[i]%=10;
		}
	}
	for(i=119;i>=0;i--)
	{ if (t[i]!=0) break;}
	for(;i>=0;i--)
		cout<<t[i];
	cout<<endl;
	return 0;
}
