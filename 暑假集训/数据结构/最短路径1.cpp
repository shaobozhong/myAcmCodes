#include<iostream>
using namespace std;

typedef struct node 
{
	struct node *next;
	int weight;
	int loc;
}Gnode;

typedef struct 
{
	Gnode *next;
	int distance;
	char sign;
	int degree;
}Graph;

void insert(Graph *G,int weight,int n,int i,int j)
{
	Gnode *p;
	p=new Gnode;
	p->loc=j;
	p->weight=weight;
	p->next=G[i].next;
	G[i].next=p;
}


void shortroad(Graph *G,int n,int loc)
{
	int i;

	Gnode *p;
	while(loc)
	{
		loc=0;
		for(i=1;i<=n;i++)
		{
			if (G[i].degree==0) 
			{
				G[i].degree--;
				p=G[i].next;
				while(p)
				{
					if (G[p->loc].distance>G[i].distance+p->weight)
					{
						G[p->loc].distance=G[i].distance+p->weight;
						
					}
					G[p->loc].degree--;
					p=p->next;
				}
				loc=i;
			}
		}
	}
}

void print(Graph *G,int n)
{
	Gnode *p;
	int i;
	for(i=1;i<=n;i++)
	{
		cout<<G[i].sign<<":";
		p=G[i].next;
		while(p)
		{
			cout<<p->loc<<G[p->loc].sign<<" ";
			p=p->next;
		}
	}
}
void shortprint(Graph *G,int n,int loc)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if (i!=loc)
		{
			if (G[i].distance==10000) G[i].distance=0;
		    cout<<G[i].sign<<": "<<G[i].distance<<endl;
		}
	}
}
int main()
{
	Graph *G;
	char ch;
	int i,n,j,weight;
	char s[100];
	cin>>s;
	n=(int)strlen(s);
	G=new Graph[n+1];
	for(i=1;i<=n;i++)
	{
		G[i].degree=0;
		G[i].distance=10000;
		G[i].next=NULL;
		G[i].sign=s[i-1];
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>weight;
			if (weight)
			{
				G[j].degree++;
				insert(G,weight,n,i,j);
			}
		}
	}
	//print(G,n);//¥Ú”°Õº
	//cout<<endl;
	cin>>ch;
	for(i=1;i<=n;i++)
	{
		if (ch==G[i].sign) break;
	}
	G[i].distance=0;

    shortroad(G,n,i);
	shortprint(G,n,i);
	return 0;
}

