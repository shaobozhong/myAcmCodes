#include<stdio.h>
int main()
{
	double sum;
	int a[100002]={0};
	int n,x,y,i,z,max,k,s;
	scanf("%d",&n);
     max=0;
	for(z=1;z<=n;z++)
	{
		sum=0;
	for(i=1;i<=max;i++)
		a[i]=0;
        max=0;

		scanf("%d",&k);
		for(;k>=1;k--)
		{
			scanf("%d%d%d",&x,&y,&s);
			if (max<y) max=y;
			for(i=x;i<=y;i++)
			{
				if (s>a[i]) a[i]=s;
			}
		}
		for(i=1;i<=max;i++)
			sum+=a[i];
		printf("%.0f\n",sum);
	}
	return 0;
}