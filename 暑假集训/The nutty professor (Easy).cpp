#include<iostream>
using namespace std;

int main()
{
	int casenum;
	int d,n,s,p;
	scanf("%d",&casenum);
	while(casenum--)
	{
		scanf("%d%d%d%d",&d,&n,&s,&p);
		if (d+n*p<n*s) puts("parallelize");
		else 
		{
			if (d+n*p==n*s) puts("does not matter");
			else puts("do not parallelize");
		}
	}
	return 0;
}
