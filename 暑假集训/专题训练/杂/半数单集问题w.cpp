#include<iostream>
using namespace std;
int a[202];
int work(int n)
{
	int ans=1,i;
	if (a[n]>0) return a[n];
	for(i=1;i<=n/2;i++)
	{
		ans+=work(i);
		if ((i>10)&&2*(i/10)<=i%10) ans-=a[i/10];
	}
	a[n]=ans;
	return ans;
}
int main()
{
	int result,n;
	memset(a,0,sizeof(a));
	while(cin>>n,n)
	{
      result=work(n);
	  cout<<result<<endl;
	}
	return 0;
}