 
#include"stdio.h"
int main()
{
	int a[65535],i,n,m,s=0,k=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<=n;i++)
		a[i]=i;
	for(i=1;;i++)
	{
		if(i>n) 
		{
			i=1;
			k=0;
		}
		if(a[i]>0) 
			s++;
		if(a[i]==-1) 
			k++;
		if(s%m==0) 
			a[i]=-1;
		if(k==n-1) 
			break;
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]!=-1) printf("%d\n",a[i]);
	}
	return 0;} 
