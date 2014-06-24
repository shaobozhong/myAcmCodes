#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int a[1001];


int main()
{
	int i;
	int l,h,r;
	int min1,max1;
    int n;
	while(cin>>n)
	{
		min1=INT_MAX;
		max1=0;
		memset(a,0,sizeof(a));
		while(n--)
		{
			cin>>l>>h>>r;
			if (min1>l) min1=l;
			if (max1<r) max1=r;
			for(i=l;i<r;++i)
			{
				if (a[i]<h) a[i]=h;
			}
		}

		for(i=min1;i<max1;++i)
		{
			if (i==1 || a[i]!=a[i-1]) 
			{
				cout<<i<<" "<<a[i]<<" ";
			}
		}
		cout<<max1<<" "<<a[max1]<<endl;
	}
	return 0;
}