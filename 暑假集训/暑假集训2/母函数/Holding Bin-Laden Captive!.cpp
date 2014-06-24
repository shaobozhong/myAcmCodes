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
	int a[8100],b[6000];
	int res[8100];
	int num[3];
	int min1,max1;
	int i,j;
	int alen,blen;
	while(scanf("%d%d%d",&num[0],&num[1],&num[2]),num[0]!=0||num[1]!=0||num[2]!=0)
	{
		if (num[0]==0) {puts("1");continue;}
		max1=num[0]*1+num[1]*2+num[2]*5;
		min1=2;
		//第一次
		memset(a,0,sizeof(a));
		for(i=0;i<=num[0];++i)
		{
			a[i]=1;
		}
		alen=num[0];

       //第二次
		memset(b,0,sizeof(b));
		for(j=0;j<=2*num[1];j+=2)
		{
			b[j]=1;
		}
		blen=2*num[1];
		mutiply(alen,blen,a,b,res);
		alen=alen+blen;
		for(j=0;j<=alen;++j)
		{
			a[j]=res[j];
		}

        //第三次
		memset(b,0,sizeof(b));
		for(j=0;j<=5*num[2];j+=5)
		{
			b[j]=1;
		}
		blen=5*num[2];
		mutiply(alen,blen,a,b,res);
		alen=alen+blen;
		for(j=0;j<=alen;++j) 
		{
			a[j]=res[j];
		}

		bool flag=false;
		for(i=min1;i<=max1+1;++i)
		{
			if (!a[i]) {printf("%d\n",i);break;}
		}
        
	}
	return 0;
}