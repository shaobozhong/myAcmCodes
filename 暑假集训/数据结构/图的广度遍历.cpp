#include <iostream>
using namespace std;
typedef struct node
{
	int loc;
	int weight;
	struct node *next;
}Gnode;

typedef struct
{
	Gnode data[100];
	char vex[100];
	int vexnum;
}Graph;
//链队
typedef struct Lnode
{
	int data;
	struct Lnode *next;
}LNode;
typedef struct
{
	LNode *head,*real;
}LQueue;
void Init_LQ(LQueue &L)
{
	LNode *p=new LNode;
	p->next = NULL;
	L.head =L.real=p;
}

//在图的第i个链表中插入第j个字符
//边长度为x
void insert(Graph &G,int row,int col,int e)
{
	Gnode *p,*q;
	char ch,ch1;
	p=new Gnode;
	p->loc = col;
	p->weight = e;
	if(!G.data[row].next )
	{	
		p->next = NULL;
		G.data[row].next = p;
		return;
	}
	q=&G.data[row];
	ch=G.vex[col];
	while(q->next)
	{
		ch1=G.vex [q->next->loc ];
		if(ch>ch1)
			q=q->next ;
		else
			break;
	}
	p->next = q->next ;
	q->next = p;
}

//打印
void print_G(Graph G)
{
	int i;
	Gnode *p;
	for(i=1;i<=G.vexnum ;i++)
	{
		cout<<G.vex[i]<<": ";
		p=G.data[i].next ;
		while(p)
		{
			cout<<G.vex[p->loc]<<" ";
			p=p->next ;
		}
		cout<<endl;
	}
}
//进队
void EnQueue(Graph &G,LQueue &L,int x)
{
	LNode *p=new LNode;
	p->data = x;
	G.data[x].loc=1;
	p->next = NULL;
	L.real ->next = p;
	L.real = p;
}
//出队
int OutQueue(LQueue &L,Graph &G)
{
	int x;
	LNode *p=L.head;
	cout<<G.vex [p->next->data];
	//G.data[p->next->data].loc = 1;
	x=p->next->data ;
	L.head = p->next ;
	free(p);
	return x;
}
//广度优先遍历
void Bread(Graph G,int x)
{
	int i;
	int loc;
	Gnode *p;
	LQueue L;
	for(i=1;i<=G.vexnum ;i++)
		G.data[i].loc = 0;
	Init_LQ(L);
	EnQueue(G,L,x);
	//队不为空
	while(L.head!= L.real )
	{
		loc=OutQueue(L,G);
		p=G.data[loc].next ;
		while(p )
		{
			if ( G.data[p->loc].loc==0 ) EnQueue(G,L,p->loc );
			p=p->next ;
		}


	}


}
void main()
{
	int j,i,x;
	Graph G;
	freopen("pro1.in","r",stdin);
	cin>>G.vexnum ;
	getchar();
	for(i=1;i<=G.vexnum ;i++){
		cin>>G.vex [i];
		G.data[i].next = NULL;
	}
	for(i=1;i<=G.vexnum;i++)
	{
		for(j=1;j<=G.vexnum ;j++)
		{
			cin>>x;
			if(x)
			{
				insert(G,i,j,x);
			}
		}
	}
	print_G(G);
	cin>>x;
	Bread(G,x);
	


}