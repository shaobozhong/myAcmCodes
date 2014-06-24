#include<stdio.h>
int main()
{
	int m,i,j,s,k;
	scanf("%d",&m);
	for(i=1;i<=m-1;i++)
	{
		//if (j<1000) k=1;
		//else k=i-m/i;
		s=0;
		for(j=i;j>=k ;j--)
		{
			s+=j;
			if (s==m) 
			{
				printf("%d %d\n",j,i);
				break;
			}
			if (s>m) break;
		}
	}
	return 0;
}