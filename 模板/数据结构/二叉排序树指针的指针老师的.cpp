#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *left,*right;
}BitNode,*BitTree;


void insert(BitTree &T,int x)
{
	BitNode **nod=&T,*p;
	while(*nod)
	{
		if (x<(*nod)->data)
			nod=&((*nod)->left);
		else 
			nod=&((*nod)->right);
	}
	p=new BitNode;
	p->data=x;
	p->left=p->right=NULL;
	*nod=p;//nod=&p;
}
void pre(BitTree T)
{
	if (T)
	{	cout<<T->data<<" ";
		pre(T->left);
	    pre(T->right);
	}
}
void in(BitTree T)
{
	if (T)
	{
		in(T->left);
		cout<<T->data<<" ";
		in(T->right);
	}
}
void post(BitTree T)
{
	if (T)
	{
		post(T->left);
		
		post(T->right);
		cout<<T->data<<" ";
	}
}
void main()
{
	int n,i,x,k,j;
	BitTree T;
	cin>>k;
	for(j=1;j<=k;j++)
	{
		T=NULL;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		insert(T,x);
	}
	pre(T);
	cout<<endl;
	in(T);
	cout<<endl;
	post(T);
	cout<<endl;
	}
}