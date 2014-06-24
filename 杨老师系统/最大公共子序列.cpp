#include<iostream>
using namespace std;

int main()
{
	bool la;
	int a[10001],i;
	int n,max,number,begin,end,tbegin,tend;
	while(scanf("%d",&n)>0&&n!=0)
	{
		la=false;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		max=-1;begin=a[0];end=a[n-1];number=0;
		tbegin=a[0];tend=a[n-1];
		for(i=0;i<n;i++)
		{
			if (a[i]>=0) la=true;
			if (number+a[i]<a[i]) 
			{
				tbegin=a[i];
				tend=a[i];
				number=a[i];
				if (number>max)
				{
					max=number;
					begin=tbegin;
					end=tend;
				}
			}
			else 
			{
				number+=a[i];tend=a[i];
				if (number>max)
				{
					max=number;
					begin=tbegin;
					end=tend;
				}
			}
		}
		if (!la)
		{
			max=0;
			printf("%d %d %d\n",max,a[0],a[n-1]);
		}
		else 
		{
			printf("%d %d %d\n",max,begin,end);
		}

	}
	return 0;
}