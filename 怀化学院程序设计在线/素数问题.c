#include<stdio.h>
#include<math.h>
int main()
{
	int x,y,i,j,sum=0;
	scanf("%d%d",&x,&y);
	for(i=x;i<=y;i++)
	{
        for(j=2;j<=sqrt(i);j++)
			if (i%j==0) break;
			if (j>sqrt(i)) {sum+=i;printf("%d ",i);}
	}
	printf("%d\n",sum);
}