#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

typedef struct
{
	string s;
	int num;
}Love;

bool cmp(const Love &a,const Love &b)
{
	if (a.num==b.num) 
	{
		if (a.s.size()==b.s.size()) return a.s>b.s;
		return a.s.size()>b.s.size();
	}
	return a.num>b.num;
}

int main()
{
	Love *a;
	string str;
	int t,n,i,count,strloca;
	cin>>t;
	while(t--)
	{
		cin>>n;
		a=new Love[n];
		getchar();
		for(i=0;i<n;i++)
			getline(cin,a[i].s);
		for(i=0;i<n;i++)
		{
			count=0;
			str=a[i].s;
			strloca=str.find("TOJ");
			while(strloca!=-1)
			{
               count++;
			   str.erase(strloca,3);
               strloca=str.find("TOJ");
			}
			str=a[i].s;
			strloca=str.find("JOT");
			while(strloca!=-1)
			{
               count++;
			   str.erase(strloca,3);
			   strloca=str.find("JOT");
			}
			a[i].num=count;
		}
		sort(a,a+n,cmp);
		for(i=0;i<n;i++)
			cout<<a[i].s<<endl;
	}
	return 0;
}