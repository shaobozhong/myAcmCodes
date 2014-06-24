#include<iostream>
using namespace std;
#define MAXN 600
#define inf 1000000000
typedef int elem_t;
elem_t G[MAXN][MAXN];
elem_t G1[MAXN][MAXN];
//elem_t mat1[MAXN][MAXN];
//elem_t min1[MAXN];

bool Bellman_ford(int n,int s)
{
    int i,j,k,d[MAXN];
    for (i=0;i<n;i++) {d[i]=inf;}
    d[s]=0;
    for (k=1;k<n;k++)
	{
        for (i=0;i<n;i++)
		{
            for (j=0;j<n;j++)
			{
                if (d[j]>d[i]+G[i][j]) {d[j]=d[i]+G[i][j];}
			}
		}
	}
    
    for (i=0;i<n;i++)
	{
        for (j=0;j<n;j++)
		{
            if (d[j]>d[i]+G[i][j])
			{
				return false;
			}
		}
	}

    return true;
}
 

 
int main()
{
	elem_t dis;
	int f;
	int n,m,w;
	int i,j,k;
	scanf("%d",&f);
	while(f--)
	{
		scanf("%d%d%d",&n,&m,&w);
		for(i=0;i<=n;++i)
		{
			for(j=0;j<=n;++j)
			{
				G[i][j]=inf;
			}
		}
		while(m--)
		{
			scanf("%d%d%d",&i,&j,&dis);
			if (G[i-1][j-1]>dis)
			{
				G[i-1][j-1]=dis;
				G[j-1][i-1]=dis;
			}
		}

		while(w--)
		{
			scanf("%d%d%d",&i,&j,&dis);
			dis*=-1;
			G[i-1][j-1]=dis;
		}

		/*for(k=0;k<n;++k)
		{
			for(i=0;i<n;++i)
			{
				for(j=0;j<n;++j)
				{
					G[i][j]=G1[i][j];
				}
			}
			if (!Bellman_ford(n,k)) break; 
		}*/

        /*if (k<n) puts("YES");
		else puts("NO");*/

		if (!Bellman_ford(n,0)) puts("YES");
		else puts("NO");
	}
	return 0;
}