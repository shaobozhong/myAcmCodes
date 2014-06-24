#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int mat[305][305], used[305];
const int f=1000008;
int min(int a,int b)
{
	if(a>b)return b;
	else return a;
}
int main() 
{
	int n,m,q,i,j,u,v,c,op,d=0,x,y;
	//freopen("t.in","r",stdin);
	for(d=1;;d++) 
	{
		cin>>n>>m>>q;
		if(n==0&&m==0&&q == 0) break;
		if (d>1) cout<<endl;
		cout<<"Case "<<d<<":"<<endl;
		for (i = 0; i < n; i++) 
			for (j = 0; j < n; j++) 
				mat[i][j]=f;
		for (i = 0; i < m; i++) 
		{
			cin>>u>>v>>c;
			if (u == v) continue;
			mat[u][v]=min(mat[u][v],c);
		}
		for (i=0;i<n;i++) mat[i][i]=0;
		memset(used, 0, sizeof(used));
		while (q--) 
		{
			cin>>op;
			if(op==0) 
			{
				cin>>x;
				if (used[x]) 
					cout<<"ERROR! At point "<<x<<endl;
				else 
				{
					used[x] = 1;
					for (i = 0; i < n; i++) 
					{
						for (j = 0; j < n; j++) 
						{
							if (i == j) continue;
							if (used[i]&&used[j]&&mat[i][j]<f) 
							{
								if (mat[j][x] <f) 
									mat[i][x] = min(mat[i][x], mat[i][j] + mat[j][x]);
								if (mat[x][i]<f) 
									mat[x][j] = min(mat[x][j], mat[x][i] + mat[i][j]);
							}
						}
					}
					for (i = 0; i < n; i++) 
					{
						for (j = 0; j<n; j++) 
						{
							if (i==j) continue;
							if (used[i]&&used[j]&&mat[i][x]<f&&mat[x][j]<f) 
								mat[i][j] = min(mat[i][j], mat[i][x] + mat[x][j]);
						}
					}
				}
			} 
			else {
				cin>>x>>y;
				if (!used[x]||!used[y]) cout<<"ERROR! At path "<<x<<" to "<<y<<endl;
				else 
				{
					if (mat[x][y]<f) 
						cout<<mat[x][y]<<endl;
					else 
						cout<<"No such path"<<endl;
				}
			}
		}
	}
	return 0;
}