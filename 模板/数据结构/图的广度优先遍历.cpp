#include<iostream>
using namespace std;

typedef struct node
{
	int loc;
	struct node *next;
	int weight;
}Node;//图的结点

typedef struct 
{
	Node *next;
	char sign;
	int loc;
	char lable;
}Graph;//图

typedef struct Lnode
{
	struct Lnode *next;
	int loc;
}LLnode;//链队的结点

typedef struct 
{
	LLnode *head,*tail;
}Lqueque;//链队

void insert(Graph *G,int i,int j,int num)// 插入图结点
{
	Node *p=G[i].next,*q;
	q=new Node;
	q->loc=j;
	q->weight=num;
	if (!G[i].next||G[j].sign<G[p->loc].sign)
	{
		q->next=p;
		G[i].next=q;
		return;
	}
	while(p->next)
	{
		if (G[j].sign<G[p->next->loc].sign)
			break;
		p=p->next;
	}
	q->next=p->next;
	p->next=q;
}

void en_que(Graph *G,Lqueque &L,int i)
{
	LLnode *p=new LLnode;
	p->loc=i;
	p->next=NULL;
	L.tail->next=p;
	L.tail=p;
	G[i].lable='1';
}

int out(Graph *G,Lqueque &L)
{
	LLnode *p=L.head;
	cout<<G[p->next->loc].sign<<" ";
	L.head=p->next;
	return p->next->loc;
	free(p);
}
void broad(Graph *G,Lqueque &L)
{
	char ch;
	int num,loc;
	Node *p;
	cin>>ch;
	for(num=1;num<=G[0].loc;num++)
	{
       if (G[num].sign==ch) break;
	}
	en_que(G,L,num);
	while(L.head!=L.tail)
	{
		loc=out(G,L);
		p=G[loc].next;
		while(p)
		{
			if (G[p->loc].lable=='0') en_que(G,L,p->loc);
			p=p->next;
		}
	}
}

int main()
{
	Lqueque Lq;
	Node *p;
	Graph *G;
	int n,i,j,num;
	cin>>n;
	if (n)
	{
		G= new Graph[n+1];
		G[0].loc=0;
		for(i=1;i<=n;i++)
		{
			G[i].next=NULL;
			G[i].lable='0';
		}
		getchar();
		for(i=1;i<=n;i++)
		{
			cin>>G[i].sign;
			G[i].loc=0;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				cin>>num;
				if (num)
				{
					G[0].loc++;
					insert(G,i,j,num);
				}
			}
		}
	/*	for(i=1;i<=n;i++)
		{
			cout<<G[i].sign<<":";
			p=G[i].next;
			while(p)
			{
				cout<<p->loc<<" ";
				p=p->next;
			}
			cout<<endl;
		}*/
			Lq.head=Lq.tail=new LLnode;//初始化链队
			broad(G,Lq); 
		
	}
	return 0;
}