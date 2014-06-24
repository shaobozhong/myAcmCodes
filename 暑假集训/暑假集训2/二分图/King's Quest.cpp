#include<stdio.h>
#include<memory.h>
#include<algorithm>
using namespace std;

#define N 4010
int link[N][N/2],nlink[N],edge[N*N][2],nedge,nvec;
int pid,id[N],flag[N];
void gen_scc_dfs(int p,int pf,int con){
	int np=nlink[p],i,t;
	flag[p]=pf;
	for(i=0;i<np;i++){
		t=link[p][i];
		if(flag[t]==con)gen_scc_dfs(t,pf,con);
	}if(pid)id[pid++]=p;
}


int gen_scc()
{
	int i;
	memset(nlink,0,sizeof(*nlink)*nvec);
	memset(flag,0,sizeof(*flag)*nvec);
	for(i=0;i<nedge;i++)
	{
		int f=edge[i][1],t=edge[i][0];
		link[f][nlink[f]++]=t;
	}
	pid=1;
	int blk=-1;
	for(i=0;i<nvec;i++)if(!flag[i])
		gen_scc_dfs(i,blk--,0);
	memset(nlink,0,sizeof(*nlink)*nvec);
	for(i=0;i<nedge;i++)
	{
		int f=edge[i][0],t=edge[i][1];
		link[f][nlink[f]++]=t;
	}
	blk=1;
	int nid=pid;
	pid=0;
	for(i=nid-1;i>0;i--)
		if(flag[id[i]]<0)
		gen_scc_dfs(id[i],blk++,flag[id[i]]);
	return blk;
}


int first[N];
int ans[N],nans;
int main()
{
	scanf("%d",&nvec);
	int i;
	for(i=0;i<nvec;i++)
	{
		int nc,j;
		scanf("%d",&nc);
		for(j=0;j<nc;j++)
		{
			int pt;
			scanf("%d",&pt);
			edge[nedge][0]=i;
			edge[nedge][1]=pt+nvec-1;
			nedge++;
		}
	}
	for(i=0;i<nvec;i++)
	{
		int pt;
		scanf("%d",&pt);
		edge[nedge][0]=pt+nvec-1;
		edge[nedge][1]=i;
		nedge++;
		first[i]=pt+nvec-1;
	}
	nvec*=2;
	gen_scc();
	nvec/=2;
	for(i=0;i<nvec;i++)
	{
		int j,nc=nlink[i];
		nans=0;
		for(j=0;j<nc;j++)
			if(flag[link[i][j]]==flag[first[i]])
				ans[nans++]=link[i][j]-nvec+1;
		sort(ans,ans+nans);
		printf("%d",nans);
		for(j=0;j<nans;j++)printf(" %d",ans[j]);
		putchar('\n');
	}
	return 0;
}

