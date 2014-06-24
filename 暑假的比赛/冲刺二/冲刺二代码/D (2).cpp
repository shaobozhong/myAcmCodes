#include<iostream>
using namespace std;

int main()
{
	int f[26],sum;
	int t,n,i,j,k,temp;
	cin>>t;
	while(t--)
	{
		sum=2;
		cin>>n;
		f[1]=1;
		for(i=2;i<n;++i)
		{
			f[i]=0;
			temp=0;
			k=;
			for(j=2;j<=k;++j)
			{
				temp+=(j/2);
			}
            f[i]+=temp*f[i-1];
			temp=0;
			sum+=f[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}