/*#include<iostream>
using namespace std;
const long N=10000000;
__int64 n,num,a[N];
__int64 prime(__int64 a[],int n)
{
    int i,j,k,x,num,*b;
    n++;
    n/=2;
    b=(int *)malloc(sizeof(int)*(n+1)*2);
    a[0]=2;a[1]=3;num=2;
    for(i=1;i<=2*n;i++)
        b[i]=0;
    for(i=3;i<=n;i+=3)
        for(j=0;j<2;j++)
            {
            x=2*(i+j)-1;
            while(b[x]==0)
                {
                a[num++]=x;
                for(k=x;k<=2*n;k+=x)
                    b[k]=1;
                }
            }
    return num;
}
int BitLength(int x)
{
    int a,b=0;
	while(x)
	{
	 a=x%10;
	 x=x/10;
	 b++;
	}
   return b;
}

int main()
{
	//int m;
 while(scanf("%I64d",&n),n!=0)
 {
	 if(n==1) num=0;
	 else if(n==2) num=1;
	 else   if(n<=10000000)
      num=prime(a,n);
	 else
		 num=5761455;
  printf("%I64d\n",num);
 }
 return 0;
}
//³¬Ê±£¿*/

/*#include<iostream>
#include<math.h>
using namespace std;
int prime(long n)
{
   int i,flag=1;
    for (i=2;i<=sqrt(n);i++)
    if (n%i==0)
	{  flag=0;  break; }
    if (flag==1) return 1; 
	else return 0;

}
int main()
{
 __int64 n,i,s,num;
 while(scanf("%I64d",&n),n!=0)
 {
	 num=0;
  for(i=2;i<=n;i++)
  {
	  s=prime(i);
	  if(s)  num++;
  }
  printf("%I64d\n",num);
 }
 return 0;
}//³¬Ê±£¿*/

/*#include <iostream>
#include<math.h>
using namespace std;
#define max 100000002 
bool a[max];  
int main()
{
    __int64 n,i,s,j,t;
        memset(a,1,sizeof(a)); 
        t=sqrt(max);
    for(i=2;i<=(__int64)t;i++)     
        if(a[i])
        {
            for(j=i;j*i<=max;j++) 
                a[i*j]=0;
        }
    while(scanf("%I64d",&n)&&n!=0)
    {
        s=0;
        for(i=2;i<=n;i++) 
			if(a[i]) 
				s++;
        printf("%I64d\n",s);
    }
    return 0;
}//??³¬Ê±*/


#include <iostream>
#include <cmath>
using namespace std;
int f(unsigned long int n)
{
	unsigned long int i;
    for(i=2;i<=sqrt((double)n);i++)
		if(n%i==0) return 0;
	return 1;
}

void work(unsigned long int n)
{
	unsigned long int i, k=0;
	if(n<=pow((double)10,(double)3))
	{
		for(i=n+1;i<pow((double)10,(double)3);i++)
			if(f(i))  k++;
		cout<<168-k<<endl;
	}
	else if(n<=pow((double)10,(double)4))
	{
		for(i=n+1;i<pow((double)10,(double)4);i++)
			if(f(i)) k++;
		cout<<1229-k<<endl;
	}
	else if(n<=5*pow((double)10,(double)4))
	{
		for(i=n+1;i<5*pow((double)10,(double)4);i++)
			if(f(i))k++;
		cout<<5133-k<<endl;
	}
	else if(n<=pow((double)10,(double)5))
	{
		for(i=n+1;i<pow((double)10,(double)5);i++)
			if(f(i))k++;
		cout<<9592-k<<endl;
	}
	else if(n<=5*pow((double)10,(double)5))
	{
		for(i=n+1;i<5*pow((double)10,(double)5);i++)
			if(f(i))k++;
		cout<<41538-k<<endl;
	}
	else if(n<=pow((double)10,(double)6))
	{
		for(i=n+1;i<pow((double)10,(double)6);i++)
			if(f(i))k++;
		cout<<78498-k<<endl;
	}
	else if(n<=2*pow((double)10,(double)6))
	{
		for(i=n+1;i<2*pow((double)10,(double)6);i++)
			if(f(i))k++;
		cout<<148933-k<<endl;
	}
	else if(n<=5*pow((double)10,(double)6))
	{
		for(i=n+1;i<5*pow((double)10,(double)6);i++)
			if(f(i))k++;
		cout<<348513-k<<endl;
	}
	else if(n<=pow((double)10,(double)7))
	{
		for(i=n+1;i<pow((double)10,(double)7);i++)
			if(f(i))k++;
		cout<<664579-k<<endl;
	}
	else if(n<=pow((double)10,(double)8))
	{
		for(i=n+1;i<pow((double)10,(double)8);i++)
			if(f(i))k++;
		cout<<5761455-k<<endl;
	}
}
int main()
{
	unsigned long int n,i,k=0;
	while(cin>>n,n!=0)
	{
		k=0;
		if(n<100)
		{
			for(i=2;i<=n;i++)
				if(f(i)) k++;
		cout<<k<<endl;
		}
		else 
		work(n);
	}
	return 0;
}




