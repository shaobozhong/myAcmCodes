#include<stdio.h>
#include<math.h>

bool a[17000001];


void  shai()
{ 
	int i,j;
for(i=2;i<=17000000;i++)
{
	a[i]=1;
}
 a[1]=0;
for(i=2;i<=sqrt(17000000);i++)
{
	if (a[i]!=0)
	{
		
	for(j=i*i;j<=17000000;j=j+i)
		 a[j]=0;
	}
}

}

int main()
{
	int s,i; 
	int n;
	shai();
	while(scanf("%d",&n)!=EOF)
	{s=0;
		for(i=2;i<=n/2;i++)
	{
		if (a[i]&&a[n-i])  s++;	
	}
    printf("%d\n",s);
	}
	return 0;
}