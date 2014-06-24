#include<iostream>
using namespace std;
int co[100];
typedef struct node
{
	int data;
	char ch;
	struct node *left,*right;
	struct node *next;
}Bnode;
//插入未进行哈夫曼算法时的结点
void insert(Bnode *L,char ch,int num)
{
	Bnode *p,*q;
    p=L;
    while(p->next)
	{
      if (num>=p->next->data)
		  p=p->next;
	  else break;
	}
	q=new Bnode;
	q->data=num;
	q->ch=ch;
	q->left = q->right = NULL;
	q->next=p->next;
    p->next=q;
}

void print(Bnode *L)
{
	Bnode *p=L->next;
  while(p)
  {
	  cout<<p->data<<" "<<p->ch <<endl;
	  p=p->next;
  }
}
//插入结点
void insert_nod(Bnode *L,Bnode *q)
{
	Bnode *p;
    p=L;
    while(p->next)
	{
      if (q->data>=p->next->data)
		  p=p->next;
	  else break;
	}
	q->next = p->next ;
	p->next = q;
}
//先序遍历
void pre(Bnode *L)
{
	if(L)
	{
		cout<<L->data<<" ";
		pre(L->left);
		pre(L->right );
	}
}
//编码
void code(Bnode *L,int i)
{
	int j;
	if (!L->left&&!L->right) 
	{
		//cout<<L->ch<<":";
		for(j=0;j<=i-1;j++)
			cout<<co[j];
		cout<<endl;
	}
	
	if (L->left)
		{
			co[i]=0;
			code(L->left,i+1);
		}
		if (L->right)
		{
			co[i]=1;
			code(L->right,i+1);
		}
    
	
}
void main()
{
	FILE *fp;
	int n,i;
	char ch,*charra;
	int *numarra;
	Bnode *p1,*p2,*q;
	Bnode *L=new Bnode;
	L->data=0;
	L->next=NULL;
	
	while(scanf("%d",&n)+1)
	{
		scanf("%c",&ch);
	charra=new char[n];
	numarra=new int[n];
	for(i=0;i<n;i++)
	{
		scanf("%c",&charra[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&numarra[i]);
	}
	for(i=0;i<n;i++)
	{
		insert(L,charra[i],numarra[i]);
	}
	print(L);
	for(i=1;i<n;i++)
	{
		p1=L->next ;
		p2=p1->next ;
		L->next = p2->next ;
		q=new Bnode;
		q->left = p1;
		q->right = p2;
		q->data = p1->data +p2->data;
		q->next = NULL;
		insert_nod(L,q);
	}
	pre(L->next);
	cout<<endl;
	code(L->next,0);
	}	
}