#include<iostream>
using namespace std;

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
	    scanf("%d",&n);
		if (240%n==0)
		{
			puts("YES");
		}
		else 
		{
			puts("NO");
		}
	}


	return 0;
}