#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int c,int d)
{
	return c<d;
}


int main()
{
	int a[1200],b[1200];
	bool vis[1200];
	int t,n;
	int i,j;
	int count1;
	scanf("%d",&t);
	int caseNum;
	caseNum=0;
	while(t--)
	{
		++caseNum;
		memset(vis,false,sizeof(vis));
		scanf("%d",&n);
		for(i=0;i<n;++i)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;++i)
		{
			scanf("%d",&b[i]);
		}

		sort(a,a+n,cmp);
		count1=0;

		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{
				if (vis[j]) continue;
				if (a[i]>=b[j]) 
				{
					vis[j]=true;
					++count1;
					break;
				}
			}
		}

		printf("Case %d: %d\n",caseNum,count1);
	}
	return 0;
}

