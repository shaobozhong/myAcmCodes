#include<iostream>
#include<algorithm>
using namespace std;

struct University
{
	int sum;
	int de[101];
};
	int n,m;
bool cmp(const University &a,const University &b)
{
	return a.sum<b.sum;
}

bool compare(const University &a,const University &b)
{
	int i;
	for(i=0;i<m;++i)
	{
		if (a.de[i]<b.de[i]) return false;
	}
	return true;
}

int main()
{
	int c;

	int i,j;
	int num;
	University u[101]; 
	int res[101];
	int max1;
	scanf("%d",&c);
	while(c--)
	{
		max1=1;
		scanf("%d%d",&n,&m);
			for(i=1;i<=n;++i)
			{
				u[i].sum=0;
			}
			for(i=0;i<m;++i)
			{
				for(j=0;j<n;++j)
				{
					scanf("%d",&num);
					u[num].de[i]=j;
					u[num].sum+=j;
				}
			}
			sort(u+1,u+n+1,cmp);
			for(i=1;i<=n;++i)
			{
				res[i]=1;
			}

			for(i=2;i<=n;++i)
			{
				for(j=1;j<i;++j)
				{
					if (compare(u[i],u[j])) 
					{
						if (res[j]+1>res[i]) {res[i]=res[j]+1;if (max1<res[i]) max1=res[i];}
					}
				}
			}
            printf("%d\n",max1);
	}

	return 0;
}