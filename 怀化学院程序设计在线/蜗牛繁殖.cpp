#include<iostream>
using namespace std;

int main()
{
	int n,i;
	double a[60];
	a[0]=1;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		if (i<3) a[i]=a[i-1]+1;
		else a[i]=a[i-1]+a[i-2];
	}
	for(i=1;i<=n;i++)
	{
		if (i<3) cout<<"1"<<endl;
		else printf("%.0f\n",a[i-2]);
	}
	return 0;
}