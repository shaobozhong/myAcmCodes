#include<iostream>
using namespace std;
	int father[1005];
int find1(int x)
{
	int i=x,j;
	while(father[x]!=x)
	{
		x=father[x];
	}

	while(father[i]!=x)
	{
		j=i;
		i=father[i];
		father[j]=x;
	}
	return x;
}


int main()
{
	int loc1,loc2,a,b;

	int n,m;
	int i,j;
	int count1;
	while(scanf("%d",&n),n!=0)
	{
		scanf("%d",&m);
		for(i=0;i<=n;++i)
		{
			father[i]=i;
		}
        count1=n-1;
		while(m--)
		{
			scanf("%d%d",&a,&b);
			loc1=find1(a);
			loc2=find1(b);
			if (loc1!=loc2)
			{
				--count1;
				father[loc2]=father[loc1];
			}
		}
		printf("%d\n",count1);
	}
	return 0;
}