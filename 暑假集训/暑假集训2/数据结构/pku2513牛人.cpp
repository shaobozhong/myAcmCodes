#include<iostream>
using namespace std;

int color[10000], set[10000];

void init()
{
	memset(color, 0, sizeof(color));
	memset(set, -1,sizeof(set));
}

int hash(char *str)
{
	int sum=1;
	while(*str)
		sum=(sum*29 + *str++ - 'a')%9991;
	return sum;
}

int find_set(int x)
{
	int temp, root;
	root=x;
	while(set[root]>=0)
	{
		//printf("%d\n", root);
		root=set[root];
	}
	temp=x;
	while(temp!=root)
	{
		//printf("ddd\n");
		x=set[temp];
		set[temp]=root;
		temp=x;
	}
	return root;
}

void union_set(int x, int y)
{
	int sum=set[x]+set[y];
	if(set[x]>set[y])
	{
		set[x]=y;
		set[y]=sum;
	}
	else
	{
		set[y]=x;
		set[x]=sum;
	}
}

int main()
{
	int n1, n2, r1, r2, odd, i, root;
	char a[15], b[15];
	init();
	while(scanf("%s%s", &a, &b)!=EOF)
	{
		n1=hash(a);
		n2=hash(b);
		//printf("%d %d\n", n1, n2);
		color[n1]++;
		color[n2]++;
		r1=find_set(n1);
		r2=find_set(n2);
		if(r1!=r2)
			union_set(r1, r2);
	}
	odd=0;
	root=-1;
	for(i=0; i<10000; ++i)
	{
		if(color[i])
		{
			if(color[i]%2)
			{
				++odd;
				if(odd>2)
				{
					//printf("here1\n");
					printf("Impossible\n");
					return 0;
				}
			}
			if(root==-1)
			{
				//printf("got\n");
				root=find_set(i);
			}
			else
			{
				if(root!=find_set(i))
				{
					//printf("%d\n", i);
					//printf("here2\n");
					printf("Impossible\n");
					return 0;
				}
			}
		}
	}
	printf("Possible\n");
	return 0;
}