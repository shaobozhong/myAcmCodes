#include<iostream>
using namespace std;

typedef struct node
{
  char ch; 
  struct node *left,*right;
}Tnode,*PTnode;

void pre_in(PTnode &T,int k,int left,int right,char *pre,char *in)
{
	int i;
	T=new Tnode;
	T->ch=pre[k];
	T->left=T->right=NULL;
	for(i=left;i<=right;i++)
	{
		if (in[i]==pre[k]) break;
	}
	if (i!=left)
	{
		pre_in(T->left,k+1,left,i-1,pre,in);
	}
    if(i<right) 
	{
		pre_in(T->right,k+i+1-left,i+1,right,pre,in);
	}
}

void post_in(PTnode &T,int k,int left,int right,char *post,char *in)
{
	int i;
	T=new Tnode;
	T->ch=post[k];
	T->left=T->right=NULL;
	for(i=left;i<=right;i++)
	{
		if (in[i]==post[k]) break;
	}
  if (i!=left)
	{
		post_in(T->left,k-right+i-1,left,i-1,post,in);
	}
    if(i<right) 
	{
		post_in(T->right,k-1,i+1,right,post,in);
	}
}

void prin1(PTnode &T)
{
	if (T)
	{
		prin1(T->left);
		prin1(T->right);
		cout<<T->ch;
	}
}

void prin2(PTnode &T)
{
	if (T)
	{
		cout<<T->ch;
		prin2(T->left);
		prin2(T->right);
	}
}

int main()
{
	PTnode T;
	char pre[100],in[100],post[100],order[5];
    int n,i,len;
	bool pr;
	cin>>n;
	getchar();
	for(;n>=1;n--)
	{
		pr=false;
      for(i=1;i<=2;i++)
	  {
		  gets(order);
		  if (strcmp(order,"in")==0) gets(in);
		  else if (strcmp(order,"pre")==0){gets(pre);pr=true;}
		  else gets(post);   
	  }
		  if (pr)
		  {
			  len=(int)strlen(pre);
			  if(len) 
			  {
			   pre_in(T,0,0,len-1,pre,in); 
			   cout<<"post: ";
			   prin1(T);
			   cout<<endl;
			  }
		  }
		  else
		  {
			  len=(int)strlen(post);
			  if (len) 
			  {
				  post_in(T,len-1,0,len-1,post,in);
				  cout<<"pre: ";
			      prin2(T);
				  cout<<endl;
			  }
		  }
	}
	return 0;
}