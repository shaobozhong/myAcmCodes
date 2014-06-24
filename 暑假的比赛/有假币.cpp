#include<iostream>
using namespace std;

int main()
{
	int count,n;
	while(scanf("%d",&n)&&n)
	{
		for(count=0;n>1;++count)
		{
			if (n%3==0) n/=3;
			else n=n/3+1;
		}
		printf("%d\n",count);
	}
	return 0;
}