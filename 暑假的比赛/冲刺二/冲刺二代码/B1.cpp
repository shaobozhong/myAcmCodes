# include <iostream>
using namespace std;

int w[2004];  //物品的重量
int v[2004];  //物品的价值
int c; //背包的容量
int n; //物品的种类
int ** m; //最优值
int *x; //最优解数组

int max(int a, int b); //求a, b中的较大者
int min(int a, int b);
void fun(); // 计算最优值
void Traceback(int *x); //构造最优解


int main()
{
	int z,i,j,t,k,g;
	// freopen("0-1背包问题.in", "r", stdin);
	cin>>g;
	while(g--)
	{
		cin>>c;//kaishi****************
		cin>>z;
		j=0;
		for(i=1;i<=z;i++)
		{
			j++;
			scanf("%d%d%d",&w[j],&v[j],&t);
			for(k=2;k<=t;k++)
			{
				j++;
				w[j]=w[j-1];
				v[j]=v[j-1];
			}
		}
		//cin>>n;//beibaozhognlei
		n=j;
		m = new int *[n+1];
		for(i=1; i<=n; i++)
		{
			m[i] = new int [101];
		}
		for(i=1; i<=n; i++)
		{//初始化最优值都为0
			for(int j=1; j<=100; j++)
			{
				m[i][j] = 0;
			}
		}
		//x = new int [n+1];
		fun(); //函数调用，计算最优值
		//Traceback(x); //构造最优解
	}
	return 0;
}


int max(int a, int b) //定义函数，求a, b中的较大者
{
	if(a>=b)
		return a;
	else
		return b;
}

int min(int a, int b)  //求a, b中的较小者
{
	if(a>=b)
		return b;
	else
		return a;
}
void fun()  //自底向上计算最优值
{
	int jMax = min(w[n]-1, c); //保证jMax < w[n];
    for(int j=0; j<=jMax; j++) 
	{  //只有第n件物品，但背包容量不够
		m[n][j] = 0;
	}
	for(j=w[n]; j<=c; j++) 
	{  //只有第n件物品，且背包容量足够
		m[n][j] = v[n];
	}
	for(int i=n-1; i>1; i--)
	{
		jMax = min(w[i]-1, c); //确保jMax < w[i];
		for(int j=0; j<=jMax; j++) 
		{ //可以选择的物品为i, i+1, ……, n, 但容量小于w[i]
			m[i][j] = m[i+1][j];
		}
		for(j=w[i]; j<=c; j++)   
		{	//可以选择的物品i, i+1, ……, n, 且容量大于等于w[i]
			m[i][j] = max(m[i+1][j], m[i+1][j-w[i]]+v[i]);
		}
	}
	m[1][c] = m[2][c];  //上面没有求出m[1][c]
	if(c >= w[1]) 
	{ //可以选择的物品1，2，……，n, 且背包容量大于等于w[1]
		m[1][c] = max(m[1][c], m[2][c-w[1]]+v[1]);
	}
    //cout<<"带走物品的最大价值为: ";
	cout<<m[1][c]<<endl;
}


void Traceback(int *x)  //根据最优值构造最优解
{
    for(int i=1; i<n; i++)
	{
		if(m[i][c] == m[i+1][c])
			x[i] = 0;
		else
		{
			x[i] = 1;
			c -= w[i]; 
		}
	}
	x[n] = (m[n][c])? 1:0;  //判断最优值m[n][c]是否为真，如果是，x[n] = 1;否，x[n] = 0;
	//	cout<<"最优解是: "<<endl;
	/*for(i=1; i<=n; i++)
	{
	cout<<x[i]<<" ";
}*/
	cout<<endl;
}


