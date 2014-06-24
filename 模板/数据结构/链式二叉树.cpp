#include<iostream>
using namespace std;

typedef struct ntree
{
	ntree *next;
	ntree *left;
	ntree *right;
	char data;

}tnode;

typedef struct sta
{
	tnode *top;
}stack;

void push(stack *s,ntree *p)
{
	p->next=s->top;
	s->top=p;
}
void pop(stack *s)
{
	cout<<s->top->data;
	s->top=s->top->next;
}
void creat(char *tree,tnode *s,int *i,int len)
{
	tnode *p,*q;
	p=s;
	if (!s) return;
	if (tree[*i]=='-') {q=NULL;(*i)++;}
	else { 
		q=new tnode;
		q->data=tree[(*i)++];
	}
	p->left=q;	
	creat(tree,p->left,i,len);
	if (tree[*i]=='-') {q=NULL;(*i)++;}
	else 
	{q=new tnode;
	q->data=tree[(*i)++];
	}
	p->right=q;
	creat(tree,p->right,i,len);
}

void front(tnode *s)
{
	if (!s) return;
	cout<<s->data;
	tnode *p;
	p=s->left;
	front(p);
	p=s->right;
	front(p);
}

void middle(tnode *s)
{
	if (s->left) 
		middle(s->left);
	cout<<s->data;
	if (s->right) middle(s->right);
}


void bhind(tnode *s,stack *s1)
{
	if (!s) return;
	push(s1,s);
	bhind(s->right,s1);
	bhind(s->left,s1);
}


void printbhind(stack *s1)
{
	while(s1->top)
	{
		pop(s1);
	}
}


int main()
{
	stack s1;
	tnode s,*p;
	char tree[100];  
	int n,i,len,k;
	cin>>n;
	getchar();
	for(i=1;i<=n;i++)
	{
		gets(tree);
		len=(int)strlen(tree);
		if (len>0) s.data=tree[0];
		k=1;
		creat(tree,&s,&k,len);
		front(&s);
		cout<<endl;
		middle(&s);
		cout<<endl;
		s1.top=NULL;
		bhind(&s,&s1);
		printbhind(&s1);
		cout<<endl;
	}

	return 0;
}