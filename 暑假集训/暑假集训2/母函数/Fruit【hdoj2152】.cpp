#include<iostream>
using namespace std;

struct node
{
	int s,e;
};


int main()
{
	int a[10050],b[10050];
	node num[105];
	int n,m;
	int alen,blen,i,j,k;
	while(scanf("%d%d",&n,&m)!=EOF)
	{

		for(i=0;i<n;++i)
		{
			scanf("%d%d",&num[i].s,&num[i].e);
		}
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));

		for(i=num[0].s;i<=num[0].e;++i)
		{
			a[i]=1;
		}
		alen=num[0].e;
		for(i=1;i<n;++i)
		{
			for(j=0;j<=alen;++j)
			{
				for(k=num[i].s;k<=num[i].e;++k)
				{
					b[j+k]+=a[j];
				}
			}
			blen=num[i].e;
			alen=alen+blen;
			for(j=0;j<=alen;++j)
			{
				a[j]=b[j];
				b[j]=0;
			}
		}


		printf("%d\n",a[m]);
	}
	return 0;
}