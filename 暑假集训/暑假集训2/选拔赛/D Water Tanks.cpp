#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int t,n;
	int i,k;
	int count2,step,tres,res;
	int a[205];

	int sum,sum2;
	bool flag;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		res=INT_MAX;
		sum=0;
		for(i=0;i<n;++i)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}

       
		for(k=0;k<n;++k)
		{
			     tres=0;
				  flag=true;
					sum2=0;
				    count2=k;
					step=0;
					while(flag||count2!=k)
					{
						++step;
						if (flag) flag=false;
						
						sum2+=a[count2];
						if (sum2*n==step*sum) {sum2=step=0;}
						else ++tres;
						++count2;
						if (count2==n) count2=0;
					}
			if (res>tres) res=tres;
		}
		printf("%d\n",res);
	}
	return 0;
}