//注意这个题目 砝码是可以想减的
#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	int n,sum;
	int alen,blen;
	int num[105];
	int a[20005],b[20005];
	int i,j;
	int res[10005],count1;
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;
		for(i=0;i<n;++i)
		{
			scanf("%d",&num[i]);
			sum+=num[i];
		}
		sort(num,num+n,cmp);
		for(i=0;i<=sum+10002;++i)
		{
			a[i]=0;
			b[i]=0;
		}
		a[10002]=1;
		a[num[0]+10002]=1;
		a[10002-num[0]]=1;
		alen=num[0];
		for(i=1;i<n;++i)
		{
			for(j=10002-alen;j<=10002+alen;++j)
			{
				b[j]+=a[j];
				b[j+num[i]]+=a[j];
				b[j-num[i]]+=a[j];
			}
			blen=num[i];
			alen=alen+blen;
			for(j=10002-alen;j<=10002+alen;++j)
			{
				a[j]=b[j];
				b[j]=0;
			}
		}

        count1=0;
		for(i=1;i<=sum;++i)
		{
			if (a[i+10002]==0) res[count1++]=i;
		}
		if (!count1) puts("0");
		else 
		{
			printf("%d\n",count1);
			printf("%d",res[0]);
			for(i=1;i<count1;++i)
			{
				printf(" %d",res[i]);
			}
			putchar('\n');
		}
	}
	return 0;
}