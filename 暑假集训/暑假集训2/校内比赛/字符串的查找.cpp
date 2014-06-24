#include<iostream>
#include<string>
using namespace std;

int dir[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

char map[100][100];

string str;
int n,m;

bool work(int *x,int *y,int k,int l)
{
	if (*x<1 || *x>n || *y<1 || *y>m) return false;
	if (l+1==int(str.size())) 
	{
		if (map[*x][*y]==str[l]) return true;
		else return false;
	}

	if (map[*x][*y]==str[l])
	{
		*x+=dir[k][0];
	    *y+=dir[k][1];
		if (work(x,y,k,l+1)) return true;
	}
	return false;
}

int main()
{
	int x,y;
	int k,i,j;
	bool la;
	int t;
	int sx,sy,ex,ey;
	while(cin>>n>>m)
	{
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=m;++j)
			{
				cin>>map[i][j];
			}
		}
		cin>>t;
		while(t--)
		{
			la=false;
			cin>>str;
			for(i=1;!la&&i<=n;++i)
			{
				for(j=1;!la&&j<=m;++j)
				{
					if (str[0]==map[i][j])
					{
						if (int(str.size())==1) {sx=i;sy=j;ex=i;ex=j;la=true;break;}
						for(k=0;k<8;++k)
						{
							x=i+dir[k][0];
							y=j+dir[k][1];
							if (map[x][y]==str[1])
							{
								if (work(&x,&y,k,1)) {sx=i;sy=j;ex=x;ey=y;la=true;break;}
							}
						}
					}
				}
			}
            printf("(%d,%d)->(%d,%d)\n",sy,sx,ey,ex);
		}
	}
	return 0;
}