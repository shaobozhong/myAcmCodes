#include<iostream>
using namespace std;
int main()
{
	bool judge;
	int n,rs,re,count,temp,i,m,s,e;
	int father[1001];
	while(cin>>n,n)
	{
		for(i=1;i<=n;i++)
			father[i]=i;

		count=0;
		cin>>m;
		while(m--)
		{
			judge=true;
			cin>>rs>>re;
			if (rs>re) {temp=rs;rs=re;re=temp;}
			s=rs;
			e=re;
			while(father[s]!=s)
			{
				s=father[s];
			}
			while(father[e]!=e)
			{
				e=father[e];
			}
			if (e!=s) {count++;father[e]=s;}
		}
		cout<<n-1-count<<endl;
}
	return 0;
}