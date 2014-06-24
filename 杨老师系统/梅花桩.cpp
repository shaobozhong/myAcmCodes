#include<iostream>
#include<cmath>
using namespace std;

double a[100001][5];

int main()
{
	int n;
	int i,j,k;
	double max1,tmp1,tmp2;
	max1=0;
	scanf("%d",&n);
	scanf("%lf%lf%lf%lf%lf",&a[0][0],&a[0][1],&a[0][2],&a[0][3],&a[0][4]);
	scanf("%lf%lf%lf%lf%lf",&a[1][0],&a[1][1],&a[1][2],&a[1][3],&a[1][4]);
	max1=0;
	for(k=0;k<5;++k)
	{
		max1+=abs(a[1][k]-a[0][k]);
	}
	for(i=2;i<n;++i)
	{
		scanf("%lf%lf%lf%lf%lf",&a[i][0],&a[i][1],&a[i][2],&a[i][3],&a[i][4]);
			tmp1=0;
			for(k=0;k<5;++k)
			{
				tmp1+=abs(a[i][k]-a[0][k]);
			}
			if (tmp1>max1) max1=tmp1;
			tmp2=0;
			for(k=0;k<5;++k)
			{
				tmp2+=abs(a[i][k]-a[1][k]);
			}
			if (tmp2>max1) max1=tmp2;
			if (max1==tmp1)
			{
				for(k=0;k<5;++k)
				{
					a[1][k]=a[i][k];
				}
			}
			else if (max1==tmp2)
			{
				for(k=0;k<5;++k)
				{
					a[0][k]=a[i][k];
				}
			}
	}
	printf("%.2lf\n",max1);
	return 0;
}

