#include<stdio.h>
#include<math.h>
int er(int s )
{
	int a=0,i=0;
	while(s!=0)
	{
		a+=(int)pow(2,i)*(s%10);
		s/=10;
		i++;
	}
	return(a);
}



int main()
{
	char b;
	int i,n,a,c;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%c%d",&a,&b,&c);
		a=er(a);
		c=er(c);
		switch(b)
		{
		case 'A':printf("%d\n",a+c);break;
		case 'B':printf("%d\n",a-c);break;
		case 'C' :printf("%d\n",a*c);break;
		case 'D':printf("%.2f\n",(float)a/c);break;
		case 'E':printf("%d\n",(int)pow(a,c));
			
		}
		
	}
	return 0;
}