#include<stdio.h>
int main()
{
	int n,a[8001],b[8001];
	int i,j,temp,q,sum;
	while(scanf("%d",&n)>0)
	{
		for(i=1;i<n;i++)
			scanf("%d",&a[i]);
		q=1;
		a[0]=0;
		while(q!=n+1)
		{
			for(i=0;i<n;i++)
			{
				if(a[i]==-1)
					continue;
				if(a[i]==0)
				{    temp=i;
				}
			}
				a[temp]=-1;
				b[temp]=q;
				q++;
				for(i=temp;i<n;i++)
				{if(a[i]==-1)continue;
				a[i]--;}
		}
		 sum=0;
		for(j=1;j<=n;j++)
		{
			sum+=j;
		}
		if(sum%2==0)
		{for(j=0;j<n;j++)
				if(b[j]==n-2)
				{printf("%d\n",j+1);break;}
		}
		else
		{
			for(j=0;j<n;j++)
				if(b[j]==n-1)
				{printf("%d\n",j+1);break;}	
		}
	}
	return 0;
}