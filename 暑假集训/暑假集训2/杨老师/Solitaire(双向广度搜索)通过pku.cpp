#include<iostream>
#include<string>
#include<set>
#include<queue>
using namespace std;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

struct State//一个表示 扩展出来的状态的结构体
{
	int a[4][2];
	string state;
	int step;
};

void reform(State *s)//将四个点的坐标转换成一个 16位的字符串
{
	int i;
	s->state="0000000000000000000000000000000000000000000000000000000000000000";
	for(i=0;i<4;++i)
	{
		s->state[((s->a[i][0])-1)*8+s->a[i][1]]='1';
	}
}

int main()
{
	//bool vis1[65];//标记正向搜索遍历过的点
	//bool vis2[65];//标记逆向搜索遍历过的点
	set<string> vis1;//正向扩展结果的集合
	set<string> vis2;//逆向扩展结果的集合
	bool la,res;//标记是否找到答案 或者该跳出了
	queue <State> q;//正向广度用的队列
	queue <State> rq;//逆向广度用的队列
	State s,e;//起始状态和目标状态 
	State top,temp;//队头 和 临时变量
	int i,j,k;
	while(cin>>s.a[0][0])
	{
		vis1.clear();
		vis2.clear();
		while(!q.empty())
		{
			q.pop();
		}
		while(!rq.empty())
		{
			rq.pop();
		}

		cin>>s.a[0][1];
		for(i=1;i<4;++i)
		{
			for(j=0;j<2;++j)
			{
				cin>>s.a[i][j];
			}
		}
		reform(&s);
		for(i=0;i<4;++i)
		{
			for(j=0;j<2;++j)
			{
				cin>>e.a[i][j];
			}
		}
		reform(&e);
		if (s.state==e.state) {puts("YES");continue;}//若直接相等了

		s.step=0;
		e.step=0;
		q.push(s);
		la=false;
		res=false;
		vis1.insert(s.state);//开始扩展
		while(!la&&!res&&!q.empty())
		{

			top=q.front();
			q.pop();
			for(i=0;!la&&!res&&i<4;++i)
			{
				for(j=0;!la&&!res&&j<4;++j)
				{
					if (top.a[i][0]+dir[j][0]>0&&top.a[i][0]+dir[j][0]<=8 && top.a[i][1]+dir[j][1]<=8&&top.a[i][1]+dir[j][1]>0) //没有越界
					{
						if (top.state[(top.a[i][0]+dir[j][0]-1)*8+top.a[i][1]+dir[j][1]]=='0')//要走到的点 没有被占据
							//if(vis1[(top.a[i][0]+dir[j][0]-1)*8+(top.a[i][1]+dir[j][1])]) 
						{
							temp.step=top.step+1;//步骤加1 
							if (temp.step>4) {la=true;break;}//大于四步就跳出
							for(k=0;k<4;++k)//所有点 只要改一个 其他的照搬
							{
								temp.a[k][1]=top.a[k][1];
								temp.a[k][0]=top.a[k][0];
							}
							temp.a[i][0]=top.a[i][0]+dir[j][0];//要更新的 就更新
							temp.a[i][1]=top.a[i][1]+dir[j][1];
							//vis1[(temp.a[i][0]-1)*8+temp.a[i][1]]=false;
							reform(&temp);//状态转字符串
							if (temp.state==e.state) {res=true;break;}//达到目标状态
							if (vis1.find(temp.state)==vis1.end()) {q.push(temp);vis1.insert(temp.state);}//没有这种状态过  就可以扩展到这种状态
						}

						else 
						{
							if (top.a[i][0]+2*dir[j][0]>0&&top.a[i][0]+2*dir[j][0]<=8 && top.a[i][1]+2*dir[j][1]<=8&&top.a[i][1]+2*dir[j][1]>0) 
							{
								if (top.state[(top.a[i][0]+2*dir[j][0]-1)*8+top.a[i][1]+2*dir[j][1]]=='0')
									//if(vis1[(top.a[i][0]+2*dir[j][0]-1)*8+(top.a[i][1]+2*dir[j][1])]) 
								{
									temp.step=top.step+1;
									if (temp.step>4) {la=true;break;}
									for(k=0;k<4;++k)
									{
										temp.a[k][1]=top.a[k][1];
										temp.a[k][0]=top.a[k][0];
									}
									temp.a[i][0]=top.a[i][0]+2*dir[j][0];
									temp.a[i][1]=top.a[i][1]+2*dir[j][1];
									//vis1[(temp.a[i][0]-1)*8+temp.a[i][1]]=false;
									reform(&temp);
									if (temp.state==e.state ) {res=true;break;}
									if (vis1.find(temp.state)==vis1.end()) {q.push(temp);vis1.insert(temp.state);}
								}
							}
						}
					}
				}
			}
		}


		if (res) {puts("YES");continue;}
		rq.push(e);
		vis2.insert(e.state);
		la=false;
		while(!la&&!res&&!rq.empty())
		{
			top=rq.front();
			rq.pop();
			for(i=0;!la&&!res&&i<4;++i)
			{
				for(j=0;!la&&!res&&j<4;++j)
				{
					if (top.a[i][0]+dir[j][0]>0&&top.a[i][0]+dir[j][0]<=8 && top.a[i][1]+dir[j][1]<=8&&top.a[i][1]+dir[j][1]>0) 
					{
						if (top.state[(top.a[i][0]+dir[j][0]-1)*8+top.a[i][1]+dir[j][1]]=='0')
							//if(vis2[(top.a[i][0]+dir[j][0]-1)*8+(top.a[i][1]+dir[j][1])]) 
						{
							temp.step=top.step+1;
							if (temp.step>4) {la=true;break;}
							for(k=0;k<4;++k)
							{
								temp.a[k][1]=top.a[k][1];
								temp.a[k][0]=top.a[k][0];
							}
							temp.a[i][0]=top.a[i][0]+dir[j][0];
							temp.a[i][1]=top.a[i][1]+dir[j][1];
							//vis2[(temp.a[i][0]-1)*8+temp.a[i][1]]=false;
							reform(&temp);
							if (temp.state==s.state ||vis1.find(temp.state)!=vis1.end()) {res=true;break;}//在正向的四步中有出现过了
							if (vis2.find(temp.state)==vis2.end()) {rq.push(temp);vis2.insert(temp.state);}
						}

						else 
						{
							if (top.a[i][0]+2*dir[j][0]>0&&top.a[i][0]+2*dir[j][0]<=8 && top.a[i][1]+2*dir[j][1]<=8&&top.a[i][1]+2*dir[j][1]>0) 
							{
								if (top.state[(top.a[i][0]+2*dir[j][0]-1)*8+top.a[i][1]+2*dir[j][1]]=='0')
								//if(vis2[(top.a[i][0]+2*dir[j][0]-1)*8+(top.a[i][1]+2*dir[j][1])]) 
								{
									temp.step=top.step+1;
									if (temp.step>4) {la=true;break;}
									for(k=0;k<4;++k)
									{
										temp.a[k][1]=top.a[k][1];
										temp.a[k][0]=top.a[k][0];
									}
									temp.a[i][0]=top.a[i][0]+2*dir[j][0];
									temp.a[i][1]=top.a[i][1]+2*dir[j][1];
									//vis2[(temp.a[i][0]-1)*8+temp.a[i][1]]=false;
									reform(&temp);
									if (temp.state==s.state ||vis1.find(temp.state)!=vis1.end()) {res=true;break;}
									if (vis2.find(temp.state)==vis2.end()) {rq.push(temp);vis2.insert(temp.state);}
								}
							}
						}
					}
				}
			}
		}

		if (res) puts("YES");
		else puts("NO");
	}
	return 0;
}