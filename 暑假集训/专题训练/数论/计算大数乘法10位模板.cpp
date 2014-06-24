#include<stdio.h>
#include<stdlib.h>
#define I 10000000000
#define maxsize 800//366! 位数：781

__int64 a[maxsize];

void fac(int n,__int64 *a)
{
	int i,j;
	__int64 k;
	if(n==0||n==1)
	{
		a[0]=1;a[1]=1;
		return;
	}
	a[0]=a[1]=1;
	k=1;
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=k;j++) 
			if(a[j])
				a[j]*=i;
		for(j=1;j<=k;j++)
			if(a[j]>=I) 
			{
				if(j==k)
					k++;
				a[j+1]+=(a[j]/I);
				a[j]%=I;
			}
	}
	a[0]=k;//个数
}
int main()
{
	int n,ans[10],k,t=1;
	__int64 i;
	while(scanf("%d",&n)!=EOF && n)
	{
		memset(a,0,sizeof(a));
		memset(ans,0,sizeof(ans));
		fac(n,a);
		while(a[a[0]])
		{
			k=a[a[0]]%10;
			ans[k]++;
			a[a[0]]/=10;
		}
		for(i=a[0]-1;i>=1;i--)
		{
			//若a[i]不足9位数，前面补零。
			if(a[i]==0) ans[0]+=10;
			else if(a[i]<10) ans[0]+=9;
			else if(a[i]<100) ans[0]+=8;
			else if(a[i]<1000) ans[0]+=7;
			else if(a[i]<10000) ans[0]+=6;
			else if(a[i]<100000) ans[0]+=5;
			else if(a[i]<1000000) ans[0]+=4;
			else if(a[i]<10000000) ans[0]+=3;
			else if(a[i]<100000000) ans[0]+=2;
			else if(a[i]<1000000000) ans[0]+=1;
			while(a[i])
			{
				k=a[i]%10;
				ans[k]++;
				a[i]/=10;
			}
		}
		printf("%d! --\n",n);
		printf("   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n",
			ans[0],ans[1],ans[2],ans[3],ans[4]);
		printf("   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d\n",
			ans[5],ans[6],ans[7],ans[8],ans[9]);
	}
	return 0;
}

