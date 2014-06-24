#include<iostream>
using namespace std;

int main()
{
	double money,a[4]={2.25,5.58,9.99};
	int i,j,n,time[4];
	while(cin>>n>>money)
	{
		time[3]=n/5;
		for(i=1;i<=time[3];i++)
		{
			money+=(18.0/100)*money;
		}
		n%=5;
		i=3;
		while(n)
		{
			time[i-1]=n/i;
			for(j=1;j<=time[i-1];j++)
			{
				money+=(a[i-1]/100)*money;
			}
			n%=i;
			i--;
		}
		while(i)
		{
			time[i-1]=0;
			i--;
		}
		for(i=0;i<=3;i++)
			cout<<time[i]<<endl;
		printf("%.2lf\n",money);
	}
	return 0;
}