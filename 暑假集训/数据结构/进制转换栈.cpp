#include<iostream>
using namespace std;
#define M 100

typedef struct
{
 int data[M];
 int top;
}mystack;



void push(mystack *s,int n)
{
	if (s->top==M) {cout<<"overflow!"<<endl;return;}
	s->data[s->top++]=n;
	
}

void pull(mystack *s)
{
	if (s->top==0) {cout<<"underflow!";return;}
	s->top--;
	cout<<s->data[s->top];
}

int main()
{
    int k,n,m;
	mystack s;
	s.top=0;
	cin>>k>>m;
	for(int i=1;i<=k;i++)
	{
	cin >>n;
	while(n)
	{
		push(&s,n%m);
		n/=m;
	}
	while(s.top)
	{
		pull(&s);
	}
	cout<<endl;
	}
	return 0;
}