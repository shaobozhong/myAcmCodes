#include<iostream>
using namespace std;


int main()
{
	int b;
	char a[15],c[35];
	int num,i,j;
	int count1,count2;
	while(scanf("%d",&b)!=EOF)
	{
		puts("1 1");
		for(i=2;i<=300;++i)
		{

			num=i*i;
			count1=0;


			while(num)
			{
				c[count1++]=(num%b)+'0';
				if (c[count1-1]>'9') c[count1-1]=(c[count1-1]+7);
				num/=b;
			}

			for(j=0;j<=count1/2-1;++j)
			{
				if (c[j]!=c[count1-j-1]) break;
			}
			if (j>count1/2-1)  
			{
				num=i;
				count2=0;
				while(num)
				{
					a[count2++]=num%b+'0';
					if (a[count2-1]>'9') a[count2-1]=(a[count2-1]+7);
					num/=b;
				}

				for(j=count2-1;j>=0;--j)
				{
					putchar(a[j]);
				}


				putchar(' ');
				for(j=count1-1;j>=0;--j)
				{
					putchar(c[j]);
				}
				putchar('\n');
			}
		}
	}
	return 0;
}

