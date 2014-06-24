#include<stdio.h>
#include<string.h>
int main()
{
	double b[70]={0},s;
	int n,i,t,k,j;
	char a[130];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{s=0;k=0;t=1;
	
	scanf("%s",a);
		for(j=(int)strlen(a)-2;j>=0;j--)
		{
			if (a[j]>='0'&&a[j]<='9')
			{
				b[k]+=((int)a[j]-48)*t;
			if (j>0)
			{if (a[j-1]>='0'&&a[j-1]<='9')
				t*=10;
			else 
			{
				k++;
				t=1;
			}
			}
			}
		}
		for(j=0;j<=k;j++)
			s+=b[j];
	printf("%.0f\n",s);
	for(j=0;j<=69;j++)
		b[j]=0;
	}
	return 0;
}