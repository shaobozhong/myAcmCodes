#include<iostream>
using namespace std;

int main()
{
	int i,j,k,n,count1,max1;
	while(cin>>i,i!=0)
	{
		cin>>j;
		max1=0;
		for(k=i;k<=j;++k)
		{
			n=k;
			count1=0;
			while(1)
			{
				count1++;
				if (n==1) break;
				if (n%2==0) n/=2;
				else n=3*n+1;
			}
			if (max1<count1) max1=count1;
		}

		cout<<max1<<endl;
	}
	return 0;
}