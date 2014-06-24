#include<iostream>
using namespace std;

int main()
{
	int n,i,temp;
	while(cin>>n)
	{
		if (n==1) {cout<<n<<endl;continue;}
		temp=n;
		while(temp!=1)
		{
			for(i=2;i<=temp;++i)
			{
				if (temp%i==0) {temp/=i;if (temp!=1) cout<<i<<" ";else cout<<i<<endl;break;}
			}
		}
	}
	return 0;
}