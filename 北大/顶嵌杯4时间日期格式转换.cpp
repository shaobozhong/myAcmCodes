#include<stdio.h>
#include<string.h>


int main()
{

	int t,i,j,d,count,a[6];
	char str[30];
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		gets(str);
		count=5;
		for(i=strlen(str)-1;i>=0;i--)
		{
			d=1;
			a[count]=0;
			for(j=i;j>=0&&(str[j]>='0'&&str[j]<='9');j--)
			{
				a[count]+=d*(str[j]-48);
				d*=10;
			}
			i=j;
			count--;
		}
		if(a[1]>=10) printf("%d/",a[1]);
		else printf("0%d/",a[1]);
		if(a[2]>=10) printf("%d/",a[2]);
		else printf("0%d/",a[2]);
		printf("%d-",a[0]);
		if (a[3]==0) printf("12:");
		else 
		{
			if (a[3]>12)
			{
			if(a[3]%12>=10) printf("%d:",a[3]%12);
			else printf("0%d:",a[3]%12);
			}
			else 
			{
               if(a[3]>=10) printf("%d:",a[3]);
			else printf("0%d:",a[3]);
			}
		}
		if(a[4]>=10) printf("%d:",a[4]);
		else printf("0%d:",a[4]);
		if(a[5]>=10) printf("%d",a[5]);
		else printf("0%d",a[5]);
		if (a[3]<12||(a[3]==12&&a[4]==0&&a[5]==0)) puts("am");
		else puts("pm");
	}
	return 0;
}