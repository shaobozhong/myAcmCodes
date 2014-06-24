#include<iostream>
using namespace std;
__int64 f[101][101];

int main()
{
	int n,i,j;
	__int64	sum;
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
	while(cin>>n)
	{
		sum=0;
       for(i=2;i<n;i++)
		   sum+=f[n][i];
	   if (n>1)sum+=2;
	   else sum+=1;
	   cout<<sum<<endl;
	}
	return 0;
}