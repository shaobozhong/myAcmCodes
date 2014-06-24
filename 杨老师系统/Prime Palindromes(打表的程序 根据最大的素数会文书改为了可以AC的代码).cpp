#include<iostream>
#include<cmath>
using namespace std;

bool vis[10000005];
int res[100000];

void shai()
{
	int i,j;
	memset(vis,true,sizeof(vis));
	vis[0]=false;
	vis[1]=false;
	for(i=2;i<=sqrt(10000000.0);++i)
	{
		if (vis[i])
		{
			for(j=i*i;j<=10000000;j+=i)
			{
				vis[j]=false;
			}
		}
	}
}

int main()
{
	int i,j,num1,num2;
	int num;
	int count1,count2;
	char a[20];
	shai();
	count2=0;
	for(i=2;i<=9989899;++i)
	{
		if (vis[i])
		{
			count1=0;
			num=i;
			while(num)
			{
				a[count1++]=(num%10)+'0';
				num/=10;
			}

			for(j=0;j<=count1/2-1;++j)
			{
				if (a[j]!=a[count1-1-j]) break;
			}
			if (j>count1/2-1) res[count2++]=i;
		}
	}

	/*printf("%d\n",count2);
	for(i=0;i<count2;++i)
	{
		printf("%d,",res[i]);
	}*/

	while(scanf("%d%d",&num1,&num2)!=EOF)
	{
		for(i=0;i<count2;++i)
		{
			if (res[i]>num2) break;
			if (res[i]>=num1) printf("%d\n",res[i]);
		}
	}
	return 0;
}