#include<stdio.h>

int gcd(int a,int b)
{
	int r;
	while(b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int main()
{
	int a,b,c,d,g,res;
	int y;
	char sign;
	while(scanf("%d",&a)!=EOF)
	{
		getchar();
		scanf("%d",&b);
		sign=getchar();
		scanf("%d",&c);
		getchar();
		scanf("%d",&d);
		getchar();
		g=(b*d)/gcd(b,d);
		a=a*g/b;
		c=c*g/d;
		if (sign=='+') res=a+c;
		else if (sign=='-') res=a-c;
		if (res<0) 
		{
			printf("-");
			res*=-1;
		}
		else sign='+';
        y=gcd(res,g);
		res/=y;
		g/=y;
		//if (res>g) {printf("%d",res/g);res%=g;}
		if (g==1) printf("%d\n",res);
		else if (res!=0) printf("%d/%d\n",res,g);
		else puts("0");
	}
	return 0;
}