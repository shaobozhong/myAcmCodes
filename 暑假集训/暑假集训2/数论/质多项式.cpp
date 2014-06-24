//首先易得 k位和0位必须是1   具体见代码
#include<iostream>
using namespace std;
int bin[32];

void init()
{
	int i;
	bin[0]=1;
	for(i=1;i<=30;++i)
	{
		bin[i]=bin[i-1]*2;
	}
}


int calclength(int a)
{
	int i;
        for(i=30;i>=0;--i)
		{
			if (bin[i]<=a) return i;
		}
		return 0;
}

bool divide(int a,int b)
{
	int alen,blen;
	alen=calclength(a);
	blen=calclength(b);
	b=b<<(alen-blen);
	while(a!=b&&alen>=blen)
	{
		a=a^b;//异或运算
		while(bin[alen]>a)//首位不为零
		{
			--alen;
			b=b>>1;
		}
	}
	if (alen>=blen) return true;
	return false;
}


void output(int now,int k)
{
	int i;
	if (k==1) {puts("x");return;}
	for(i=30;i>=1;--i)
	{
		if (bin[i]<=now) 
		{
			now-=bin[i];
			 printf("x^%d+",i);
		}
	}
	printf("%d\n",1);
}

int main()
{
	int k;
	int i,now;
	bool la;
	init();
	while(scanf("%d",&k),k!=0)
	{

		la=false;
		now=bin[k]-1;

		while(!la)
		{

			la=true;
			now+=2;
			
			for(i=2;i<=bin[(k+1)/2+1]-1;++i)
			{
				if (divide(now,i)) 
				{
					la=false;
					break;
				}
			}
		}
        output(now,k);
	}
	return 0;
}