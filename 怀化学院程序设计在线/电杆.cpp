#include <iostream>
using namespace std;

int main()
{
	int a1,a2,a3,n,c,sum,i,f;
   
	while(scanf("%d%d",&n,&c)!=EOF)
	{
		a1=0;a2=0;a3=0;sum=0;
		cin>>a1>>a2;
		if (a1<a2)  
		{
			
				f=(a2-a1-c/2)*c+c*c/4;
				if (f>(a2-a1-c/2-1)*c+c*c/4+c+1) f=(a2-a1-c/2-1)*c+c*c/4+c+1;
				if (f>(a2-a1)*(a2-a1)) f=(a2-a1)*(a2-a1);
				sum+=f;
				a1=a2;                 
				a2=0;
			
		}
		i=2;
		while(i<n)
		{
			if (a2==0) {scanf("%d",&a2);i++;if (i==n) break;}
			if (a3==0) {scanf("%d",&a3);i++;}
			if (a2<a1&&a2<a3) 
			{
				f=c;
				if (f>a1-a2) f=a1-a2;
				if (f>a3-a2) f=a3-a2;
				sum+=(a1+a3-(a2+f)*2)*c+f*f;
				a1=a3; a2=0;a3=0;
			}
			else if (a2>a3) 
			{
				sum+=a2>a1?(a2-a1)*c:(a1-a2)*c;
				a1=a2;a2=a3;a3=0;
			}
			else 
			{
				sum+=a2>a1?(a2-a1)*c:(a1-a2)*c;
				sum+=a3>a2?(a3-a2)*c:(a2-a3)*c;
				a1=a3;
				a2=0;
				a3=0;
			}

		}
		if (a2!=0)   
		{
			f=(a1-a2-c/2)*c+c*c/4;
			if (f>(a1-a2-c/2-1)*c+c*c/4+c+1) f=(a1-a2-c/2-1)*c+c*c/4+c+1;
			if (f>(a1-a2)*(a1-a2)) f=(a1-a2)*(a1-a2);
			sum+=f;
		}

		printf("%d\n",sum);
	}
	return 0;
}