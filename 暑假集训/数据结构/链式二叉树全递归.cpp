#include<iostream>
using namespace std;

typedef struct node
{
	struct node *left;
	struct node *right;
	char data;
}tree;

void creat(tree *t,int *i,char *s)
{
	tree *p;
	if (!t) return;
	if (s[*i]=='-') { p=NULL;(*i)++;}
	else 
	{
		p=new tree;
		p->data=s[(*i)++];
	}
	t->left=p;
	creat(p,i,s);
	if (s[*i]=='-') {p=NULL;(*i)++;}
	else 
	{
		p=new tree;
		p->data=s[(*i)++];
	}
	t->right=p;
	creat(p,i,s);
}


void pre(tree *t)
{
	if (!t) return;
    cout<<t->data;
	pre(t->left);
	pre(t->right);
}

void in(tree *t)
{
	if (!t) return;
   in(t->left); 
	cout<<t->data;
	in(t->right);
}

void post(tree *t)
{
	if (!t) return;
    post(t->left);
	post(t->right); 
	cout<<t->data;
}
int main()
{
	tree *t;
	char s[100];
	int n,i,k,len;
	cin>>n;
	for(i=1;i<=n;i++)
	{t=NULL;
		cin>>s;
		len=(int)strlen(s);
		if (len>0)
		{
			t=new tree;
			t->data=s[0];
			k=1;
			creat(t,&k,s);
		    pre(t);
			cout<<endl;
			in(t);
			cout<<endl;
			post(t);
			cout<<endl;
		}
	}
	return 0;
}