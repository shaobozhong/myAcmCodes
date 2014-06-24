#include<iostream>
using namespace std;
int a[101][101];


void dynamic(int m)
{
	int i,j;
	for(i=m-2;i>=0;i--)
	{
		for(j=0;j<=i;j++)
		{
			a[i][j]+=a[i+1][j]>a[i+1][j+1]?a[i+1][j]:a[i+1][j+1];
		}
	}
	cout<<a[0][0]<<endl;
}
int main()
{
	
	int t,m,i,j;
	cin>>t;
	for(;t>=1;t--)
	{
		cin>>m;
		for(i=0;i<=m-1;i++)
		{
			for(j=0;j<=i;j++)
				cin>>a[i][j];
		}
		dynamic(m);
	}
	return 0;
}