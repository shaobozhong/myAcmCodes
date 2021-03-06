#include<iostream>
#include<set>
#include<queue>
using namespace std;
int n,m;
int map[105][105];
int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};

set<int> num;

struct node
{
	int x,y;
};

void lable(char map1[][105],int i,int j)
{
	int x,y;
	int k;
	map1[i][j]='@';
	for(k=0;k<4;++k)
	{
		x=i+dir[k][0];
		y=j+dir[k][1];
		if (x<0 || x>=n || y<0 || y>=m) continue;
		if (map1[x][y]=='0') lable(map1,x,y);
	}
}

void lable1(char map1[][105],int i,int j)
{
	queue<node>q;
	node tmp;
	node top;
	int k;
	map1[i][j]='@';
	tmp.x=i;
	tmp.y=j;
	q.push(tmp);
	while(!q.empty())
	{
		top=q.front();
		q.pop();
		for(k=0;k<4;++k)
		{
			tmp.x=top.x+dir[k][0];
			tmp.y=top.y+dir[k][1];
			if (tmp.x>=n || tmp.x<0 || tmp.y<0 || tmp.y>=m) continue;
			if (map1[tmp.x][tmp.y]!='@') 
			{
				map1[tmp.x][tmp.y]='@';
				q.push(tmp);
			}
		}
	}
}

bool panduan()
{
	char map1[105][105];
	int i,j;
	bool flag=false;
	for(i=0;i<n;++i)
	{
		for(j=0;j<m;++j)
		{
			if (map[i][j]==0) map1[i][j]='0';
			else map1[i][j]='1';
		}
	}

	for(i=0;i<n;++i)
	{
		if (map1[i][0]=='0') lable(map1,i,0);


		if (map1[i][m-1]=='0') lable(map1,i,m-1);
	}

	for(i=0;i<m;++i)
	{
		if (map1[0][i]=='0') lable(map1,0,i);
		if (map1[n-1][i]=='0') lable(map1,n-1,i);
	}

	for(i=0;i<n;++i)
	{
		for(j=0;j<m;++j)
		{
			if (map1[i][j]!='@') 
			{
				if (flag) 
				{ 	
					return true; 
				}
				lable1(map1,i,j);
				flag=true;
			}
		}
	}

	return false;
}

int main()
{

	int i,j;
	int tmp;
	int casenum;
	casenum=0;
	//freopen("1.txt","w",stdout);
	while(scanf("%d%d",&n,&m),n!=0||m!=0)
	{
		num.clear();
		++casenum;
		for(i=0;i<n;++i)
		{
			for(j=0;j<m;++j)
			{
				scanf("%d",&map[i][j]);
				num.insert(map[i][j]);
			}
		}

		tmp=0;
		while(!num.empty())
		{
			tmp=*(num.begin())-tmp;
			for(i=0;i<n;++i)
			{
				for(j=0;j<m;++j)
				{
					map[i][j]-=tmp;
					if (map[i][j]<0) map[i][j]=0;
				}
			}
			if(panduan()) break; 
			tmp=*(num.begin());
			num.erase(num.begin());
		}
		/*for(i=0;i<n;++i)
		{
		for(j=0;j<m;++j)
		{
		cout<<map[i][j]<<" "; 
		}
		cout<<endl;
		}*/
		if (num.empty()) 
		{
			printf("Case %d: Island never splits.\n",casenum);
		}
		else 
		{
			printf("Case %d: Island splits when ocean rises %d feet.\n",casenum,*(num.begin()));
		}
	}
	return 0;
}