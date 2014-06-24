#include<stdio.h>
int length;
void shulian(__int64 n,int temp)
{ if (n==1) {if (length<temp) length=temp; return;}

if (n%2!=0) shulian(3*n+1,temp+1); else shulian(n/2,temp+1);
}

int main()
{
	__int64 i,j,k;
	while(scanf("%I64d%I64d",&i,&j)+1)
	{length=1;
	for(k=i;k<=j;k++)
		shulian(k,1);
    for(k=i;k>=j;k--)
		shulian(k,1);  
	printf("%I64d %I64d %d\n",i,j,length);
	}
	return 0;
}
