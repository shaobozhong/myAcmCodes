#include<iostream>
using namespace std;

int la;
int a[31];

void rtransform(int num)//进制转换
{
	la=0;
	while(num)
	{
		a[la++]=num%3;
		num/=3;
	}
}


int main()
{
	int num,tnum;
	int i,j;
	while(scanf("%d",&num)!=EOF)
	{
		memset(a,0,sizeof(a));
		tnum=abs(num);
		rtransform(tnum);
		if (num==0) 
		{
			puts("0");
			continue;
		}


        if (num<0) //小于零要先转换成负数
		{
			a[la]=-1;
			for(i=1;i<la;++i)
			{
				a[i]=2-a[i];
			}
			a[0]=3-a[0];
			/*for(i=0;i<=la;++i)
			{
				if (a[i]>0)
				{
					for(j=i;a[j]!=0;++j){}
					--a[j];
                    for(j--;j>i;--j)
					    a[j]=2-a[j];
					a[i]=3-a[i];
					break;
				}
			}*/
		}

		for(i=0;i<=la+1;++i)//要变成没有2  的形式
		{
			if (a[i]>=3)
			{
				a[i+1]+=a[i]/3;
				a[i]=a[i]%3;
			}
			if (a[i]==2) 
			{
				a[i]=-1;
				++a[i+1];
			}
		}

		

		for(i=la+2;i>=0;--i)
		{
			if (a[i]!=0) break;
		}
		for(;i>=0;--i)
		{
			if (a[i]==-1) {putchar('-');continue;}
			printf("%d",a[i]);
		}
		putchar('\n');
	}
	return 0;
}