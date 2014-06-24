#include<iostream>
using namespace std;
int f[101][101];

int main()
{
	int n,m,i,j,sum;
	f[1][1]=1;
	for(i=1;i<=100;i++)
	{
		f[i][1]=1;
		f[i][i]=1;
	}
	for(i=2;i<=100;i++)
	{
		for(j=2;j<=i-1;j++)
		{
			f[i][j]=f[i-1][j-1]+j*f[i-1][j];
		}
	}
	while(cin>>n>>m)
	{
	   cout<<f[n][m]<<endl;
	}
	return 0;
}