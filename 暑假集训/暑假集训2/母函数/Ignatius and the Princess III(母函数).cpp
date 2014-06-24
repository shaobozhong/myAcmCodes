#include<iostream>
using namespace std;

void mutiply(int alen,int blen,int *a,int *b,int *res)
{
	int i,j;
	for(i=0;i<=alen+blen;++i)
	{
		res[i]=0;
	}

	for(i=0;i<=blen;++i)
	{
		if (b[i]==0) continue;
		for(j=0;j<=alen;++j)
		{
			res[i+j]+=a[j]*b[i];
		}
	}
}

int main()
{
	int a[15000],b[121];
	int res[15000];
	int i,j;
	int alen,blen;
	int n;

	memset(a,0,sizeof(a));
	for(i=0;i<=120;++i)
	{
		a[i]=1;
	}
	alen=120;
	for(i=2;i<=120;++i)
	{
		memset(b,0,sizeof(b));
		for(j=0;j<=120;j+=i)
		{
			b[j]=1;
		}
		blen=j-i;
		mutiply(alen,blen,a,b,res);
		alen=alen+blen;
		for(j=0;j<=alen;++j)
		{
			a[j]=res[j];
		}
	}
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",a[n]);
	}
	return 0;
}