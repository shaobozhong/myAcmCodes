#include<iostream>
using namespace std;

int main()
{
	double num;
	int n,m,i;
	while(cin>>n>>m)
	{
		for(i=32767;i>=1;i--)
		{
			if (i%m!=0) break;
		}
        num=i*((double)n/double(m));
		printf("%.0f %d\n",num,i);
	}
	return 0;
}