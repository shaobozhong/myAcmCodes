#include<iostream>
using namespace std;

int main()
{
	int n,num;
	int sum;
	int i,j;
	sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			scanf("%d",&num);
			if (j<=i) sum+=num;
		}
	}
	printf("%d\n",sum);
	return 0;
}