#include<iostream>
using namespace std;

	int a[250001],b[121];
	int res[250001];

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
	int n;

	int num,value;
	int sum,min1;
	int i,j;
	int alen,blen;
	while(scanf("%d",&n),n>=0)
	{
		if (n==0) {puts("0 0");continue;}
		min1=INT_MAX;
		sum=0;
		memset(a,0,sizeof(a));
		if (n!=0)
		{
			scanf("%d%d",&value,&num);
			//µÚÒ»´Î
			for(i=0;i<=num*value;i+=value)
			{
				a[i]=1;
			}
			alen=num*value;
			sum+=alen;
		}

		for(i=1;i<n;++i)
		{
			scanf("%d%d",&value,&num);
			memset(b,0,sizeof(b));
			for(j=0;j<=value*num;j+=value)
			{
				b[j]=1;
			}
			blen=value*num;
			sum+=blen;
			mutiply(alen,blen,a,b,res);
			alen=alen+blen;
			for(j=0;j<=alen;++j)
			{
				a[j]=res[j];
			}
		}
        if (sum%2==0) i=sum/2;
		else i=sum/2+1;
		for(;i<=sum;++i)
		{
			if (a[i]!=0) break;
		}
		printf("%d %d\n",i,sum-i);
	}
	return 0;
}