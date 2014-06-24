#include<iostream>
#include<vector>
#include <set>
#include<limits>
using namespace std;
typedef struct 
{
	vector <int> B;
	vector <int> P; 
}Device;
int main()
{
	int t,n,m,i,j,b,pri;
	double result,tresult;
	double psum;
	
	set<int> B;
	set <int>::iterator p;
	Device d[102];
	scanf("%d",&t);
	while(t--)
	{
		result=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&m);
			for(j=1;j<=m;j++)
			{
				scanf("%d%d",&b,&pri);
				d[i].B.push_back(b);
				d[i].P.push_back(pri);
				if (B.find(b)==B.end()) B.insert(b);
			}
		}
		for(p=B.begin();p!=B.end();++p)
		{
			psum=0;
			for(i=0;i<n;i++)
			{
				pri=INT_MAX;
				for(j=0;j<d[i].B.size();j++)
				{
					if (d[i].B[j]>=*p&&d[i].P[j]<pri)
					{
						 pri=d[i].P[j];
					}
				}
				if (pri==INT_MAX) break;
				psum+=pri;
			}
			if (pri==INT_MAX) continue;
			tresult=(double)(*p)/psum;
        if (tresult>result) result=tresult;
		}
		printf("%.3f\n",result);
		B.clear();
		for(i=0;i<=m;i++)
		{
			d[i].B.clear();
			d[i].P.clear();
		}
	}
	return 0;
}