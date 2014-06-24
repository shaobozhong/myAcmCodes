#include<iostream>
using namespace std;
int max1,n;
typedef struct node
{
	int lable;
	int weight;
	struct node  *next;
}kids;

typedef struct 
{
	kids *next;
	int in;
	int weight;
	char data;
}Graph;

void work1(Graph *g)
{
	int i;
	bool la;
	kids *p;
	la=false;
	for(i=1;i<=n;++i)
		{
			if (g[i].in==0) {la=true;break;}
		}
	while(la)
	{
		la=false;
		g[i].in=-1;
		p=g[i].next;
		while(p)
		{
			if (g[p->lable].weight<g[i].weight+p->weight) 
			{
				g[p->lable].weight=g[i].weight+p->weight;
			}
			g[p->lable].in--;
			p=p->next;
		}
		for(i=1;i<=n;++i)
		{
			if (g[i].in==0) {la=true;break;}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(max1<g[i].weight) max1=g[i].weight;
	}
}


void work2(Graph *r)
{
    int i;
	bool la;
	kids *p;
	la=false;
	for(i=1;i<=n;i++)
	{
		if (r[i].in==0) break;
	}
	r[i].weight=max1;
	la=true;
	while(la)
	{
		la=false;
		p=r[i].next;
		r[i].in=-1;
		while(p)
		{
			if (r[p->lable].weight==-1||r[p->lable].weight>r[i].weight-p->weight) 
			{
				r[p->lable].weight=r[i].weight-p->weight;
			}
			r[p->lable].in--;
			p=p->next;
		}
		for(i=1;i<=n;i++)
		{
			if (r[i].in==0) { la=true; break;}
		}
	}
}


void res(Graph *g,Graph *r)
{
	int i;
	
	for(i=1;i<=n;i++)
	{
		if (r[i].weight==g[i].weight) printf("%c ",g[i].data);
	}
	cout<<endl;
}
int main()
{
	Graph *g,*r;
	kids *p;
	int t,i,j,num;
	cin>>t;
	while(t--)
	{
		max1=0;
		cin>>n;
		g=new Graph[n+1];
		r=new Graph[n+1];
		for(i=1;i<=n;i++)
		{
			cin>>g[i].data;
			g[i].next=NULL;
			g[i].in=0;
			g[i].weight=0;
			r[i].data=g[i].data;
			r[i].in=0;
			r[i].next=NULL;
			r[i].weight=-1;
		}

		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				cin>>num;
				if (num)
				{
					p=new kids;
					p->next=g[i].next;
					p->weight=num;
					p->lable=j;
					g[i].next=p;
					g[j].in++;

					p=new kids;
					p->next=r[j].next;
					p->weight=num;
					p->lable=i;
					r[j].next=p;
					r[i].in++;
				}
			}
		}
		work1(g);
		work2(r);
		res(g,r);
	}
}