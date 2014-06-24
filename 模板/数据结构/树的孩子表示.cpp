#include<iostream>
using namespace std;
#define M 20

typedef struct child
{
	int data; 
	child *next;
}children;//元素孩子地址结点


typedef struct
{
	children *next;
	char data[M];
}node;//元素结点




void creat(node *elem,int n)//建立关于孩子表示法的链表
{
	int i;
	for(i=1;i<=n;i++)
	{
		cin>>elem[i].data;
		elem[i].next=NULL;
	}
}

int find(char *kid,node *elem,int n)//查找元素的位置
{
	int i;
	for(i=1;i<=n;i++)
		if (strcmp(elem[i].data,kid)==0) return i;
	return 0;
}


void print(node *elem,int n)  //输出各元素的孩子的地址
{
	int i;
	children *p;
	for(i=1;i<=n;i++)
	{
		cout<<elem[i].data<<" ";
		p=elem[i].next;
		while(p)
		{
			cout<<p->data<<" ";
			p=p->next;
		}
		cout<<endl;
	}
}

int findfather(int loc, node *elem,int n)
{
	children *p;
	int i;
  for(i=1;i<=n;i++)
  {
    p=elem[i].next;
	while(p)
	{
		if (p->data==loc) return i;
		p=p->next;
	}
  }
  return 0;
}

bool find_ancestors(char *kid ,node *elem,int n)
{
	int loc,zu;
	cout<<kid<<": ";
	loc=find(kid,elem,n);
	zu=findfather(loc,elem,n);
	if (zu)
	{
		while(zu)
		{
			cout<<elem[zu].data<<" ";
			zu=findfather(zu,elem,n);
		}
		cout<<endl;
		return false;
	}
    return true;
}

int main()
{
	char kid[M];
	node *elem;
	children *p,*q;
	int n,loc,i,num,j;
	while(scanf("%d",&n)+1)
	{
		elem=new node[n+1];

		for(i=1;i<=n;i++)
		{
			cin>>elem[i].data;
			elem[i].next=NULL;
		}
		for(i=1;i<=n;i++)
		{
			cin>>kid;
			loc=find(kid,elem,n);
			cin>>num;
			if (num>0)
			{
				q=new children;
				elem[loc].next=q;
				cin>>kid;
				q->data=find(kid,elem,n);
				p=q;
				for(j=2;j<=num;j++)
				{   
					q=new children;
					p->next=q;
					cin>>kid;
					q->data=find(kid,elem,n);
					p=q;
				}
				q->next=NULL;
			}
		}
		//print(elem,n);
		cin>>num;
		for(i=1;i<=num;i++)
		{
			cin>>kid;
			if (find_ancestors(kid,elem,n)) 
				cout<<"no progenitor!"<<endl;
			
		}
     
	}
	return 0;
}