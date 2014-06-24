#include<iostream>
using namespace std;

int main()
{
	int loca;
	int n,u,d,count;
	while(scanf("%d%d%d",&n,&u,&d)!=EOF&&(n!=0||u!=0||d!=0))
	{
		loca=0;
		count=0;
		while(loca<n)
		{
			if (count%2==0) loca+=u;
			else loca-=d;
			++count;
		}
		printf("%d\n",count);
	}
	return 0;
}