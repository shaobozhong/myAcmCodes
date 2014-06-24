#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

typedef struct 
{
	string s;
	int sum;
}string1;

bool cmp(const string1 a,const string1 b)
{
	return a.sum<b.sum;
}
int main()
{
	string1 a[1000];
	int n,i,j;
	while(cin>>n,n!=0)
	{
		for(i=0;i<n;i++)
			cin>>a[i].s;
		for(i=0;i<n;i++)
		{
			a[i].sum=0;
			for(j=0;j<a[i].s.size();j++)
			{
				a[i].sum+=a[i].s[j]-'0';
			}
		}
		sort(a,a+n,cmp);
		for(i=0;i<n-1;i++)
		{
			cout<<a[i].s<<" ";
		}   
		cout<<a[i].s<<endl;
	}
	return 0;
}