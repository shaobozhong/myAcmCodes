#include<stdio.h>
int main()
{
	int n,i,total=0,t,m,s;
     scanf("%d",&m);
	for(i=377;i<=m;i++)
	{   s=0;
	    n=i;
		if (n%13==0)
		{
			while(n!=0)
			{
              t=n%10;
			  if (t==7) s++;
			  if (s==2) break;
			  n/=10;
			}
			if (s==2) total++;
		}
		
	}
	printf("%d\n",total);
	return 0;
}