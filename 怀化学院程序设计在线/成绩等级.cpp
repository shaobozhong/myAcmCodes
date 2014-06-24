#include<iostream>
using namespace std;

int main()
{
	double x;
	int i;
	double a[4]={90,80,70,60};
	cin>>x;
	i=0;
	while(i<4)
	{
		if (x>=a[i])  {putchar('A'+i);putchar('\n');break;}
		i++;
	}
	if (i>=4) puts("E");
	return 0;
}