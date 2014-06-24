#include<stdio.h>
#include<string.h>
void work()
{char a[10]={0};
int b[10];
int s,shi,ge,i;
s=0;
scanf("%s",a);
for(i=0;i<=(int)strlen(a)-1;i++)
			b[i]=(int)a[i]-48;
		for(i=0;i<=(int)strlen(a)-1;i++)
			s=s+b[i];
		while(s>=10)
		{shi=s/10;
		ge=s%10;
        s=shi+ge;
		}
printf("%d\n",s);
}


int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		work();
	}
return 0;
}