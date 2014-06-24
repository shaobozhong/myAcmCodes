#include<iostream>
using namespace std;

int main()
{
	int m,d;
	long long  a[110];
	while (scanf("%d%d",&m,&d)!=EOF&&(m!=0||d!=0))
	{
		a[0]=1; 
		for (int i=1;i<=d;++i)
		{
			if (i<=m) a[i]=a[i-1]+1;
			else a[i]=a[i-1]+a[i-m];
		}
		printf("%lld\n",a[d]);
	}
	return 0;
}