#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	char p[1000];
	int n,i,k,fh;
	double a,b,c;
	scanf("%d",&n);
    for(k=1;k<=n;k++)
	{
		a=0;b=0;
		scanf("%s",p);
		for(i=0;i<=(int)strlen(p)-1;i++)
		{	if (p[i]!='0'&&p[i]!='1')
		{
			fh=i;
			break;
		}
		} 
		c=1;
		for(i=fh-1;i>=0;i--)
		{   
		a+=c*((int)p[i]-48);
		c*=2;
		}
		c=1;
		for(i=(int)strlen(p)-1;i>=fh+1;i--)
		{
			b+=c*((int)p[i]-48);
			c*=2;
		}
		switch(*(p+fh))
		{
		case 'A':printf("%.0f\n",a+b);break;
		case 'B':printf("%.0f\n",a-b);break;
		case 'C' :printf("%.0f\n",a*b);break;
		case 'D':printf("%.2f\n",a/b);break;
		case 'E':printf("%.0f\n",pow(a,b));
			
		}
	}
	return 0;
}