#include<iostream>
#include<string>
using namespace std;
const int INF = 0x3F3F3F3F; 
const int V = 30001;   
const int E = 150001; 
struct Elem
{
	int e;
	int blood;
};
struct Cost
{
	int s,e;
};
int pnt[E],nxt[E]; 
Cost cost[E];

int e, head[V];  Elem dist[V];  bool vis[V]; 
string City[105]; int num;

bool Bigger(int a,int b)
{
	if (a>=0&&a<=6 && b>=0&& b<=6)
	{
		return a>b;
	}

	if (a>=0&&a<=6 && b>=18&& b<=24)
	{
		return true;
	}

	if (a>=18&&a<=24 && b>=0&& b<=6)
	{
		return false;
	}

	if (a>=18&&a<=24 && b>=18&& b<=24)
	{
		return a>b;
	}
	return false;
}

int relax(int u, int v, const Cost &c){ 
	int b;
	if (Bigger(dist[u].e,c.s)) b=1;
	else b=0;
	if( dist[v].blood > dist[u].blood+b  || ( dist[v].blood==dist[u].blood+b && Bigger(dist[v].e,c.e))) 
	{ 
		dist[v].blood = dist[u].blood+b;
		dist[v].e=c.e;
		return 1; 
	} 

	return 0; 
} 
inline void addedge(int u, int v, int s,int ee){ 
	pnt[e] = v; cost[e].s = s; cost[e].e=ee;nxt[e] = head[u]; head[u] = e++; 
} 
int SPFA(int src, int n,int t) 
{ // 此处用堆栈实现，有些时候比队列要快 
	int  i; 
	for( i=1; i <= n; ++i ){ // 顶点1...n 
		vis[i] = 0; dist[i].blood = INF;
		dist[i].e=6;
	} 
	dist[src].blood = 0; //开始不要血
	dist[src].e=17;//可以出发的时间
	int  Q[E], top = 1;  
	Q[0] = src; vis[src] = true; 
	while( top ){ 
		int  u, v; 
		u = Q[--top]; vis[u] = false; 
		for( i=head[u]; i != -1; i=nxt[i] ){ 
			v = pnt[i]; 
			if( 1 == relax(u, v, cost[i]) && !vis[v] ) { 
				Q[top++] = v; vis[v] = true;  
			} 
		} 
	} 
	return dist[t].blood; 
} 

int find1(const string str)
{
	int i;
	for(i=1;i<num;++i)
	{
		if (City[i]==str) return i;
	}
	return -1;
}

int main(){ 
	string City1,City2;
	int Blood;
	int m; 
	int t;
	int casenum;
	cin>>casenum;
	for(t=1;t<=casenum;++t){ 
		int  i, loc1, loc2, c,s,ee; 
		num=1;
		e = 0; 
		memset(head, -1, sizeof(head)); 
		cin>>m;
		for( i=0; i < m; ++i ) 
		{// b-a <= c, 有向边(a, b):c ，边的方向！！！ 
			cin>>City1>>City2>>s>>c;
			ee=s+c;
			s%=24;
			ee%=24;
			if (c>12 || (s>6 &&s<18) || (ee>6 &&(ee)<18)) continue;
			loc1=find1(City1);
			if (loc1==-1) {loc1=num;City[num++]=City1;}
			loc2=find1(City2);
			if (loc2==-1) {loc2=num;City[num++]=City2;}
			addedge(loc1,loc2,s,ee); 
		} 
		printf("Test Case %d.\n",t);
		cin>>City1>>City2;
		loc1=find1(City1);
		if (loc1==-1) {puts("There is no route Vladimir can take.");continue;}
		loc2=find1(City2);
		if (loc2==-1) {puts("There is no route Vladimir can take.");continue;}
		Blood=SPFA(loc1,num-1,loc2);
		if (Blood==INF) {puts("There is no route Vladimir can take.");continue;}
		else printf("Vladimir needs %d litre(s) of blood.\n",Blood);
	} 
	return 0; 
} 