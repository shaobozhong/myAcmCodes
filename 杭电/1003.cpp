#include<stdio.h>

int main()
{
	int a,b,c ;
	double d,e,f;
   int sum,max,min;
	while(scanf("%lf%d%d%d",&sum,&a,&b,&c),a!=0||b!=0||c!=0||sum!=0)
	{
     if (a>0) f=a-0.5;else f=a;
	 if (b>0) d=b-0.5;else d=b;
	 if (c>0) e=c-0.5;else e=c;
	 min=f*9+d*4+e*4+0.5;
	 max=(a+0.499999)*9+(b+0.499999)*4+(c+0.499999)*4+0.5;
     if (sum>=min&&sum<=max) printf("yes\n");
	  else printf("no\n");
	}
	return 0;
}