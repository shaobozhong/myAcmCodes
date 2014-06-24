#include<iostream>
#include<string>
#include<string.h>
using namespace std;

int main()
{
	string dic="aeiou";
	char str[50];
    int n,len,i;
	cin>>n;
	while(n--)
	{
		cin>>str;
		len=int(strlen(str));
		if (dic.find(str[0])!=-1) 
		{
			str[len]='c';
			str[len+1]='o';
			str[len+2]='w';
			str[len+3]='\0';
		cout<<str<<endl;
		}
		else 
		{
          for(i=1;i<len;++i)
		  {
			  putchar(str[i]);
		  }
		  putchar(str[0]);
		  putchar('o');
		  putchar('w');
		  cout<<endl;
		}

	}
	return 0;
}