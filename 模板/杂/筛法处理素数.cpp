#include<iostream>
#include<cmath>
using namespace std;
#define MAX 1001
bool la[MAX];

void pick()
{
	int i,j;
	memset(la,1,sizeof(la));
	la[1]=0;
	for(i=2;i<=sqrt(double(MAX-1));++i)
	{
		if (la[i])
		{
			for(j=i*i;j<=MAX-1;j+=i)
			{
				la[j]=0;
			}
		}
	}
}

int main()
{
	int i;
	pick();
	for(i=1;i<MAX;++i)
	{
		if (la[i]) printf("%d ",i);
	}
	putchar('\n');
	return 0;
}