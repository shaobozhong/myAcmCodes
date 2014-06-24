#include<iostream>
using namespace std;

int main()
{
	int a[51],b[51];
	int t,i,j,num,sum;
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		a[0]=1;
		b[0]=1;
		for(i=1;i<=26;++i)
		{
			scanf("%d",&num);
			if (num!=0)
			{
				for(j=0;j+num<=50;++j)
				{
				 b[j+num]+=a[j];
				}
				for(j=0;j<=50;++j)
				{
					a[j]=b[j];
				}
			}
		}	
		for(i=1;i<=50;++i)
		{
			sum+=a[i];
		}
		printf("%d\n",sum);
	}
	return 0;
}