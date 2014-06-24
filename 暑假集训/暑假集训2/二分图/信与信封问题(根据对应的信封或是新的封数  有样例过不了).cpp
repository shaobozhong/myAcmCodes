#include<iostream>
using namespace std;

int n;
int res[101];
bool map[101][101];

bool match_perfect(int &x,int &y)
{
	int i,j;
	int k;
	int count1;
	for(i=1;i<=n;++i)
	{
		x=i;
		count1=0;
		for(j=1;j<=n;++j)
		{
			if (map[i][j]) {y=j;++count1;}
		}
		if (count1==1) 
		{
			for(k=1;k<=n;++k)
			{
				map[x][k]=false;
				map[k][y]=false;
			}
			return true;
		}
	}

	for(i=1;i<=n;++i)
	{
		y=i;
		count1=0;
		for(j=1;j<=n;++j)
		{
			if (map[j][i]) {x=j;++count1;}
		}
		if (count1==1) 
		{
			for(k=1;k<=n;++k)
			{
				map[x][k]=false;
				map[k][y]=false;
			}
			return true;
		}
	}


	return false;
}

int main()
{
	
	int x,y;
	int i,j;
	while(scanf("%d",&n)!=EOF)
	{
	for(i=1;i<=n;++i)
	{
		res[i]=0;
		for(j=1;j<=n;++j)
		{
			map[i][j]=true;
		}
	}
	while(scanf("%d%d",&x,&y),x!=0||y!=0)
	{
		map[x][y]=false;
	}
	if (match_perfect(x,y)) res[x]=y;
	else 
	{
		puts("none");continue;
	}
    for(i=2;i<=n;++i)
	{
	  if (match_perfect(x,y)) res[x]=y;
	  else break;
	}

	for(i=1;i<=n;++i)
	{
		if (res[i]) printf("%d %d\n",i,res[i]);
	}
	}
	return 0;
}