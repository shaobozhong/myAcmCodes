#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

typedef struct
{
	char s[100];
	int num;
}string1;

bool cmp(const string1 a,const string1 b)
{
	return a.num<b.num;
}
int main()
{
	int i,count,j;
	string1 a[1000];
	count=0;
	while(gets(a[count].s))
	{
		a[count].num=0;
        count++;
	}
	for(i=0;i<count;i++)
	{
		for(j=0;j<(int)strlen(a[i].s)-1;j++)
		{
			if (a[i].s[j]==' ') a[i].num++;
		}
	}
    sort(a,a+count,cmp);
	for(i=0;i<count;i++)
	{
		cout<<a[i].s<<endl;
	}
	return 0;
}