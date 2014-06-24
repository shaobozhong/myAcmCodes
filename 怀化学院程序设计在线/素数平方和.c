#include<stdio.h>
#include<math.h>

int prime(int n)
{
 int i;
 if (n<=1) return 0;
 for(i=2;i<=sqrt(n);i++)
	 if (n%i==0) break;
 if (i>sqrt(n)) return 1;
 return 0;
}

int main()
{
	int n,m,i;
	double s=0;
   scanf("%d%d",&n,&m);
   for(i=n;i<=m;i++)
	   if (prime(i)) s+=i*i;
   printf("%.0f\n",s);
	return 0;
}