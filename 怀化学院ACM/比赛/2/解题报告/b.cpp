#include <stdio.h>
int main()
{
	int i,j,ans,t,ii;
	while(scanf("%d%d",&i,&j) && i&&j)
	{
		if(i>j)
		{
			i^=j;j^=i;i^=j;
		}
		for(ans=0;i<=j;i++)
		{
			ii=i;t=1;
			while(ii-1)
			{
				t++;
				if(ii&1) ii=3*ii+1;
				else ii/=2;
			}
			if(ans<t)ans=t;
		}
		printf("%d\n",ans);
	}
	return 0;
}