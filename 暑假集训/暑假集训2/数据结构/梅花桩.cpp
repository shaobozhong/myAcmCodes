#include<iostream>
#include<cmath>
using namespace std;

double a[100001][5];

int main()
{
	int n;
	int i,j,k;
	double max1;
	max1=0;
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		scanf("%lf%lf%lf%lf%lf",&a[i][0],&a[i][1],&a[i][2],&a[i][3],&a[i][4]);
		for(j=0;j<i;++j)
		{
			double tmp=0;
			for(k=0;k<5;++k)
			{
				tmp+=abs(a[i][k]-a[j][k]);
			}
			if (tmp>max1) max1=tmp;
		}
	}
	printf("%.2lf",max1);
	return 0;
}