#include<iostream>
using namespace std;

int main()
{
	int i,j;
	int t,m;
	int ti,va;
	int s[105];
	while(cin>>t>>m)
	{
		for(i=0;i<=t;++i)
		{
			s[i]=0;
		}
		while(m--)
		{
			cin>>ti>>va;
			for(j=t;j>=ti;--j)
			{
				if (s[j-ti]+va>s[j]) 
				{
					s[j]=s[j-ti]+va;
				}
			}
		}
		cout<<s[t]<<endl;
	}
	return 0;
}
