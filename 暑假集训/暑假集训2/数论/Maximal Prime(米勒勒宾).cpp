#include<iostream>
#include<time.h>
#include <cmath>
#include <algorithm>
#include <stdlib.h>
using namespace std;


long long mul_mod(long long x,long long y,long long n)

{

     long long T=long long(floor(sqrt((double)n)+0.5));

     long long t=T*T-n;

     long long a=x/T; long long b=x%T;

     long long c=y/T; long long d=y%T;

     long long e=a*c/T; long long f=a*c%T;

     long long v=((a*d+b*c)%n+e*t)%n;

     long long g=v/T; long long h=v%T;

     long long ans=(((f+g)*t%n+b*d)%n+h*T)%n;

     while(ans<0) ans+=n;

     return ans;

}

 

long long modExp(long long a,long long n,long long p)
{
  long long  ans=1,d=a%p;

     do
	 {
         if(n&1)ans=mul_mod(ans,d,p);

         d=mul_mod(d,d,p);

     }while(n>>=1);

     return ans;

}

bool passmillertabinTest(long long n)
{
	int l,m,b,i,k;
	if (n==1) return false;
	m=n-1;
	l=0;
	while(m % 2==0)
	{
		l++;
		m/=2;
	}
		srand(time(NULL));
		b=rand()%(n-1)+1;
		if (modExp(b,m,n)==1) return true;
		k=m;
		for(i=0;i<=l-1;++i)
		{
			if (modExp(b,k,n)==n-1) return true;
			k*=2;
		}
		return false;
	}

int main()
{
	int i;
	int a[100],count,weight;//存储各位数字的数组和位数
    long long num,temp,max;
	while(cin>>num)
	{
		if (passmillertabinTest(num)) {printf("%lld\n",num);continue;}
		max=0;
		temp=num;
		count=0;
		a[0]=0;
		weight=1;
		while(temp)
		{
			weight*=10;
			a[count++]=int(temp%10);
			temp/=10;
		}
        a[count]=0;
		for(i=0;i<=count;++i)
		{
			num-=a[count-i]*weight;
			temp=num;
			while(temp)
			{
				if (passmillertabinTest(temp) && temp>max) {max=temp;break;} 
				temp/=10;
			}
			weight/=10;
		}

		if (max!=0)printf("%lld\n",max);
		else puts("No Primes");
	}
	return 0;
}