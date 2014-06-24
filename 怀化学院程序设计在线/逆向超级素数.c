#include<stdio.h>
#include<math.h>

int prime(int n)
{
	int i;
	if (n<=1) return 0;
	for(i=2;i<=sqrt(n);i++)
		if (n%i==0) break;
	if (i>sqrt(n)) return 1;
	else return 0;
}

int main()
{
	int x,y,i,s,s1,t,total=0;
	float temp;
	scanf("%d%d",&x,&y);
	for(i=x;i<=y;i++)
		if (prime(i))
		{t=1;
	s=i;
	while(s!=0)
	{if (!prime(s)) {t=0;break;}
	s1=s;
    temp=1.0/10;
	while(s1!=0)
	{
		if (s1%10==0) t=0;
		temp*=10;
		s1/=10;
	}
	s=s-(s/(int)temp)*temp;

	}
	if (t==1) total++;
	}
	printf("%d\n",total);
	return 0;
}