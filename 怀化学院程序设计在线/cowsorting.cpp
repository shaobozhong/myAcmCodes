#include<iostream>
#include<algorithm>
using namespace std;
int a[10001];
bool cmp(int i,int j)
{
	return a[i]<a[j];
}

int main()
{
	int n,i,j;
	int p[10001],vis[10001],sum,mini,mn,res,_count,temp;
	while (scanf("%d",&n)!=EOF)
	{   
		res=0;;
		mn=INT_MAX;
		memset(vis,0,sizeof(vis));
		for (i=0;i<n;++i)
		{
			cin>>a[i];
			if (a[i]<mn) mn=a[i];
			p[i]=i;
		}
		sort(p,p+n,cmp);
		for (i=0;i<n;++i)
		{
			if (p[i]==i) continue;
			if (vis[i]!=1)
			{
				_count=1;
				mini=a[i];
				sum=a[i];
				j=p[i];
				while (j!=i)
				{
					_count++;
					vis[j]=1;
					sum+=a[j];
					if (mini>a[j]) mini=a[j];
					j=p[j];
				}
				temp=sum+(_count-2)*mini; 
				if (temp>sum+(_count+1)*mn+mini) temp=sum+(_count+1)*mn+mini;
				res+=temp;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}