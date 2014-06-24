#include<iostream>
using namespace std;

int main()
{
	int a[100];
	int i,d,m;
	while (scanf("%d%d",&m,&d)!=EOF&&(m!=0||d!=0))
	{
		a[0]=1;
		for (i=1;i<=d;++i)
		{
			if (i<=m+1) a[i]=1;
			else a[i]=a[i-1]+a[i-m-1];
		}
		printf("%d\n",a[d]);
	}
	return 0;
}