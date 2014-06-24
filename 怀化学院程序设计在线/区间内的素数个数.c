#include<stdio.h>
#include<math.h>
int panduan(int n)
{
	int i;
	for(i=2;i<=sqrt(n);i++)
		if (n%i==0) break;
	if (i>sqrt(n)) return 1;
	return 0;
}
int main()
{
	int a,b,i,s;
	while(scanf("%d%d",&a,&b)>0&&a!=0||b!=0)
	{
		s=0;
		if (a<2) a=2;
		for(i=a;i<=b;i++)
		{
			if(panduan(i)) s++; 
		}
		printf("%d\n",s);
	}
	return 0;
}