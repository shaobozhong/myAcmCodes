#include<iostream>
using namespace std;

int a[10]={1,1,2,6,24,120,720,5040,40320,362880};
int main()
{
	int n;
	int i;
	while(scanf("%d",&n),n>=0)
	{
		if (n==0) {puts("NO");continue;}
		for(i=9;i>=0;--i)
		{
			if (n>=a[i]) {n-=a[i];if (n==0) break;}
		}
		if (n==0) puts("YES");
		else puts("NO");
	}
	return 0;
}