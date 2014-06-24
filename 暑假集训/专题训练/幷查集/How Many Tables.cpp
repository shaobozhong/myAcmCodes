#include<iostream>
using namespace std;

int main()
{
	int father[1001];
	int test,n,m,temp,count,e,re,s,rs,i;
	cin>>test;
	while(test--)
	{
		count=0;
		cin>>n>>m;
		for(i=1;i<=n;i++)
			father[i]=i;
        for(i=1;i<=m;i++)
		{
			cin>>rs>>re;
			if (rs>re) {temp=rs;rs=re;re=temp;}
			s=rs;e=re;
			while(e!=father[e])
			{
				e=father[e];
			}
			while(s!=father[s])
			{
				s=father[s];
			}
			if (e!=s) father[e]=s;
		}
		for(i=1;i<=n;i++)
			if (father[i]==i) count++;
		cout<<count<<endl;
	}
	return 0;
}