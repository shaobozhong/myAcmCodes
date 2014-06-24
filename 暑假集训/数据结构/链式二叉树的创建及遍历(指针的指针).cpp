#include<iostream>
using namespace std;
typedef struct node
{
  char ch;
  struct node *left,*right;
}bitnode;
void creat(bitnode *t)
{
	char ch;
    scanf("%c",&ch);
    if(ch=='-') t->ch=0;
	else
	{ 
	t->ch=ch; 
	t->left=new bitnode; 
	creat(t->left);
    t->right=new bitnode;	
	creat(t->right);
	}
}
void pre(bitnode *t)
{
  if(t->ch!=0)
  {
    cout<<t->ch;
    pre(t->left);
	pre(t->right);
  }
}
void in(bitnode *t)
{
  if(t->ch!=0)
  {
   
    in(t->left); 
	cout<<t->ch;
	in(t->right);
  }
}
void post(bitnode *t)
{
  if(t->ch!=0)
  {
    post(t->left); 
    post(t->right);
	cout<<t->ch;
  }
}


void main()
{
   int n,i;
  
   bitnode T;
   scanf("%d",&n);  
  
   for(i=0;i<n;i++)
   {
	    getchar();
   creat(&T);
   pre(&T);
   cout<<endl;
   in(&T);
   cout<<endl;
   post(&T);
   cout<<endl;
   }
}
