#include<stdio.h>

int main()
{

int  i,j,n,a,s,c[1003]={0},t;
    while(scanf("%d",&n)+1)
    {
		
	t=1;
	i=0;
	s=1;
	while(s<1000)
	{ i++;
	  s=s*n;	
	}
    a=i;
	c[0]=s%1000;
	s%=1000;
	n%=1000;
	for(i=1;t;i++)
	{    
		s*=n;s%=1000;
	    c[i]=s;
		for(j=0;j<=i-1;j++)
			if (s==c[j]) 
			{
				t=0;
				printf("%d\n",j+2*a+i);
				break;
			}
	}
	}
	return 0;
}