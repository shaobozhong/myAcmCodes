//杭电 1010
#include<iostream>
using namespace std;

char map[9][9];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

bool maze(int sx,int sy,int dx,int dy,int t,int n,int m)
{
	int i;
    
	if (sx<1 || sx>n || sy<1 || sy>m) return false;
	if (abs(sx-dx)>t || abs(sy-dy)>t) return false;
	if (t==0)
	{
		if (sx==dx && sy==dy) return true;
		else return false;
	}

	map[sx][sy]='X';
	for(i=0;i<4;++i)
	{
		if (map[sx+dir[i][0]][sy+dir[i][1]]!='X')
		{
			if (maze(sx+dir[i][0],sy+dir[i][1],dx,dy,t-1,n,m)) return true;
		}
	}
	map[sx][sy]='.';
	return false;
}

int main()
{
	int n,m,t;//矩阵的行数、列数、门开的时间
	int i,j;//循环变量
	int sx,sy,dx,dy;//起点和终点的坐标变量
	int count1;
	while(cin>>n>>m>>t,n!=0||m!=0||t!=0)
	{
        count1=0;
		sx=0;sy=0;dx=0;dy=0;
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=m;++j)
			{
				cin>>map[i][j];
				if (map[i][j]!='X') count1++;
				if (map[i][j]=='S') {sx=i;sy=j;}
				else 
				{
					if (map[i][j]=='D') {dx=i;dy=j;}
				}
			}
		}
		if (count1<t+1||(abs(sx-dx)+abs(sy-dy))%2!=t%2) {puts("NO");continue;}
		if (maze(sx,sy,dx,dy,t,n,m)) puts("YES");
		else puts("NO");
	}
	return 0;
}