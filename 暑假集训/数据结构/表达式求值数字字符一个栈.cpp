#include<iostream>
using namespace std;
#define M 100

typedef struct
{
	int data[M];
	char f[M];
	int top;
}stack;

void push(stack *s,char x)
{
	if (s->top==M) return;
	s->f[s->top++]=x;
}

bool panduan(char x,char y)
{
	if ((y=='+'||y=='-')&&(x=='*'||x=='/')) return true;
	return false;

}
int calc(int a,char x,int b)
{
	switch(x)
	{
	case '+':return (a+b);
	case '-':return (a-b);
	case '*':return (a*b);
	default:return (a/b);
	}
	return 0;
}

int main()
{
	stack s;
	int n,i,temp;
	char x;
	cin>>n;

	for(i=1;i<=n;i++)
	{
		s.top=0;
		cin>>s.data[0];
		while(scanf("%c",&x),x!='\n')
		{
			if (s.top>0&&panduan(x,s.f[s.top-1])) push(&s,x); 
			else if (s.top>0) 
			{
				while(s.top>0&&!panduan(x,s.f[s.top-1]))
				{
					s.data[s.top-1]=calc(s.data[s.top-1],s.f[s.top-1],s.data[s.top]);
					s.top--;
				}
				push(&s,x);
			}
			else push(&s,x);
			cin>>s.data[s.top];
		}
		while(s.top)
		{
			s.data[s.top-1]=calc(s.data[s.top-1],s.f[s.top-1],s.data[s.top]);
			s.top--;
		}
       cout<<s.data[s.top]<<endl;
	}
	return 0;
}