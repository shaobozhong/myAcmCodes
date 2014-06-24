#include<iostream>
#include<math.h>
using namespace std;
int r[1000005];
int pre=0;
bool a[3000008]={0};


void  shai()
{ 
	int i,j;
for(i=2;i<=3000008;i++)
{
	a[i]=1;
}
 a[1]=0;
for(i=2;i<=(int)sqrt((double)3000008);i++)
{
	if (a[i]!=0)
	{
		
	for(j=i*i;j<=3000008;j=j+i)
		 a[j]=0;
	}
}

}

void work(int n)
{
	int i;
	for(i=pre+1;i<=n;i++)
	{
		if (a[3*i+7]) r[i]=1;
		else 
		{
			r[i]=0;
		}
		r[i]+=r[i-1];
	}
	pre=n;
}
int main()
{
	int t;
	int n;
	shai();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
	    if (n>pre) work(n);
		printf("%d\n",r[n]);
	}
	return 0;
}