#include<iostream>
#include<algorithm>
using namespace std;

#define maxn 33

bool map[maxn][maxn];//记录转化图的邻接矩阵
bool p[maxn],pbest[maxn];//记录每个位置上选或不选的状态
int best,sumbest;//最佳的种类数和资金
int h[maxn];//存储启发式函数的结果
int d[maxn];//存储各个顶点的出度
int fund,various;//资金和种类
int v[maxn];//鱼的价格

void init()//初始化
{
	int i,j;
	best=0;
	sumbest=0;
	for(i=1;i<=various;++i)
	{
		for(j=1;j<=various;++j)
		{
			map[i][j]=false;
		}
	}
	for(i=1;i<=various;++i)
	{
		p[i]=false;
		pbest[i]=false;
	}
}

void datainput()
{
	int i,num,price;//循环变量、编号、价格、用来表示子图
	int num1,num2;//有边的两个顶点的编号

	for(i=1;i<=various;++i)
	{
		cin>>num>>price;
		v[num]=price;
	}
	while(cin>>num1>>num2,num1!=0||num2!=0)
	{
		map[num1][num2]=true;
		map[num2][num1]=true;
	}
}

bool cmp(int a,int b)
{
	return a>b;
}

void h_found()//启发式函数
{
	int c,t;
	int n,i,j,s;
	for(n=1;n<=various;++n)
	{
		for(i=1;i<=n;++i)//统计各点的出度
		{
			d[i]=0;
			for(j=1;j<=n;++j)
			{
				if (map[i][j]) ++d[i];
			}
		}
		s=0;
		for(i=1;i<=n;++i) s+=d[i];//计算子图的度之和
        sort(d+1,d+n+1,cmp);//对度的数组进行由大到小排序
		c=0;
		t=0;
		while(c<s)//从最大的度顶点开始取 但是又不大于度的总和
		{
			++t;
			c+=2*d[t];//断开和其他顶点的边
		}
		h[n]=n-t;
	}
}

bool judge(int choose,int sum,int i)
{
	int j;
	if (choose+h[i-1]<best) return false;
	if (sum>fund) return false;
	for(j=1;j<=various;++j)
	{
		if (p[j] && map[i][j]) return false;
	}
	return true;
}

void p_found(int choose,int sum,int i)//当前的选择种类数，资金和，当前的鱼的种类的编号
{
	int j;
	if (i==0) 
	{
		if (choose>best||choose==best &&sum>sumbest)
		{
			best=choose;
			sumbest=sum;
			for(j=1;j<=various;++j)
			{
				pbest[j]=p[j];
			}
		}
		return;
	}
	if (choose+h[i-1]>=best)
	{
		p_found(choose,sum,i-1);
	}

	if (judge(choose+1,sum+v[i],i)) 
	{
		p[i]=true;
		p_found(choose+1,sum+v[i],i-1);
        p[i]=false;
	}

}


void dataoutput()
{
	int i;
	cout<<best<<" "<<sumbest<<endl;
	for(i=1;i<=various;++i)
	{
		if (pbest[i]) cout<<i<<endl;
	}
}
int main()
{
	cin>>fund>>various;
	init();
	datainput();
	h_found();
	p_found(0,0,various);
	dataoutput();
	return 0;
}