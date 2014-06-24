#include<iostream>
using namespace std;
int main()
{
	__int64 a[26],b[26],c[26],m;
	__int64 i,j,n,k;
	b[1]=1;
	c[1]=1;
	c[2]=2;
	b[2]=3;
	a[1]=1;
	a[2]=2;
	for(i=3;i<=25;i++)
	{
		m=i;
		for(j=i-1;j>1;j--)
		{
			m+=(c[j]*(c[j]-1))/2;		
			m+=c[j];
			k=(c[j]*(c[j]-1))/2;
			c[j]=c[j]+k;
		}
		c[i]=i;
		b[i]=m;
	}
	for(i=3;i<=25;i++)
		a[i]=c[i-1]+1;
	while(scanf("%I64d",&n))
	printf("%I64d\n",c[n]);
	return 0;
}