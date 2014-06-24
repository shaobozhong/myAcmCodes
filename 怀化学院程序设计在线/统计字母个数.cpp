#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char a[100];
	int i,a_count=0,b_count=0;
	while(gets(a))
	{
		a_count=0;b_count=0;
	for(i=0;i<(int)strlen(a);i++)
	{
		if (a[i]>='A'&&a[i]<='Z') a_count++;
		else if (a[i]>='a'&&a[i]<='z') b_count++;
	}
	cout<<b_count<<endl;
	cout<<a_count<<endl;
	}
	return 0;
}