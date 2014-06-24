#include<iostream>
using namespace std;

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m),n!=0||m!=0)
	{
		while(n&&m&&m!=n)
		{
			if (m%n==0) {m=n;break;}
			if (n%m==0) {n=m;break;}
			if (m>n) 
			{
				m=m%n;
			}
			else 
			{
				n=n%m;
			}
		}
		if (n!=0&&m!=0)
			printf("%d\n",m);
		else 
			puts("0");
	}
	return 0;
}