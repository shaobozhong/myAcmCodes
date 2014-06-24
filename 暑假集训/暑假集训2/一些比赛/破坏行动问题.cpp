#include<iostream>
using namespace std;

int n,m,s,t;//记录结点数，管道数。A地和B地的编号  
/*数组pre用来记录增广路，数组v用来记录可增广的流量，数组queque用于广度扩展增广路的队列，p是队头指针，q是队尾指针，
g用是邻接矩阵*/

int g[130][130],t1[8500],p,q,queque[130],v[130],pre[130];

int min(int a,int b)
{
	return a<b?a:b;
}

void augment(int v)
{
	int i=t,j=pre[t];//从t开始，以v为增量，修正搜索出来的增广路的流量，知道源点s为止
	while(i!=s)
	{
		g[i][j]+=v;//增加（i,j）边的流量
		g[j][i]-=v;//减少（j,i）边的逆向流量 
		i=j,j=pre[i];//去增广路上的下一条边修正
	}
}

void maxflow()
{
	int i,j;
	while(1)
	{
		memset(pre,0xff,sizeof(pre));
		for(i=0;i<n;++i)
		{
			v[i]=30000;
		}


		p=q=0;// p是队头指针，g是队尾指针
		queque[0]=s;// 把源点s加入到队列中
		for(;p<=q;p++)
		{
			i=queque[p];//取队列头的元素
			for(j=0;j<n;++j)
			{
				if (g[i][j]>0&&pre[j]<0) 
				{
					//广度优先寻找增广路
					pre[j]=i;
					v[j]=min(v[i],g[i][j]);// 记录最小的可增广的流量
					queque[++q]=j;
				}
			}
			if (pre[t]>0) break;// 如果找到一条到达汇点的增广路，退出循环

		}
		if (pre[t]>=0)
		{
			augment(v[t]);//沿着汇点 反方向修正增广路，增加流量
		}
		else
		{
			break;//已经找不到到达汇点的增广路，退出
		}
	}
}

void solve()
{
	int i,j,k,tot;//使用floyd求传递闭包求残量网络中能够允许1流量通过的所有路径

	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			for(k=0;k<n;++k)
			{
				/*如果从结点j到结点i还允许有流量通过，并且从结点i到结点k也还允许有流量通过
				那么从结点j到结点k也允许1流量通过。（中间经过点i）*/
				if (g[j][i] && g[i][k]) g[j][k]=1;
			}
		}
	}

	tot=0;
	//统计所有的流量为0的残量边的总数，即为所求
	for(k=0;k<m;++k)
	{
		i=t1[k]/n;//从t1中解码得到一条边的两个结点 
		j=t1[k]%n;
		if (g[i][j]==0 || g[j][i]==0) tot++;//如果该边没有流量通过则累加到tot中
	}

	cout<<tot<<endl;
	//输出每条流量为0 的残量边 

	for(k=0;k<m;++k)
	{
		i=t1[k]/n;//从t1中解码得到一条边的两个结点
		j=t1[k]%n;
		//如果该边没有流量通过则输出  
		if (g[i][j]==0 || g[j][i]==0) cout<<k+1<<endl;
	}
}

int main()
{
	int i,j,k,c;
	cin>>n>>m>>s>>t;//读入数据
	s--;t--;//结点都是从0开始的

	for(k=0;k<m;++k)//读入管道并存储
	{
		cin>>i>>j>>c;
		i--;j--;
		g[i][j]=g[j][i]=c;
		t1[k]=i*n+j;//对每条管道编码成为一个整数并存储在t1数组中 
	}

	maxflow(); // 求网络最大流
	solve();   //用floyd求出所有符合条件的边 并输出  
	return 0;

}