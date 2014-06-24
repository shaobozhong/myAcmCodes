#include<iostream>
using namespace std;

int main()
{
	int i;
	double a[6],sum,max,min;
	while(1)
	{
		max=0;
		min=10000;
		sum=0.0;
		for(i=0;i<6;++i)
		{
			cin>>a[i];
			sum+=a[i];
			if (max<a[i]) max=a[i];
			if (min>a[i]) min=a[i];
		}
		if (sum==0) break;
		sum-=max+min;
		cout<<sum/4<<endl;
	}
	return 0;
}