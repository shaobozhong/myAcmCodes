#include<iostream>
#include<string>
#include<set>
using namespace std;
int dir[8][2]={{0,1},{0,-1},{1,-1},{1,0},{1,1},{-1,-1},{-1,0},{-1,1}};	
char map[31][31];
int n;
set <string> res; 

void work(int x,int y,string str,int k)
{
	if (str!="")res.insert(str);
	if (x<0||x>=n || y<0|| y>=n) return;
	work(x+dir[k][0],y+dir[k][1],str+map[x][y],k);
}

int main()
{
	int t;

	int i,j,k;
	string str;
	scanf("%d",&t);
	while(t--)
	{
		res.clear();
		scanf("%d",&n);
		getchar();
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{
				map[i][j]=getchar();
			}
			getchar();
		}

		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{
				for(k=0;k<8;++k)
				{
				str="";
				work(i,j,str,k);
				}
			}
		}
		printf("%d\n",res.size());
	}
	return 0;
}

