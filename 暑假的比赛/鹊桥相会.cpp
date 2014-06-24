#include<iostream>
#include<limits>
using namespace std;

int main()
{
	int min,n,distance,i,t,v,ctime_1;
	while(scanf("%d%d",&distance,&n)!=EOF&&(n!=0||distance!=0))
	{
		min=INT_MAX;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&t,&v);
			if (t<=0&&v>0)
			{
				ctime_1=(distance*1000-t)/v;
			if (min>ctime_1) min=ctime_1;
			}

			}
		
		if (min==INT_MAX) printf("Can't Solve\n");
		else 
		{
			printf("%d\n",min);
		}
		
	}
	return 0;
}