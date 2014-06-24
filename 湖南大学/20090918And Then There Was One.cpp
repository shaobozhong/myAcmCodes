#include<iostream>
using namespace std;

int main()
{
	int a[10001],n,k,m,i,j,count;
	while(scanf("%d%d%d",&n,&k,&m)>0&&(n!=0||m!=0||k!=0))
	{
		for(i=1;i<=n;i++)
		{
			a[i]=i;
		}
		count=m%n;
		if (count==0){count=n;}
		for(i=count;i<=n-1;++i)
		{
			a[i]=a[i+1];
		}
		for(i=n-1;i>=2;--i)
		{
            count=(count+k-1)%i;
			if (count==0) count=i;
			for(j=count;j<i;++j)
			{
				a[j]=a[j+1];
			}
		}
		printf("%d\n",a[1]);
	}
	return 0;
}