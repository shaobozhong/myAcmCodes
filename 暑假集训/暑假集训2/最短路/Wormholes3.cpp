#include<iostream>
using namespace std;
#define MAXN 505
#define inf 1000000000
typedef int elem_t;
elem_t mat[MAXN][MAXN];
elem_t min1[MAXN];
int pre[MAXN];
bool bellman_ford(int n,int s){
	int v[MAXN],i,j,k,tag;
	for (i=0;i<n;i++)
		min1[i]=inf,v[i]=0,pre[i]=-1;
	for (min1[s]=0,j=0;j<n;j++){
		for (k=-1,i=0;i<n;i++)
			if (!v[i]&&(k==-1||min1[i]<min1[k]))
				k=i;
		for (v[k]=1,i=0;i<n;i++)
			if (!v[i]&&mat[k][i]>=0&&min1[k]+mat[k][i]<min1[i])
				min1[i]=min1[k]+mat[pre[i]=k][i];
	}
	for (tag=1,j=0;tag&&j<=n;j++)
		for (tag=i=0;i<n;i++)
			for (k=0;k<n;k++)
				if (min1[k]+mat[k][i]<min1[i])
					min1[i]=min1[k]+mat[pre[i]=k][i],tag=1;
	return j<=n;
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
				mat[i][j]=inf;
			}
		}
		while(m--)
		{
			scanf("%d%d%d",&i,&j,&dis);
			if (mat[i-1][j-1]>dis)
			{
				mat[i-1][j-1]=dis;
				mat[j-1][i-1]=dis;
			}
		}

		while(w--)
		{
			scanf("%d%d%d",&i,&j,&dis);
			dis*=-1;
			mat[i-1][j-1]=dis;
		}

		if (!bellman_ford(n,0)) puts("YES");
		else puts("NO");
	}
	return 0;
}