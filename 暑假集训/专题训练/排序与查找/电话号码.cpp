#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

typedef struct 
{
	string s;
}string1;

bool cmp(const string1 a,const string1 b)
{
	return a.s.size()>b.s.size();
}
int main()
{
	bool pr;
	string str;
	string1 a[10000];
	int t,n,i,j,stlen,k;
	cin>>t;
	while(t--)
	{
		pr=true;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a[i].s;
		}
        sort(a,a+n,cmp);	
        for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				stlen=a[j].s.size();
				for(k=0;k<stlen;k++)
				{
					if (a[i].s[k]!=a[j].s[k]) break;
				}
				if (k==stlen) pr=false;
			}
			if (!pr) break;
		}
		if (pr) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	} 
	return 0;
}