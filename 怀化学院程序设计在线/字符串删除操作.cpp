
#include <iostream>
#include <string.h>
using namespace std;

void Delete(char *s,char *t)
{
	//删除主串s中所有包含t的子串
	char *subloc;  //子串位置的指针
	int i,k,len_t = strlen(t);
	subloc=strstr(s,t);  //定位子串在主串中的首指针
	while(subloc)
	{
		for(i=0;i<len_t;i++)
			*(subloc+i)='0';  //将主串中相应位置全置为'0'
		subloc=strstr(s,t);
	}
	k=0;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]!='0')
		{
			cout<<s[i];
			k++;
		}
	}
	if(k==0)
		cout<<"NULL STRING";
	cout<<endl;
}

int main()
{
	int n;
	char s[81],t[81];
	cin>>n;  //用例个数
	while(n--)
	{
		cin>>s;
		cin>>t;
		Delete(s,t);
	}
	return 0;
}
