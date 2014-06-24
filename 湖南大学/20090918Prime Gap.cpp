#include<iostream>
#include<cmath>
using namespace std;


bool a[1299710]={0};


void  shai()
{ 
	int i,j;
for(i=2;i<=1299710;i++)
{
	a[i]=1;
}
 a[1]=0;
for(i=2;i<=(int)sqrt((double)1299710);i++)
{
	if (a[i]!=0)
	{
		
	for(j=i*i;j<=1299710;j=j+i)
		 a[j]=0;
	}
}

}

int main()
{
	int n,i,j;
	shai();
	while(scanf("%d",&n)>0&&n!=0)
	{
		if (a[n]||n==1){ printf("0\n");continue;}
	    for(i=n;i<=1299709;i++)
		{
			if (a[i]) break;
		}
		for(j=n-1;j>1;j--)
		{
			if (a[j]) break;
		}
		printf("%d\n",i-j);
	}
	return 0;
}