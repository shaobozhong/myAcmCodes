#include <stdio.h>
#include <string.h>

int a, b, n, k, ans, min, now;
int map[100][100], bj[100];

int dfs(int x) {
	int tmp, min = -1;
	bj[x] = 1;
	if(x == k) return 0;
	for(int i = 0; i < n; ++i) 
	{
		if(i == now) continue;
		if(bj[i]) continue;
		if(map[x][i])
		{
			tmp = dfs(i);
			if(tmp != -1) if((min == -1) || (tmp + 1 < min)) min = tmp + 1;
		}
	}
	bj[x] = 0;
	return min;
}

void solve(int x) 
{
	int tmp;
	   now = x;
	if(dfs(0) == -1) 
	{ 
		now = -1;
		 tmp = dfs(x);
		if(tmp < min) 
		{
			min = tmp;
			ans = x;
		}
	}
}

int main()
{
	int t,i,j,m;
	scanf("%d",&t);
	for(j=1;j<=t;j++)
	{
		for(n=0;n<100;n++)
		{
			for(k=0;k<100;k++)
			{
				map[n][k]=0;
			}
		}
		scanf("%d %d", &n, &k);
		scanf("%d",&m);
		while(m-- ) 
		{
			scanf("%d %d", &a, &b);
			map[a][b] = 1;
		}
		ans = 0;
		now = -1;
		min = dfs(0);
		for(i = 1; i < n; ++i) 
		{
			memset(bj, 0, sizeof(bj));
			if(i != k) solve(i);
		}
		printf("Case %d:Put guards in room %d.\n", j,ans);
	}
	return 0;
}
