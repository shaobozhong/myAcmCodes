#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *left,*right;
	struct node *next;
}tree,*Btree;

void insert(Btree &T,int x)
{
   tree **p=&T,*q;
   while(*p)
   {
	   if (x<(*p)->data)
		   p=&((*p)->left);
	   else 
		   p=&((*p)->right);
   }
   q=new tree;
   q->data=x;
   q->left=q->right=NULL;
   *p=q;
}
void pre(Btree &T)
{
	if (T)
	{
		cout<<T->data<<" ";
		pre(T->left);		
		pre(T->right);
	}
}
void in(Btree &T)
{
	if (T)
	{
		in(T->left);
		cout<<T->data<<" ";
		in(T->right);
	}
}
void post(Btree &T)
{
	if (T)
	{
		post(T->left);
		post(T->right);
		cout<<T->data<<" ";
	}
}
int main()
{
	Btree T;
    int n,k,x;
	cin>>k;
	for(;k>=1;k--)
	{
		T=NULL;
		cin>>n;
		for(;n>=1;n--)
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
	return 0;
}