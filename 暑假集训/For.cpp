#include<iostream>
using namespace std;


struct node
{
	int x,y;
};

int main()
{
	int n;
	node a[1005];
	int i,j;
	int min1,min2;
	int casenum;
	casenum=0;
	while(scanf("%d",&n),n!=0)
	{
		if (casenum) putchar('\n');
		++casenum;
		for(i=0;i<n;++i)
		{
			scanf("%d%d",&a[i].x,&a[i].y);
		}
		printf("Case %d:\n",casenum);
		for(i=0;i<n;++i)
		{
			min1=INT_MAX;min2=INT_MAX;
			for(j=0;j<n;++j)
			{
				if (a[j].x>a[i].x && a[j].y>a[i].y && (a[j].x<min1 ||  (a[j].x==min1 && a[j].y<min2))) {min1=a[j].x; min2=a[j].y;}
			}
			if (min1!=INT_MAX && min2!= INT_MAX) printf("%d %d\n",min1,min2);
			else printf("%d %d\n",-1,-1);
		}
	}
	return 0;
}

