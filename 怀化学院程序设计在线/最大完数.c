#include<stdio.h>
int main()
{
	int z,n,x,y,i,j,max=0,s;
	scanf("%d",&n);
	for(z=1;z<=n;z++)
	{
		max=0;
	scanf("%d%d",&x,&y);
	for(i=x;i<=y;i++)
	{
		s=0;
for(j=1;j<=i/2+1;j++)
		{
			if (i%j==0) s+=j; 
		}
		if (s==i) if (max<j) max=i;
	}
	printf("%d\n",max);
	}
	return 0;
}