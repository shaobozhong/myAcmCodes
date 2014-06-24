#include<iostream>
#include<queue>
using namespace std;
int n,m;
int map[105][105];
int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};



struct node
{
	int x,y;
};

void lable(bool map1[][105],int i,int j,int num)
{
	int x,y;
	int k;
	map1[i][j]=false;
	for(k=0;k<4;++k)
	{
		x=i+dir[k][0];
		y=j+dir[k][1];
		if (x<0 || x>=n || y<0 || y>=m) continue;
		if (map1[x][y] && map[x][y]-num<=0) lable(map1,x,y,num);
	}
}

void lable1(bool map1[][105],int i,int j)
{
	queue<node>q;
	node tmp;
	node top;
	int k;
	map1[i][j]=false;
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
			if (map1[tmp.x][tmp.y]) 
			{
				map1[tmp.x][tmp.y]=false;
				q.push(tmp);
			}
		}
	}
}

bool panduan(int num)
{
	bool map1[105][105];
	int i,j;
	bool flag=false;
	for(i=0;i<n;++i)
	{
		for(j=0;j<m;++j)
		{
			map1[i][j]=true;
		}
	}

	for(i=0;i<n;++i)
	{
		if (map[i][0]-num<=0) lable(map1,i,0,num);
		if (map[i][m-1]-num<=0) lable(map1,i,m-1,num);
	}

	for(i=0;i<m;++i)
	{
		if (map[0][i]-num<=0) lable(map1,0,i,num);
		if (map[n-1][i]-num<=0) lable(map1,n-1,i,num);
	}

	for(i=0;i<n;++i)
	{
		for(j=0;j<m;++j)
		{
			if (map1[i][j]) 
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
	int min1,max1;
	casenum=0;
	//freopen("1.txt","w",stdout);
	while(scanf("%d%d",&n,&m),n!=0||m!=0)
	{
		//num.clear();
		min1=INT_MAX;
		max1=0;
		++casenum;
		for(i=0;i<n;++i)
		{
			for(j=0;j<m;++j)
			{
				scanf("%d",&map[i][j]);
				if (min1>map[i][j]) min1=map[i][j];
				if (max1<map[i][j]) max1=map[i][j];
				//num.insert(map[i][j]);
			}
		}

		tmp=0;
		for(tmp=min1;tmp<=max1;++tmp)
		//while(!num.empty())
		{
			//tmp=*(num.begin());
			if(panduan(tmp)) break; 
			//tmp=*(num.begin());
			//num.erase(num.begin());
		}
		/*for(i=0;i<n;++i)
		{
		for(j=0;j<m;++j)
		{
		cout<<map[i][j]<<" "; 
		}
		cout<<endl;
		}*/
		if (tmp>max1)
		//if (num.empty()) 
		{
			printf("Case %d: Island never splits.\n",casenum);
		}
		else 
		{
			printf("Case %d: Island splits when ocean rises %d feet.\n",casenum,tmp/*(num.begin())*/);
		}
	}
	return 0;
}

