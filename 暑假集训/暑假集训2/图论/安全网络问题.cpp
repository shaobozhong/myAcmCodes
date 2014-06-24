/*算法描述;
1 将整个网络分离出个连通分量  
2 从0到n-1 逐个试探每个服务器是否是关键的。对每一个结点，找出含有该结点的连通分量，将该结点删除后 重新划分该连通分量 要是只能划出一个 就说明不是关键服务器 
不把新的连通分量加入总的  连通分量集合中（在本程序中 也就是链表中） 否则删除原来的 加入新的 并且按照 最小服务器编号  排序
本程序中是采用广度遍历探索连通分量
同时可以考虑使用深度遍历 来探索连通分量 可以大幅度减少代码长度
*/
#include<iostream>
#include<set>
using namespace std;

#define MAX 100
struct Connect//为存储连通分量建立的结构体
{
	set<int> Link;//保存连通分量
	struct Connect *next;
};

bool map[MAX][MAX];//存储图
bool vis[MAX];//扩展时标记是否遍历过
Connect Chead,*Ctail;//存储所有连通分量的链表 和最后一个单元的指针
int n;//服务器的数量
int minsubnet;//最小的安全子网数

void findlink()//找连通分量
{
	int i,j;
	Connect *p,*q;
	set<int> oex;//这两个set用于广度扩展连通分量
	set<int> expand;//当前扩展的集合
	set<int> ::iterator ex;//迭代器
	for(i=0;i<n;++i)//所有点都没有被遍历过
	{
		vis[i]=true;
	}
	p=&Chead;
	minsubnet=0;//初始化最小安全子网数
	for(i=0;i<n;++i)
	{
		if (vis[i])
		{
			minsubnet+=1;//最小安全子网数加1
			q=new Connect;
			q->Link.insert(i);
			oex.insert(i);
			vis[i]=false;
			while(1)
			{
				expand=oex;
				oex.clear();
				for(ex=expand.begin();ex!=expand.end();++ex)
				{
					for(j=0;j<n;++j)
					{
						if (vis[j] && map[*ex][j]) 
						{
							oex.insert(j);
							vis[j]=false;//遍历过了
							q->Link.insert(j);
						}
					}
				}
				if (oex.empty()) break;
			}
			q->next=p->next;
			p->next=q;
			p=p->next;
		}
	}
	Ctail=p;
}

bool attemptdel(Connect *pre,int sn)//链表中当前的上一个结点 为删除方便  尝试删除的服务器的编号 该函数就是尝试删除某一顶点 看其是否关键服务器 并且返回是否进行了更新
{

	Connect *p,*q,*next,temp;
	bool map1[MAX][MAX];
	set<int> oex;//这两个set用于广度扩展连通分量
	set<int> expand;//当前扩展的集合
	set<int> ::iterator ex,iset;//迭代器
	int count1;
	int psn,qsn;//p指针指向的连通分量的最小服务器编号
	int i,j;//循环变量
	for(i=0;i<n;++i)//所有点都没有被遍历过
	{
		vis[i]=true;
	}
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			map1[i][j]=map[i][j];
		}
	}

	for(i=0;i<n;++i)
	{
		if (map1[sn][i]) 
		{
			map1[sn][i]=false;
			map1[i][sn]=false;
		}
	}
	temp.next=NULL;
	p=&temp;
	count1=0;
	for(iset=pre->next->Link.begin();iset!=pre->next->Link.end();++iset)
	{
		if (vis[*iset] && *iset!=sn)
		{
			count1+=1;
			q=new Connect;
			q->Link.insert(*iset);
			oex.insert(*iset);
			vis[*iset]=false;
			while(1)
			{
				expand=oex;
				oex.clear();
				for(ex=expand.begin();ex!=expand.end();++ex)
				{
					for(j=0;j<n;++j)
					{
						if (j!=sn &&pre->next->Link.find(j)!=pre->next->Link.end()&& vis[j] && map1[*ex][j] ) 
						{
							oex.insert(j);
							vis[j]=false;//遍历过了
							q->Link.insert(j);
						}
					}
				}
				if (oex.empty()) break;
			}
			q->next=p->next;
			p->next=q;
			p=p->next;
		}
	}

	if (count1<=1) return false;
	minsubnet+=count1-1;
	pre->next=pre->next->next;
	p=pre;
	q=temp.next;
	while(q)
	{
		q->Link.insert(sn);
		next=q->next;//保存q的下一个 因为q->next会改变
		if (p->next) psn=*(p->next->Link.begin());//要是下一个为空就没有link 
		qsn=*(q->Link.begin());
		while(p->next && psn<qsn)
		{
			p=p->next;
			if (p->next) psn=*(p->next->Link.begin());//要是下一个为空就没有link
		}
		q->next=p->next;
		p->next=q;
		p=p->next;
		q=next;//q往后走
	}
	return true;
}

void printdata()
{
	Connect *p;
	set<int> ::iterator iset;//迭代器
	cout<<minsubnet<<endl;
	p=Chead.next;
	while(p)
	{
		for(iset=p->Link.begin();iset!=p->Link.end();++iset)
		{
			cout<<*iset<<" ";
		}
		cout<<endl;
		p=p->next;
	}
}
int main()
{

	int i,j;//循环变量
	int k,sn,lk;//服务器的编号  一个服务器的相连的服务器数 连接的服务器的编号
	char ra;//读取无用的括号
	Connect *p;
	set<int> ::iterator iset;//迭代器
	bool  la;//标记尝试删除是否更新了  连通分量
	while(cin>>n)
	{
		//图的建立
		Chead.next=NULL;
		for(i=0;i<n;++i)//初始化图
		{
			for(j=0;j<n;++j)
			{
				map[i][j]=false;
			}
		}

		for(i=1;i<=n;++i)
		{
			cin>>k;
			cin>>ra;
			cin>>sn;
			cin>>ra;
			for(j=1;j<=sn;++j)
			{
				cin>>lk;
				map[k][lk]=true;//另一个方向在另一个服务器的描述中会有
			}
		}
		//先找出所有的连通分量并存储到链表中
		findlink();
		//到这里 找到了图中原有的连通分量 接下来就开始对每一个连通分量 看是否含有关键服务器
		p=&Chead;
		while(p->next)
		{
			for(iset=p->next->Link.begin();iset!=p->next->Link.end();++iset)
			{
				la=false;
				la=attemptdel(p,*iset);
				if (la) break;//要是删除了 就应该跳出来
			}
			if (!la) p=p->next;//要是已经删除了 就还要对替上来的这一个进行尝试
		}
		printdata();//输出数据
	}
	return 0;
}