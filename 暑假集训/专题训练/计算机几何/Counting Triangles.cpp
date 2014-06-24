#include<iostream>
using namespace std;

int main()
{
	int n,i,j;
	int sum;
	while(cin>>n)
	{
		sum=0;
		for(i=1;i<=n;i++)//这个循环可以替换为n*n;
		{
			sum+=i+i-1;
		
		}
		if (n>1) sum++;
		for(i=n;i>1;i--)
		{
			for(j=i;j>=2;j--)
			{
				sum+=i-j+1;
			}
		}
		if (n>=2) sum--;
		if (n>=4) 
		{
			for(i=2;i<=n-2;i++)
			{
				for(j=2;j<=i&&i<=n-j;j++)
				{
					sum+=i-j+1;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}