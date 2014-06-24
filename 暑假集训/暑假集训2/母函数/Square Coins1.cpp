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

		for(j=0;j<=alen;++j)//此处alen在外 blen在外时一样的 因为不怕b改变 当然若是a  b一遍遍的乘 貌似要合理一些 其实是一样的
		{
			for(k=0;k<=300;k+=tmp)
			{
				b[j+k]+=a[j];
			}
		}
		blen=k-tmp;
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