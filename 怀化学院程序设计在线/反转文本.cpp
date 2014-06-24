#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char s[100];
	int i,t;

	scanf("%d",&t);
	getchar();
	while(t--)
	{
		gets(s);
		for(i=strlen(s)-1;i>=0;i--)
		{
			printf("%c",s[i]);
		}
		cout<<endl;
	}
	return 0;
}