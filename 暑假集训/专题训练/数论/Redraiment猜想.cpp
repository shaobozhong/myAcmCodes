
#include<stdio.h>
#include<math.h>
#define M 10000000

bool a[M+1]={0};


void  shai()
{ 
	int i,j;
	for(i=2;i<=M;i++)
	{
		a[i]=1;
	}
	a[1]=0;
	for(i=2;i<=(int)sqrt((double)M);i++)
	{
		if (a[i]!=0)
		{
			for(j=i*i;j<=M;j=j+i)	 
			{
				a[j]=0;
			}
		}
	}

}

int main()
{
	int n,count,i;
	shai();
	while(scanf("%d",&n),n!=0)
	{
		count=0;
		for(i=2;i<=n;i++)
			if (a[i]) count++;
		printf("%d\n",count);
	}
	
	return 0;
}