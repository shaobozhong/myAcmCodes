#include<iostream>
using namespace std;
    int a[95000];
	int b[95000];
int main()
{
	int n;
	int i,j,k;
	int tmp,alen,blen;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(i=0;i<=300;++i)
	{
		a[i]=1;
	}
    alen=300;
	for(i=2;i*i<=300;++i)
	{
		tmp=i*i;

		for(j=0;j<=300;j+=tmp)
		{
			for(k=0;k<=alen;k++)
			{
				b[j+k]+=a[k];
			}
		}
		blen=j-tmp;
        alen=alen+blen;
		for(j=0;j<=alen;++j)
		{
			a[j]=b[j];
			b[j]=0;
		}
	}


	while(scanf("%d",&n),n!=0)
	{
		printf("%d\n",a[n]);
	}
	return 0;
}