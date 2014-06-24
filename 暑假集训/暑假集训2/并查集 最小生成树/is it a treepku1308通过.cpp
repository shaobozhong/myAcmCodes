#include<iostream>
using namespace std;

int father[100005];

int find1(int x)
{
	int i=x;
	while(father[x]!=x)
	{
		x=father[x];
	}

	while(father[i]!=i)
	{
		int j=i;
		i=father[i];
		father[j]=x;
	}
	return x;
}

int main()
{
	int a,b;
	int i;
	int count1;
	int point,side;
	int test=0;
	while(scanf("%d%d",&a,&b),a!=-1||b!=-1)
	{
		++test;
		if(a==0 && b==0)
		{
			printf("Case %d is a tree.\n",test);
			continue;
		}

		point =0;
		int loc1,loc2;
		side=0;
		bool la=true;
		for(i=1;i<=100000;++i)
		{
			father[i]=0;
		}
		++side;
		if (father[a]==0)
		{
			father[a]=a;
			++point;
		}
		if (father[b]==0)
		{
			father[b]=b;
			++point;
		}	
		loc1=find1(a);
		loc2=find1(b);
		if (loc1!=loc2)
		{
			father[loc2]=father[loc1];
		}
		else la=false;
		while(scanf("%d%d",&a,&b),a!=0||b!=0)
		{
			++side;
			if (la)
			{
				if (father[a]==0)
				{
					father[a]=a;
					++point;
				}
				if (father[b]==0)
				{
					father[b]=b;
					++point;
				}
				loc1=find1(a);
				loc2=find1(b);
				if (loc1!=loc2)
				{
					father[loc2]=father[loc1];
				}
				else la=false;
			}
		}
		if (la && side==point-1) printf("Case %d is a tree.\n",test);
		else printf("Case %d is not a tree.\n",test);
	}
	return 0;
}