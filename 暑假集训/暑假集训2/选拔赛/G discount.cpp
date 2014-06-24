#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int t;
	double p,d;
	int num;
	int res;
	int a[5],count1,add;
	bool la;
	scanf("%d",&t);
	while(t--)
	{
		la=false;
		scanf("%lf%lf",&p,&d);
		p=p*(100-d)/100;
		if (fabs(p-int(p))<0.000001) res=int(p);
		else res=int(p+1);
		num=res;
		count1=0;
		while(num)
		{
			a[count1]=num%10;
			if (a[count1]==8) la=true;
			++count1;
			num/=10;
		}
		if (la) printf("%d\n",res);
		else 
		{
			if (a[0]<8) add=8-a[0];
			else add=18-a[0];
			if (a[1]<8) 
			{
				if (80-(a[1]*10+a[0])<add) add=80-(a[1]*10+a[0]);
			}
			res+=add;
			printf("%d\n",res);
		}
	}
	return 0;
}