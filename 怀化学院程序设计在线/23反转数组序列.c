#include<stdio.h>
void main()
{
	int i,a[20],t;
	for(i=0;i<=19;i++)
		scanf("%d",&a[i]);
	for(i=0;i<=8;i++)
	{
		t=a[i];
		a[i]=a[19-i];
		a[19-i]=t;
	}
	while(scanf("%d",&t)>0&&t!=0)
		printf("%d ",a[t-1]);
	printf("\n");
}