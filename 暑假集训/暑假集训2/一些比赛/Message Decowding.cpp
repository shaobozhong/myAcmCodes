#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
	string source;
	int i;
	while(cin>>str)
	{
		getchar();
		getline(cin,source);
		for(i=0;i<int(source.size());++i)
		{
			if (source[i]>='A' && source[i]<='Z')
			{
				source[i]=str[int(source[i])-65]-32;
			}
			else 
			{
				if (source[i]>='a' && source[i]<='z')
			{
				source[i]=str[int(source[i])-97];
			}
			}
		}
		cout<<source<<endl;
	}
	return 0;
}