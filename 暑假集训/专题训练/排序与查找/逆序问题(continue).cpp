#include<iostream>
using namespace std;

int main()
{
	int n,k,sum,temp,i;
	while(scanf("%d%d",&n,&k)>0&&n!=0||k!=0)
	{
		sum=1;
		if (n==0||n<k) {cout<<"0"<<endl;continue;}
		if (k==0||n==k) {cout<<"1"<<endl;continue;}
		sum=n-k*2
		printf("%d\n",sum);
	}
	return 0;
}