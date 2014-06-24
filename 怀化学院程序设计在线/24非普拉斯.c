#include<stdio.h>
void main()
{
	int a[30],i,j=0;
	a[0]=1;
	a[1]=1;
	for(i=2;i<=29;i++)
		a[i]=a[i-1]+a[i-2];
	while(scanf("%d",&i)>0&&i!=0)
	{
      printf("%d ",a[i-1]);
	  j++;
	  if (j%5==0) printf("\n");
	}
	if (j%5!=0) printf("\n");
}