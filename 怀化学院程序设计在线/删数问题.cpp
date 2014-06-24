#include<iostream>
#include<string>
using namespace std;

int main()
{
	char max1;
	string num;
	int k,i;
	while(cin>>num)
	{
		cin>>k;
		while(k--)
		{

			max1=47;
			for(i=0;i<int(num.length());++i)
			{
				if (num[i]=='0' && !(max1==47||max1=='0') ) break;
				if (max1<num[i]) max1=num[i];
				if (i<int(num.length()) && num[i]>num[i+1]) break;
			}
			if (max1!=47) num.erase(num.find(max1),1);
		}


		for(i=0;i<int(num.length());++i)
		{
			if (num[i]!='0') break;
		}


		if (i==int(num.length())) puts("0");
		else 
		{
			for(;i<int(num.length());++i)
			{
				putchar(num[i]);
			}
			cout<<endl;
		}
	}
	return 0;
}