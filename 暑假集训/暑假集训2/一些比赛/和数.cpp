#include<iostream>
#include<set>
using namespace std;


	int a[101];
	int t,n;

bool panduan(int k)
{
	int i,j;
   	for(i=0;i<n;++i)
		{
			if (i!=k)
			{
			for(j=0;j<n;++j)
			{
				if (i!=j && k!=j && a[i]+a[j]==a[k]) return true;
			}
			}
		}
	return false;
} 

int main()
{
       int i,count;
	   cin>>t;
	while(t--)
	{
		count=0;
		cin>>n;
	    for(i=0;i<n;++i)
		{
			cin>>a[i];
		}

		for(i=0;i<n;++i)
		{
			if (panduan(i)) count++;
		}
		cout<<count<<endl;
	}
	return 0;
}