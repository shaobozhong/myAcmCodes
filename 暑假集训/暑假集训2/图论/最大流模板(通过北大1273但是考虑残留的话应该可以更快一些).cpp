#include<iostream>
#include<queue>
using namespace std;

#define MAX 1000

struct Node
{
	int la;
	struct Node *next;
};
int map[MAX][MAX];//存储图




bool find_path(int n,int s,int t,int *pre )//利用广度遍历 寻找增广路  总个数 n个  数组要往后放一个
{
	queue<int> q;
	bool vis[MAX];
	int top;//队列中头的值
	int i;// 循环变量
	for(i=1;i<=n;++i)
	{
		vis[i]=true;
	}
	q.push(s);
	vis[s]=false;
	while(!q.empty())//广度优先 用队列实现
	{
		top=q.front();
		q.pop();
		for(i=1;i<=n;++i)//点就只能从1开始了
		{
			if (vis[i] && map[top][i]>0) 
			{
				vis[i]=false;
				pre[i]=top;
				if (i==t) 
				{
					return true;
				}
				q.push(i);
			}
		}
	}
return false;
}




int Ford_Fulkerson(int n,int s,int t)
{
	int pre[MAX];//用于记录从源点s到汇点t的增广路
	int Flood;//总流量的值
	int min1;//增广路的课增量中最小的那个
	int i;//循环变量
	Flood=0;//初始化 最大流量为0
	while(find_path(n,s,t,pre))
	{
		min1=INT_MAX;
		for(i=t;i!=s;i=pre[i])//找到可增量中最小的那个
		{
			if (map[pre[i]][i]<min1) 
			{
				min1=map[pre[i]][i];
			}
		}
		//增大流量，同时使该增广路变为不可增广 
		for(i=t;i!=s;i=pre[i])
		{
			map[pre[i]][i]-=min1;
			map[i][pre[i]]+=min1;//建逆向边
		}
		Flood+=min1;//增大总流量
	}
	return Flood;
}

int main()
{
	int n,m;
	int num1,num2,flow;
	int i,j;
	int Flood;
	//freopen("1.txt","r",stdin);
	//freopen("2.txt","w",stdout);
	while(cin>>n>>m)
	{
		for(i=0;i<=m;++i)
		{
			for(j=0;j<=m;++j)
			{
				map[i][j]=0;
			}
		}

		for(i=1;i<=n;++i)
		{
			cin>>num1>>num2>>flow;
			map[num1][num2]+=flow;
		}

		Flood=Ford_Fulkerson(m,1,m);
		cout<<Flood<<endl;
	}
	return 0;
}