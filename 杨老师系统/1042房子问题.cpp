#include<iostream>
using namespace std;

int main()
{
	int degree[10005];
	int n,m,a,b,i,max;
	while(scanf("%d%d",&n,&m)&&(n!=0||m!=0))
	{
		memset(degree,0,sizeof(degree));
		max=0;
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			++degree[a];
			++degree[b];
			if(max<degree[a]) max=degree[a];
			if (max<degree[b]) max=degree[b];
		}
		printf("%d\n",max);
	}
	return 0;
}