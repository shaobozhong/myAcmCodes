#include<stdio.h>
int main()
{
   int a,b,t,s;
   while(scanf("%d%d",&a,&b)>0&&a!=0||b!=0)
   {
	   s=a*b;
	   if (a<b) {t=a;a=b;b=t;}
	   while(a%b!=0)
	   {
		   t=b;
		   b=a%b;
		   a=t;
	   }
	   printf("%d\n",s/b);
   }
	return 0;
}