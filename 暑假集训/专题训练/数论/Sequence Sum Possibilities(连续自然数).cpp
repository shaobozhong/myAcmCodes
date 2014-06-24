#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	double x;
	int t,test,n,i,count,sum;
	cin>>t;
	while(t--)
	{
		count=0;
		cin>>test;
		cin>>n;
		sum=(int)2*sqrt((double)n);
		for(i=2;i<=sum;i++)
		{
			if (2*n%i==0&& n*2/i+1-i>0&&(n*2/i+1-i) % 2 == 0)
		 count++;
		}
		cout<<test<<" "<<count<<endl;
	}
	return 0;
}
//等差数列的公式判断a【1】，a【i】都大于零 且为整数 a【n】》a【1】
//2*n%i=a[1]+a[i];
//2*n/i-(i-1)=2*a[1];