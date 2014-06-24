#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(const int &a,const int &b)
{
	return a<b;
}

int main()
{
	int *a;
	double temp,sum;
	int i,n;
	while(cin>>n)

	{
		sum=0;
		temp=0;
		a=new int[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
     sort(a,a+n,cmp);
	 for(i=0;i<n;i++)
	 {
		 temp+=a[i];
		 sum+=temp;
	 }
	 printf("%.2f\n",sum/n);
	}
	return 0;
}