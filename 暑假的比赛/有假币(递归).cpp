#include<iostream>
using namespace std;
int n;

int work(int n)
{
   if (n<=1) 
   {
	 return 0;
   }
   if (n%3==0) {return (1+work(n/3));}
   else 
   {
	   return 1+(work(n/3+1));
   }

  return 0;
}

int main()
{
	
	while(scanf("%d",&n)!=EOF&&n)
	{
		if (n==1) puts("0");
		else 
		{
	    printf("%d\n",work(n));
		}

	}
	return 0;
}