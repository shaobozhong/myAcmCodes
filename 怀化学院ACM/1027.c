#include<stdio.h>
int main()
{ 
	
	int n,s,a,b,c,d;
	
	while(scanf("%d",&n)+1)
	{
		if(n<6) break;
		for(a=6;a<=n;a++)
		{
			s=a*a*a;
			for(b=2;b<a;b++)
				for(c=b+1;c<a;c++)
					for(d=c+1;d<a;d++)
					{
						if (s==b*b*b+c*c*c+d*d*d)
						{printf("Cube = %d, ",a);
						printf("Triple = (%d,%d,%d)\n",b,c,d);
						}
					}
					
					
		}
		
	}
	
	return 0;
}
