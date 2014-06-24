#include<iostream>
using namespace std;

int n,m;
int w[16],c[16];
int max1;


void work(int i,int sumw,int sumc)
{
	int j;
	if (sumw>m) return;
	if (i==n)
	{
		if (sumc>max1) max1=sumc;
		return;
	}
	if (sumc>max1) max1=sumc;
	for(j=0;j<=i+1;++j)
	work(i+1,sumw+j*w[i],sumc+j*c[i]);

}


int main()
{

	int t;
	int i;
	scanf("%d",&t);
	while(t--)
	{
		max1=0;
		scanf("%d%d",&n,&m);
		for(i=0;i<n;++i)
		{
			scanf("%d",&w[i]);
		}
		for(i=0;i<n;++i)
		{
			scanf("%d",&c[i]);
		}
		work(0,0,0);
		printf("%d\n",max1);
	}
	return 0;
}

