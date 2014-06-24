#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int minres;
	int t,n;
	int i,j,k,temp;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if (n==0) {puts("0");continue;}
		minres=INT_MAX;
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=n/i;++j)
			{
				if (n%(i*j)==0)
				{
				    k=n/(i*j);
					temp=(i*j+i*k+j*k)*2;
					if (minres>temp) minres=temp;
				}
			}
		}

		cout<<minres<<endl;
	}
	return 0;
}