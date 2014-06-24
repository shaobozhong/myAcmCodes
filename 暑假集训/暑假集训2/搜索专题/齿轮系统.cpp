//这里采用的是在图中找圈的方式 实际上是可以采用 看齿轮转向的方式 去找  速度可能会快一点 至少少了最后的确定方向

#include<iostream>
#include<set>
using namespace std;

int min1;
int n,m,engine;//n个齿轮   m个相邻关系启动轮的标号
int map[32][32];//存储转化后的地图
char direct[32];//记录各个齿轮的方向

set <int> s;//当前集合
set <int> mind;//最小要删除的元素集合
set <int> d;// 当前情况要删除的元素



void work(int x)//x代表已经删除的顶点的个数
{

	int k,l;
	int j;
	int lasti,lastj;
	int	 p[32]={0};//记录本点从哪里扩展而来
	bool la;
	set<int> od;//保存没有将没遍历到的元素添加进d之前的d
	set <int> oex;//进行扩展的点
	set <int> expand;//保存下一步要扩展的点
	set<int> ::iterator i;//集合的迭代器
	set <int> v;//存储奇数个顶点圈的元素
	set <int> vis;//已经遍历过的点的集合
	if (x>min1) return;//要是已经大于最小删掉的顶点数 就没必要继续做了
	expand.insert(engine);
	vis.insert(engine);
	la=false;

	while(1)//广度搜索奇数个顶点的圈
	{
		oex=expand;
		expand.clear();
		for(i=oex.begin();i!=oex.end()&&!la;++i)//逐个扩展本层要扩展的元素
		{
			//cout<<*i<<endl;
			for(j=1;j<=n&&!la;++j)//一个个看能不能扩展 （因为是矩阵表示的图）
			{
				if (map[*i][j]==1 && s.find(j)!=s.end() ) //如果能扩展 并且扩展出的元素 在s中
				{
					if (vis.find(j)==vis.end())//如果没有被遍历过
					{
						map[*i][j]=2;
						map[j][*i]=2;
						vis.insert(j);
						expand.insert(j);
						p[j]=*i;
					}
					else //被遍历过 也就是形成了圈
					{
						lasti=*i;
						lastj=j;
						while(lasti!=lastj )
						{
							v.insert(lasti);
							v.insert(lastj);
							
							if (p[p[lasti]]==p[lastj]) //防止出现走到圈外
							{
								v.insert(p[lasti]);
								lasti=lastj=p[lastj];
							}
							if (p[p[lastj]]==p[lasti]) 
							{
								v.insert(p[lastj]);
								lasti=lastj=p[lasti];
							}
							if (p[lasti]) {lasti=p[lasti];}
							if (p[lastj])lastj=p[lastj]; 
						}
						if (lasti==lastj) v.insert(lasti);

						if (v.size()%2==1) la=true;//判断是不是奇圈
						else {v.clear();map[*i][j]=2;map[j][*i]=2; p[j]=*i;expand.insert(j);}//不是奇圈则继续
					}
				}
			}
		}
		if (expand.empty() || la ) break;
	}



	for(k=1;k<=n;++k)
	{
		for(l=1;l<=n;++l)
		{
			if (map[k][l]==2) map[k][l]=1;
		}
	}



	if (!la)
	{
		od=d;
		x=n-int(vis.size());
	    for(k=1;k<=n;++k)
		{
			if (vis.find(k)==vis.end()&&d.find(k)==d.end())
			{
				d.insert(k);
			}
		}
		
		//x+=int(d.size());
		if (min1>x)
		{
			min1=x;
			mind=d;
		}
		d=od;
		return;
	}




	for(i=v.begin();i!=v.end();++i)
	{
		if (*i!=engine)
		{
			s.erase(s.find(*i));
			d.insert(*i);
			work(x+1);
			d.erase(d.find(*i));
			s.insert(*i);
		}
	}


}


int main()
{
	char ch;
	int x,y,i,j,CC,OP,count;
	set<int>::iterator  k;
	set <int> oex;//进行扩展的点
	set <int> expand;//保存下一步要扩展的点
	set <int> vis;
	while(cin>>n>>m)
	{
		d.clear();
		min1=INT_MAX;
		CC=0;
		OP=0;
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=n;++j)
			{
				map[i][j]=0;
			}
		}

		for(i=1;i<=n;++i)
		{
			s.insert(i);
			direct[i]='N';
		}
		for(i=1;i<=m;++i)
		{
			cin>>x>>y;
			map[x][y]=true;
			map[y][x]=true;
		}
		cin>>engine;
		cin>>ch;
		if (ch=='O') OP++;
		else CC++;
		work(0);
		if (min1==0) puts("W");
		else puts("B");
		expand.insert(engine);
		vis.insert(engine);
		direct[engine]=ch;
		while(1)//广度遍历确定个轮的转向
		{
			oex=expand;
			expand.clear();
			for(k=oex.begin();k!=oex.end();++k)
			{
				for(j=1;j<=n;++j)
				{
					if (map[*k][j]==1 && mind.find(j)==mind.end()&&vis.find(j)==vis.end()) 
					{
						map[*k][j]=2;
						map[j][*k]=2;
						if (direct[*k]=='C') {direct[j]='O';++OP;}
						else {direct[j]='C';++CC;}
						expand.insert(j);
						vis.insert(j);
					}
				}
			}
			if (expand.empty()) break;
		}
		if (!CC) cout<<"CC";//输出顺时针的结果
		else
		{
			cout<<"CC ";
			count=0;
			for(i=1;i<=n;++i)
			{
				if (direct[i]=='CC') 
				{
					++count;
					if (count<CC) {cout<<i<<" ";}
					else cout<<i<<endl;
				}
			}
		}

		if (!OP) cout<<"O"<<endl;//输出逆时针的结果
		else
		{
			count=0;
			cout<<"O ";
			for(i=1;i<=n;++i)
			{
				if (direct[i]=='O') 
				{
					++count;
					if (count<OP) {cout<<i<<" ";}
					else cout<<i<<endl;
				}
			}
		}

		if (min1!=0)// 输出要删掉的元素
		{
			cout<<"R ";
			count=0;
			for(k=mind.begin();k!=mind.end();++k)
			{
				count++;
				if (count<int(mind.size())) cout<<*k<<" ";
				else cout<<*k<<endl;
			}
		}
		vis.clear();
		expand.clear();
		s.clear();
	}
	return 0;
}