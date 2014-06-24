#include<stdio.h>
int main()
{
	int x,y,i,total=0;
	scanf("%d%d",&x,&y);
	for(i=x;i<=y;i++)
		if (i%3==2&&i%5==3) total++;
	printf("%d\n",total);
	return 0;
}