#include<iostream>
using namespace std;
#define M 100

typedef struct
{
	int top;
	char data[M];
}mystack;

void push(mystack *s,char x)
{
	if (s->top==M) 
	{
		cout<<"overflow!";return;
	}
	s->data[s->top++]=x;
}

void pull(mystack *s)
{
	if (s->top==0)
	{
		cout<<"underflow!";return;
	}
	s->top--;
}

int main()
{
	int n,i;
	char x;
	mystack s;
	
	cin>>n;
	getchar();
	for(i=1;i<=n;i++)
	{s.top=0;
		while(x=getchar(),x!='\n')
		{
			if (s.top>0&&((int)x-(int)s.data[s.top-1]==2||(int)x-(int)s.data[s.top-1]==1)) pull(&s);
			else push(&s,x);
		}
		
		if (s.top==0) cout<<"YES"<<endl;
		else 
		{
			cout<<"NO"<<endl;
			
		}
	}
	return 0;
}
