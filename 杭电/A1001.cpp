#include<iostream>
using namespace std;

int main()
{
	double sum,t[4],temp,n;
    int i;
	while(scanf("%lf%lf%lf%lf",&n,&t[1],&t[2],&t[3]),n!=0||t[1]!=0||t[2]!=0||t[3]!=0)
	{
		sum=0;
		for(i=0;i<=n-1;i++)
		{
			temp=i;
			sum+=2*n;
			if (temp<t[1])  sum+=n-t[1]+temp;
			else sum+=temp-t[1];
			temp=t[1];
			sum+=n;
			if (temp>t[2])  sum+=n-temp+t[2];
			else sum+=t[2]-temp;
			temp=t[2];
			if (temp<t[3]) sum+=n-t[3]+temp;
			else sum+=temp-t[3];
		}
printf("%.3f\n",sum/n);
	}
	return 0;
}