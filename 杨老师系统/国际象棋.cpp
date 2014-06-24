#include<iostream>
#include<cmath>
#include<set>
#include<queue>
using namespace std;

int dir[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};

class State
{
public:int x,y;
private:
	friend bool operator <(const State &a,const State &b)
	{
		if (a.x==b.x)
		{
			return a.y<b.y;
		}
		return a.x<b.x;
	}
	friend bool operator ==(const State &a,const State &b)
	{
		return a.x==b.x&&a.y==b.y;
	}
};

class node
{
public:int x,y,step;
};

int main()
{
	set <State> vis;
	queue<node> q;
	node top;
	node tmp;
	State tmp1;
	int ex,ey;
	int n,m,i;
	bool res,la;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		while(!q.empty())
		{
			q.pop();
		}
		vis.clear();

		scanf("%d%d",&tmp.x,&tmp.y);
		scanf("%d%d",&ex,&ey);

		if (m<=0) {printf("Knight cannot reach Queen within %d moves!\n",m);continue;}
		tmp.step=0;
		q.push(tmp);
		tmp1.x=tmp.x;
		tmp1.y=tmp.y;
		vis.insert(tmp1);
		la=false;
		res=false;
		while(!la&&!q.empty())
		{
			top=q.front();
			q.pop();
			//if (top.step==m) {res=false;la=true;break;} 
			if (top.step==m||(m-top.step)*2<abs(ex-top.x) || (m-top.step)*2<abs(ey-top.y)) {continue;}//top.step==m 放在这比独立跳出 还快？？？？
			for(i=0;i<8;++i)
			{
				tmp1.x=top.x+dir[i][0];
				tmp1.y=top.y+dir[i][1];
				if (tmp1.x==ex && tmp1.y==ey) {res=true;la=true;break;}
				if (tmp1.x<1||tmp1.x>n || tmp1.y<1 ||tmp1.y>n || vis.count(tmp1)>0) continue;
				tmp.step=top.step+1;
				tmp.x=tmp1.x;
				tmp.y=tmp1.y;
				q.push(tmp);
				vis.insert(tmp1);
			}
		}
		if (res) printf("Knight can reach Queen within %d moves!\n",m);
		else     printf("Knight cannot reach Queen within %d moves!\n",m);
	}

	return 0;
}

