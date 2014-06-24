#include<stdio.h>
#include<math.h>
void main()
{
	int a,b,i,total,j;
	while(scanf("%d%d",&a,&b)>0&&a!=0||b!=0)
	{
		if (a>b) {j=a;a=b;b=j;}
		total=0;
		for(i=a;i<=b;i++)
		{if (i<2) continue;
			for(j=2;j<=sqrt(i);j++)
				if  (i%j==0) break;
			if (j>sqrt(i)) total++;	
		}
		printf("%d\n",total);
	}
}