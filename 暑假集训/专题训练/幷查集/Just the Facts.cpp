#include<iostream>
using namespace std;

int main()
{
    int n,sum,t,i,temp;
	while(cin>>n)
	{
		sum=1;
		for(i=n;i>=1;i--)
		{
			temp=i;
			while(1)
			{
			   t=temp%10;
			   if (t!=0) break;
			   temp/=10;
			}
            temp%=10000;

			sum*=temp;
			while(1)
			{
			   t=sum%10;
			   if (t!=0) break;
			   sum/=10;
			}
            sum%=10000;
		}
        while(1)
		{
			t=sum%10;
			if (t!=0) {printf("%5d -> %d\n",n,t);break;}
		}
	}
	return 0;
}