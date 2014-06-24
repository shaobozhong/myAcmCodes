#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str,temp;
	int i;
	cin>>str;
	while(cin>>temp)
	{
		for(i=0;i<(int)str.size();++i)
		{
			str[i]+=(int)(temp[i]-48);
			if (str[i]>57) str[i]='0'+(str[i]-48)%10;
		}
	}
	cout<<str<<endl;
	return 0;
}