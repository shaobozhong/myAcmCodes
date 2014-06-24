#include<iostream>
#include<algorithm>
using namespace std;

struct Task
{
	int t,l;
};


bool cmp(Task a,Task b)
{
	return a.l>b.l;
}


int main()
{
	int n;
	int i;
	int max1;
	Task t[1005];
	while(scanf("%d",&n),n!=0)
	{
		for(i=0;i<n;++i)
		{
			scanf("%d",&t[i].t);
		}
		for(i=0;i<n;++i)
		{
			scanf("%d",&t[i].l);
		}
		sort(t,t+n,cmp);
		max1=t[0].l;
		for(i=0;i<n;++i)
		{
			if (max1<t[i].t) break;
			if (max1>t[i].l) max1=t[i].l;
			max1=max1-t[i].t;
		}
		if (i<n||max1<0) puts("impossible");
		else 
		{
			printf("%d\n",max1);
		}
	}
	return 0;
}