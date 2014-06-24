#include<iostream>
using namespace std;

int work(int n,int m)
{
	if ((n<1)||(m<1)) return 0;
	if (n==1 || m==1) return 1;
    if (n<m) return work(n,n);
	if (n==m) return work(n,m-1)+1;
	return work(n,m-1)+work(n-m,m);
}

int main()
{
    int n,ans;
	while(scanf("%d",&n)!=EOF)
	{
         ans=work(n,n);
		 printf("%d\n",ans);
	}
	return 0;
}