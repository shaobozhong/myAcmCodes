#include<iostream>
using namespace std;

int main()
{
	int n,i,j,max,min;
	while(scanf("%d",&n)!=EOF)
	{
		if (n==1) {printf("%3d\n",1);continue;}
		max=2*((n-2)+n);min=n+1;
		for(i=1;i<n;i++)
		{
			printf("%3d",i);
		}
		printf("%3d\n",i);
		for(i=2;i<=n-1;i++)
		{
			printf("%3d",max);
			for(j=1;j<=n-2;j++)
			{
				printf("%3s","");
			}
			printf("%3d\n",min);
			--max;++min;
		}
		for(i=max;i>min;i--)
		{
			printf("%3d",i);
		}
		printf("%3d\n",i);
	}
	return 0;
}