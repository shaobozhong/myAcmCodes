#include<iostream>
using namespace std;

int map[100][100];
int n,m;

bool ifbeauty()
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<m-1;j++)
		{
			if (map[i][j]==0&&(map[i+1][j]==0||map[i][j+1]==0)) return false;
		}
		if (map[i][j]==0&&map[i+1][j]==0) return false;
	}
	for(i=0;i<m-1;i++)
	{
		if (map[n-1][i]==0&&map[n-1][i+1]==0) return false;
	}
	return true;
}
int main()
{
	bool all;
	
    int i,j;
	while(scanf("%d%d",&n,&m),m!=0||n!=0)
	{
		all=true;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%d",&map[i][j]);
				if (map[i][j]==0) all=false;
			}
		}
		if (all) {puts("No");continue;}
		if (ifbeauty()) {puts("Yes");continue;}
		puts("No");
	}
	return 0;
}