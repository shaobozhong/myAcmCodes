#include<stdio.h>
int main()
{
    int x,y,i,j,k,total=0;
	scanf("%d%d",&x,&y);
	for(i=1;i<=y/3+1&&i<=x;i++)
		for(j=1;j<=y/2+1&&j<=x-i;j++)
		{
			k=x-i-j;
				if (3*i+2*j+k==y&&k!=0) total++;
		}
		printf("%d\n",total);
	return 0;
}