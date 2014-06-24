#include<iostream>
using namespace std;
#define  Max 6000
int n,m,w;
int a,b,t;
int d[502];
int ct;
struct edge
{
	int u,v,d;
}e[Max];
bool bellman_ford()
{
	for(int i=1;i<=n;i++)//初始化所有点
		d[i]=999999;
	d[1]=0;
	for(int i=1;i<=n-1;i++)//进行循环，循环下标为从1到n－1
	{
		int ok=1; 
		//遍历途中所有的边
		for(int j=0;j<ct;j++)             //如果这轮j的for循环没有“松弛”过的话
		{                                 //就不需要进行下一轮i的for循环了   
			if(d[e[j].v]>d[e[j].u]+e[j].d)//因为以后再也不会松弛了，这个结论可以得到证明
			{
				d[e[j].v]=d[e[j].u]+e[j].d;
				ok=0;
			}
		}
		if(ok)
			break;                       
	}
	for(int i=0;i<ct;i++)// 判有负环
	{
		if(d[e[i].v]>d[e[i].u]+e[i].d)
			return 1;
	}
	return 0;
}
int main()
{
	int cas;
	cin>>cas;
	while(cas--)
	{
		ct=0;
		cin>>n>>m>>w;
		for(int i=1;i<=m;i++)
		{
			cin>>a>>b>>t;
			e[ct].u=a;
			e[ct].v=b;
			e[ct].d=t;
			ct++;
			e[ct].u=b;
			e[ct].v=a;
			e[ct].d=t;
			ct++;
		}
		for(int j=1;j<=w;j++)
		{
			cin>>a>>b>>t;
			e[ct].u=a;
			e[ct].v=b;
			e[ct].d=-t;
			ct++;
		}
		bool ans=bellman_ford();
		if(ans)
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
