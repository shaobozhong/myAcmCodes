#include<stdio.h>
#include<string.h>
void main()
{
	int i,n;
	float a,c;
	char b;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%f",&a);
		scanf("%c",&b);
		scanf("%f",&c);
        switch(b)
		{
		case '+':printf("%.2f\n",a+c);break;
		case '-':printf("%.2f\n",a-c);break;
		case '*':printf("%.2f\n",a*c);break;
		case '/':printf("%.2f\n",a/c);break;
	default:printf("%d\n",(int)a%(int)c);
		}
	}
}