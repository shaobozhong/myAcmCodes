#include<iostream>
using namespace std;

typedef struct node
{

	int weight;
	int loc;
	struct node *next;

}Node;
typedef struct 
{
	int fee;
	Node *next;
	int degree;
	bool la;
}citys;

void the_least(citys *city,int n)
{
	int i,loc,temp=0;
	Node *p;
	loc=1;
	while(loc)
	{
		loc=0;
		for(i=1;i<=n;i++)
		{
			if (city[i].degree==0)
			{
				p=city[i].next;
				loc=i;
				city[i].degree=temp-1;
			
				while(p)
				{
					if (city[p->loc].fee>city[i].fee+p->weight)
					{
						city[p->loc].fee=city[i].fee+p->weight;
					}
					if (city[i].la) city[p->loc].degree--;
					p=p->next;
				}
		    temp=0;	
			city[i].la=false;
			}
			
		}
		if (i>n)
		{
			for(i=1;i<=n;i++)
			{
				if (city[i].la)
				{
					//p=city[i].next;
					loc=i;
					temp=city[i].degree--;
					city[i].la=false;
					/*city[i].la=false;
					while(p)
					{
						if (city[p->loc].fee>city[i].fee+p->weight)
						{
							city[p->loc].fee=city[i].fee+p->weight;
						}
						city[p->loc].degree--;
						p=p->next;
					}*/
					break;
				}
			}
		}
	}
}


int main()
{
	citys *city;
	Node *q;
	int t,n,b,l,s,e,k,m,i;
	cin>>t;
	for(;t>=1;t--)
	{
		cin>>n>>b>>l;
		city=new citys[n+1];
		for(i=1;i<=n;i++)
		{
			city[i].next=NULL;
			city[i].degree=0;
			city[i].fee=10000;
			city[i].la=true;

		}
		for(i=1;i<=l;i++)
		{
			cin>>s>>e>>k>>m;
			q=new Node;
			q->loc=e;
			if (k==0)q->weight=-1*m;
			else q->weight=m;
			q->next=city[s].next;
			city[s].next=q;
			city[e].degree++;
		}
		city[1].fee=0;
		the_least(city,n);
		if (city[b].fee<10000) cout<<city[b].fee<<endl;
		else cout<<"impossible"<<endl;
	}
	return 0;
}