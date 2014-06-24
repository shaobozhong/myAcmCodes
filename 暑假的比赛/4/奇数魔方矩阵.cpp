#include <stdio.h>
int main()
{
	int x,y,i,j,a[20][20],n;

	while(scanf("%d",&n)!=EOF&&n)
	{

		y=(n+1)/2;x=y+1;
		for(i=1;i<=n*n;i++)
		{
			a[x][y]=i;
			if(i%n==0)
			{
				//i为n的倍数是，下一个数将出现在此数下方二格
				x+=2;
			}
			else  //否则将是斜行右下格
			{
				x+=1;
				y+=1;
			}
			if(x>n)
				x-=n;
			if(y>n)
				y-=n;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				printf("%4d",a[i][j]);
			printf("\n");
		}
	}
	return 0;
}

