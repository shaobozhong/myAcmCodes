//program block;
//uses crt;
#include<iostream>
using namespace std;
#include<string>

int e[33],t[33];   //{保留的中间解}
int biao[33][33];   //{将解变为输出形式的数组}
//s:array[-1..32,-1..32,0..1] of longint;   {计算用数组}
int s[34][34][2];
int lmin,l,n,m;//n积木个数 m是最高的高度 lmin是最小列数  l是当前搜索所假定的列数
string fs;
char ch;
int total;

void  out()      //{输出}
{
	int i,j;
	memset(biao,0,sizeof(biao));

	for(i=1;i<=32;++i)
	{
		e[i]=t[i];
	}

	++total;
	cout<<total<<endl;
	for (i=1;i<=l;++i)// {解的转换}
	{
		j=1;
		while (e[i]>0)
		{
			biao[j][i]=1;
			++j;
			--(e[i]);
		}
	}


	for (i=m;i>=1;--i)//{打印}
	{
		for (j=1;j<=n;++j)
		{
		if (j!=n) printf("%d ",biao[i][j]);//用空格隔开数据
		if (j==n) printf("%d",biao[i][j]);//行的最后不产生空格
		}
		if (l!=lmin || i!=1) putchar('\n');//最后不产生回车
	}

}
//v开始时1   x开始是n  z开始是0
void work(int v,int x,int z)   //{搜索过程}
{

	int i,j;
	if (v==l-v+1)                   //{判断是否找到解}如果 l是奇数 那么v是最中间一列
	{
		if (x==0) return;
		if (x<=m)  { t[v]=x;out();}//剩余小于 m个则满足条件
		return;
	}

	if (v>l-v+1)//l是偶数 则全部都已经安排好了
	{
		if (x==0)  out();//不应有剩余
		return;
	}


	//{分情况}
	if (z==0)//如果需要考虑
	{
		//{要保证左>右时}
		for (i=1;i<=m;++i)
		{
			for (j=i;j<=m;++j)
				if (x-i-j>=0)
				{
					t[v]=j;t[l-v+1]=i;//分别将i，j放入对称的两个位置 保证左大于右  所以将i放入左边
					if (i==j)  work(v+1,x-i-j,0);//0表示接下来还是要判断T>T'
					else work(v+1,x-i-j,1);//1表示接下来不需要判断了
				}
		}
	}


	if (z==1) //                      {不用保证左>右时}
	{
		for (i=1;i<=m;++i)
		{
			for (j=1;j<=m;++j)
			{
				if (x-i-j>=0)
				{
					t[v]=i;t[l-v+1]=j;//因为不用保证左大于右随便放
					work(v+1,x-i-j,1); 
				}
			}
		}
	}


}

void suan()		//  {计算过程}直接运算出 total
{
	int x,y,i,j;
	int rr;
	//{数据初始化}
	memset(s,0,sizeof(s));
	s[1][0][0]=1;s[1][0][1]=1;
	s[1][1][0]=1;s[1][1][1]=1;
	for (x=1;x<=m;++x){ s[x+1][2][0]=1;s[x+1][2][1]=1;}
	//{-------------}
	for (x=2;x<=n;++x)
		for (y=2;y<=x;++y)           // {求s[x,y];}
		{
			//{-----两种情况-----}
			for (i=1;i<=m;++i)
				for (j=i;j<=m;++j)
					if (x-i-j>=0)
						if (i==j)
							s[x+1][y+1][0]=s[x+1][y+1][0]+s[x-i-j+1][y-2+1][0];
						else
							s[x+1][y+1][0]=s[x+1][y+1][0]+s[x-i-j+1][y-2+1][1];
			//{-----------------}
			for (i=1;i<=m;++i)
				for (j=1;j<=m;++j)
					if (x-i-j>=0)
						s[x+1][y+1][1]=s[x+1][y+1][1]+s[x-i-j+1][y-2+1][1];
		}
		rr=0;
		//{求总数}
		for (i=1;i<=n;++i)
			rr=rr+s[n+1][i+1][0];
		printf("Total=%d\n",rr);
}


int main()
{

	//{数据初始化}
	total=0;

	memset(t,0,sizeof(t));
	cin>>n;
	cin>>m;
	//{选择输出方式}
	//suan();
	lmin=int(double(n)/m+0.99);//求出最小的列数
	//{搜索寻解}
	printf("%d %d\n",n,m);
	for (l=n;l>=lmin;--l)//从最大列数到最小列数进行尝试
	{
		work(1,n,0);
	}
	//printf("total=%d\n",total);
}
