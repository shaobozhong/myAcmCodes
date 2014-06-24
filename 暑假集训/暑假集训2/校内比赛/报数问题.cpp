#include<iostream>
using namespace std;

int main()
{
	int a[60];
	int n;
	int count,k,i,j;
	while(cin>>n)
	{
		for(i=1;i<=n;++i)
		{
			a[i]=i;
		}

		count=1;
		k=2;
		for(i=n;i>=3;--i)
		{
			count=(count+k-1)%i;
			if (count==0) count=i;
			if (count==1) {++i;continue;} 
			cout<<a[count]<<" ";
			for(j=count;j<=i-1;++j)
			{
				a[j]=a[j+1];
			}
		}
		cout<<endl<<a[1]<<" "<<a[2]<<endl;
	}
	return 0;
}