#include<iostream>
using namespace std;
#define M 100

typedef struct
{
	int head;
	int tail;
	int *data;
}stack;

void push(stack *s,int num,int n)
{
	if ((s->tail+1)%n==s->head)
	{
		//cout<<"队满"<<endl;
			return;
	}
	s->data[s->tail]=num;
	s->tail=(s->tail+1)%n;
}

void pop(stack *s,int n)
{
	if (s->head==s->tail)
	{
            //cout<<"队空！"<<endl;
			return;
	}
	s->head=(s->head+1)%n;
}
void pop1(stack *s,int n)
{
	if (s->head==s->tail)
	{
            //cout<<"队空！"<<endl;
			return;
	}
	cout<<s->data[s->head]<<" ";
	s->head=(s->head+1)%n;
}
int main()
{
	stack s;
char str[100];
	int n,m,i,num;
	s.head=s.tail=0;
	cin>>n>>m;
	s.data=new int[n+1];//也可以直接用数组去做
	for(i=1;i<=m;i++)
	{
		cin>>str;
		if (!strcmp(str,"in")) 
		{
			cin>>num;
			push(&s,num,n);
		}
		if (!strcmp(str,"out")) 
			pop(&s,n);
	}
	while(s.head!=s.tail)
	{
		pop1(&s,n);
	}
	cout<<endl;
	return 0;
}