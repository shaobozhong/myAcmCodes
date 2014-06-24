#include<iostream>
using namespace std;


typedef struct node
{
	struct node *left,*right;
	int data;
}tree,*ntree;

void insert(tree *t,int x)
{
	tree *p,*q,*r;
	p=t;
	q=new tree;
	q->data=x;
	q->left=q->right=NULL;
	while(p)
	{
		if (x<p->data)
		{
			r=p;
			p=p->left;
		}
		else 
		{
			r=p;
			p=p->right;
		}
	}
	if (x<r->data) r->left=q;
	else r->right=q;
}
void pre(tree *t)
{
	if (t)
	{	cout<<t->data<<" ";
		pre(t->left);
		pre(t->right);
	}
}
void in(tree *t)
{
	if (t)
	{
		in(t->left);
		cout<<t->data<<" ";
		in(t->right);
	}
}
void post(tree *t)
{
	if (t)
	{
		post(t->left);
		post(t->right);
		cout<<t->data<<" ";
	}
}
	
int main()
{
	tree *t;
	int n,x,i,k,j;
	cin>>k;
	for(j=1;j<=k;j++)
	{
	t=NULL;
	cin>>n;
	if (n>=1) 
	{
		cin>>x;
     t=new tree;
	 t->data=x;
	 t->right=t->left=NULL;
	}
	for(i=2;i<=n;i++)
	{
		cin>>x;
		insert(t,x);
	}
	pre(t);
	cout<<endl;
	in(t);
	cout<<endl;
	post(t);
	cout<<endl;
	}
}