#include<iostream>
#include<queue>
using namespace std;

struct Edge{
	int num;
	int value;
	struct Edge *next;
}edge[100];

int n,b,l;
bool flag[25];
int times[25];
int d[25];
queue<int> r;

int spfa(){
	Edge *t;
	int i,cur,f=1;
	memset(times,0,sizeof(int)*(n+1));
	memset(flag,true,sizeof(bool)*(n+1));
	i=l+1;
	while(i--)
		d[i]=0x7fffffff;
	d[1]=0;
	flag[1]=false;
	r.push(1);
	while(!r.empty()){
		cur=r.front();r.pop();
		for(t=edge[cur].next;t!=NULL;t=t->next){
			if (d[t->num] > d[cur]+t->value){
					d[t->num] = d[cur]+t->value;
					times[t->num]=times[cur]+1;
					if (times[t->num]>l){ 
						f = 1;
						break;
					}
					if (flag[t->num]==true){
						r.push(t->num);
						flag[t->num]=false;
					}
			}
		}
		if(!f){
			f = 0;
			flag[cur]=true;
		}else
			f = 0;
	}
	return d[b];
}

int main(){
	int i,t,s,e,k,m;
	scanf("%d",&t);
	while(t--){
		Edge *p;
		scanf("%d %d %d",&n,&b,&l);
		for(i=1;i<=l;i++)
			edge[i].next=NULL;
		for(i=0;i<n;i++){
			scanf("%d %d %d %d",&s,&e,&k,&m);
			p=new struct Edge;
			p->next=NULL;
			p->num=e;
			if(k==0)
				p->value=-m;
			else
				p->value=m;
			p->next=edge[s].next;
			edge[s].next=p;
		}
		printf("%d\n",spfa());
		while(!r.empty()) r.pop();
	}
	return 0;
} 
