#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int a,int b)
{
	return a<b;
}

int main()
{
	int n,k,count,i,j;
	int *a;

	while(cin>>n>>k)
	{
		count=0;
		a=new int[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n,cmp);
		for(i=0;i<n;i++)
		{
			count++;
			for(j=i+1;j<n;j++)
			{
				if (a[j]-a[i]>k) {i=j-1;break;}
				
			}
	     i=j-1;
		}

		cout<<count<<endl;
	}
	return 0;
}