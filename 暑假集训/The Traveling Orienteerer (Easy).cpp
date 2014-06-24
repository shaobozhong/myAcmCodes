#include<iostream>
#include<cmath>
using namespace std;

struct point 
{
	double x,y;
};

int main()
{
	int n,m,i,j,k;

	int r[20];
	double sum;
    point p[1005];
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;++i)
		{
			scanf("%lf%lf",&p[i].x,&p[i].y);
		}
        scanf("%d",&m);
		while(m--)
		{
			sum=0;
			scanf("%d",&k);
			for(i=0;i<k;++i)
			{
				scanf("%d",&r[i]);
			}
			for(i=0;i<k-1;++i)
			{
				
					sum+=sqrt((p[r[i]].x-p[r[i+1]].x)*(p[r[i]].x-p[r[i+1]].x) +(p[r[i]].y-p[r[i+1]].y)*(p[r[i]].y-p[r[i+1]].y));

			}
			//sum+=sqrt((p[r[i]].x-p[r[0]].x)*(p[r[i]].x-p[r[0]].x) +(p[r[i]].y-p[r[0]].y)*(p[r[i]].y-p[r[0]].y));
			printf("%.0lf\n",sum);
		}
	}
	return 0;
}