#include<iostream>
using namespace std;

	int father[30000];
	int num[30000];
int find1(int x)
{
	int i=x;
	int j;
	while(father[x]!=x)
	{
		x=father[x];
	}
	while(father[i]!=i)
	{
		j=i;
		i=father[i];
		father[j]=x;
	}
    return x;
}

int main()
{
	int n,m,k;
    int afather,bfather;
	int a,b,i;
	while(scanf("%d%d",&n,&m),n!=0||m!=0)
	{
		for(i=0;i<n;++i)
		{
			father[i]=i;
			num[i]=1;
		}
		while(m--)
		{
			scanf("%d",&k);
			scanf("%d",&a);
			for(i=1;i<k;++i)
			{
				scanf("%d",&b);
				afather=find1(a);
				bfather=find1(b);
				if (afather!=bfather)
				{
					num[afather]+=num[bfather];
					father[bfather]=father[afather];
				}
			}
		}
		printf("%d\n",num[find1(0)]);
	}
	return 0;
}