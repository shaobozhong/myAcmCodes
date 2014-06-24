#include<iostream>
using namespace std;

char s[100];
typedef struct node 
{
	struct node *next;
	int loc;
	int weight;
}Node;

typedef struct
{
	Node *next;
	int distance;
	int degree;
}Graph;

void insert(Graph *G,int i,int j,int weight)
{
	Node *q;
	q=new Node;
	q->weight=weight;
	q->loc=j;
	q->next=G[i].next;
	G[i].next=q;
	G[j].degree++;
}

void print(Graph *G,int len)
{
	Node *p;
	int i;
	for(i=0;i<=len-1;i++)
	{
		cout<<s[i]<<" :";
		p=G[i].next;
		while(p)
		{
			cout<<p->loc<<" ";
			p=p->next;
		}
	}
}

void longroad(Graph *G,int loc,int len)
{
	Node *p;
	int i;
	if (loc<0||loc>len-1) return; 
	loc=1;
	while(loc)
	{
		loc=0;
		for(i=0;i<=len-1;i++)
		{
			if (G[i].degree==0)
			{
				loc=1;
				G[i].degree--;
				p=G[i].next;
				while(p)
				{
					if (G[p->loc].distance<G[i].distance+p->weight) 
						G[p->loc].distance=G[i].distance+p->weight;
					G[p->loc].degree--;
					p=p->next;
				}
			}
		}
	}

}

int main()
{
	Graph *G;
	char st,en;
	int n,len,i,j,weight,sta,end;
	cin>>n;
	getchar();
	for(;n>=1;n--)
	{
		cin>>s;
		len=(int)strlen(s);
		G=new Graph[len];
		for(i=0;i<len;i++)
		{
			G[i].degree=0;
			G[i].distance=0;
			G[i].next=NULL;
		}
		for(i=0;i<=len-1;i++)
		{
			for(j=0;j<=len-1;j++)
			{
				cin>>weight;
				if (weight) insert(G,i,j,weight);
			}
		}
		//print(G,len);
		cin>>st>>en;
		for(i=0;i<=len-1;i++)
		{
			if (s[i]==st) sta=i;
			if (s[i]==en) end=i;
		}
		G[sta].distance=100;
		longroad(G,sta+1,len);
		if (G[end].distance!=0) cout<<G[end].distance-100<<endl;
		else cout<<G[end].distance<<endl;
	}
	return 0;
}