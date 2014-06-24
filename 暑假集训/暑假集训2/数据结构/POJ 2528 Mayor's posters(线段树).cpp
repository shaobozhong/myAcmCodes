//此程序采用线段树的算法 但是还是太慢了 所以加上离散化  而且因为题目中使用 方格序号表示 所以要转化成端点的形式

#include<iostream>
#include<algorithm>
using namespace std;

struct Node
{
	int state;
	int lx,rx;
};
Node tree[65536];
bool vis[10005];
struct Poster
{
	int lx,rx;
};

bool cmp(int a,int b)
{
	return a<b;
}

void build(int postnum,Poster poster,int *p,int treenum)
{
	int tmp;
	if (treenum%2==0) {if (tree[treenum/2-1].state!=0) tree[treenum].state =tree[treenum/2-1].state;}
	else {if (tree[treenum/2].state!=0) tree[treenum].state=tree[treenum/2].state;}
	if (poster.rx<=p[tree[treenum].lx] || poster.lx>=p[tree[treenum].rx]) return; 
	if (poster.lx<=p[tree[treenum].lx] && poster.rx>=p[tree[treenum].rx]) 
	{
		tree[treenum].state=postnum;
		/*if (treenum)
		{
		if (treenum%2==0) tree[treenum/2-1].state=0;
		else tree[treenum/2].state=0;
		}*/
		return;
	}
	if (tree[treenum].state==10001) tree[treenum].state=0;
	if (tree[treenum].lx+1==tree[treenum].rx  ||  tree[treenum].lx==tree[treenum].rx) return;
	tmp=treenum*2+1;
	if (tree[tmp].state==-1)
	{
		tree[tmp].state=10001;
		tree[tmp].lx=tree[treenum].lx;
		tree[tmp].rx=(tree[treenum].lx+tree[treenum].rx)/2;
	}
	build(postnum,poster,p,tmp);
	tmp=treenum*2+2;
	if (tree[tmp].state==-1)
	{
		tree[tmp].state=10001;
		tree[tmp].lx=(tree[treenum].lx+tree[treenum].rx)/2;
		tree[tmp].rx=tree[treenum].rx;
	}
	build(postnum,poster,p,tmp);
	tree[treenum].state=0;
}


int Solve(int treenum)
{
	if (tree[treenum].state==-1) return 0;
	if (tree[treenum].state==10001) return 0;
	if (tree[treenum].state ) 
	{
		if (!vis[tree[treenum].state])
		{
		vis[tree[treenum].state]=true;
		return 1;
		}
		return 0;
		//return 1+Solve(treenum*2+1)+Solve(treenum*2+2);
	}
	else 
	{
		return Solve(treenum*2+1)+Solve(treenum*2+2);
	}
	return 0;
}


int main()
{
	int casenum,count1;
	int n,i;
	Poster poster[10005];
	int p[20005];
	int ans,tmp;
	scanf("%d",&casenum);
	//freopen("3.txt","w",stdout);
	while(casenum--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
		{
			scanf("%d%d",&poster[i].lx,&poster[i].rx);
			poster[i].lx-=1;
			p[2*i-2]=poster[i].lx;
			p[2*i-1]=poster[i].rx;
		}
		sort(p,p+2*n,cmp);//对端点进行排序
		count1=0;
		for(i=1;i<2*n;++i)//去掉重复
		{
			if (p[i-1]!=p[i]) p[++count1]=p[i];
		}
		tmp=count1+2;
		for(i=0;i<65536;++i)
		{
			tree[i].state=-1;
		}

		for(i=1;i<=n;++i)
		{
			vis[i]=false;
		}


		tree[0].lx=0;tree[0].rx=count1;tree[0].state=10001;//初始化根结点

		for(i=1;i<=n;++i)
		{
			build(i,poster[i],p,0);
		}

		ans=Solve(0);

		printf("%d\n",ans);
	}
	return 0;
}