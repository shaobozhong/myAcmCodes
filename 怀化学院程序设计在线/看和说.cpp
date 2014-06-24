#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    char str[100000];
	int t,i,j,num;
    scanf("%d",&t);
	while(t--)
	{
		scanf("%s",str);
		for(i=0;i<(int)strlen(str);i++)
		{
			num=1;
			for(j=i+1;j<(int)strlen(str);j++)
			{
			if (str[i]!=str[j]) break;
			num++;
			}
			cout<<num<<str[i];
			i=j-1;
		}
		cout<<endl;
	}
	return 0;
}