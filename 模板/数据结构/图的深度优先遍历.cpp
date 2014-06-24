#include<iostream>
using namespace std;

typedef struct node 
{
	struct node *next;
	int loc;
}Node;
typedef struct
{
	Node *next;
	char sign;
    char lable;
}Graph;

void insert(Graph *G,int i,int j)
{
	Node *p=G[i].next,*q;
    q=new Node;
	q->loc=j;
	if (!p||(p&&G[j].sign<G[p->loc].sign))
	{
		G[i].next=q;
		q->next=p;
		return;
	}
	while(p->next)
	{
		if (G[j].sign<G[p->next->loc].sign)  break;
		p=p->next;
	}
	q->next=p->next;
	p->next=q;
}

void deep(Graph *G,int n,int loc)//深度遍历
{
	Node *p;
	if (G[loc].lable=='0')
	{
	cout<<G[loc].sign<<" ";
	G[loc].lable='1';
	p=G[loc].next;
	while(p)
	{
		deep(G,n,p->loc);
		p=p->next;
	}
	}
}

void print(Graph *G,int n)
{
	Node *p;
	int i;
	for(i=1;i<=n;i++)
	{
		p=G[i].next;
		cout<<G[i].sign<<":";
		while(p)
		{
			cout<<p->loc<<" ";
			p=p->next;
		}
	}

}
int main()
{
	Graph *G;
	int n,i,j,num;
	char ch;
    cin>>n;
	getchar();
	G=new Graph[n+1];
	for(i=1;i<=n;i++)
	{
		cin>>G[i].sign;
		G[i].next=NULL;
		G[i].lable='0';
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>num;
			if (num)
			{
				insert(G,i,j);
			}
		}
	}
	cin>>ch;//寻找开始点的坐标
	for(num=1;num<=n;num++)
	{
		if (G[num].sign==ch) break;
	}
//print(G,n);
deep(G,n,num);
cout<<endl;
	return 0;
}