#include<stdio.h>
int main()
{
	int a,b,c,t,n,i;
	while(scanf("%d",&n)+1)
	{
		scanf("%d%d%d",&a,&b,&c);
		if (a<b) {t=a;a=b;b=t;}
		if (a<c) {t=a;a=c;c=t;}
		if (b<c) {t=b;b=c;c=t;}
		if(n>3) for(i=4;i<=n;i++)
		{
			scanf("%d",&t);
			if (t<=c) continue;
			else
			{
				if (t<=b) c=t;
				else
				{
					if (t<=a) {c=b;b=t;}
					else
					{
						c=b;b=a;a=t;
					}
				}
			}
			
		}
		printf("%d %d %d\n",a,b,c);
	}
	return 0;
}