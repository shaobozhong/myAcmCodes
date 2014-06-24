#include<iostream>
using namespace std;

int main()
{
	int degree[1001];
	int n,m,i,a,b;
	while(scanf("%d",&n)!=EOF&&n)
	{
		scanf("%d",&m);
		memset(degree,0,sizeof(degree));
		for(i=1;i<=m;++i)
		{
			scanf("%d%d",&a,&b);
			++degree[a];
			++degree[b];
		}
		for(i=1;i<=n;++i)
		{
			if (degree[i]%2!=0) break;
		}
		if (i<=n) puts("0");
		else puts("1");
	}
	return 0;
}