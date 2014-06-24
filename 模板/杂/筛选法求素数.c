#include<stdio.h>
#include<math.h>
int main()
{ int i,j,n=100;
int a[102]={0};
a[1]=1;
for(i=2;i<=sqrt(n);i++)
{
	if (a[i]!=1)
	{
		j=i*i;
	for(;j<=n;j++)
		if (j%i==0) a[j]=1;
	}
}
for(i=2;i<=n;i++) 
if (a[i]==0) printf("%d ",i);
printf("\n");
return 0;
}