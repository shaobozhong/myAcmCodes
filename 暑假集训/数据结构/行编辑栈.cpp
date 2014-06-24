#include<iostream>
#include<string.h> 
using namespace std;
#define M 100


typedef struct
{
  int top;
  char data[M];
}stack;

void push(stack *s,char x)
{
	if (s->top==M) 
	{
		cout<<"overflow!"<<endl;
        return;
	}
	s->data[s->top++]=x;
}

void pull(stack *s)
{
	if (s->top==0)
	{
		cout<<"underflow!"<<endl;
        return;
	}
	s->top--;
}

void pri(stack s)
{
	int i;
	for(i=0;i<=s.top;i++)
		cout<<s.data[i];	
}
int main()
{
    stack s;
	int i;
    char sd[100];
	s.top=0;
	while(gets(sd))
	{
		
       for(i=0;i<=(int)strlen(sd)-1;i++)
	   {
		   if (sd[i]=='#'&&s.top>0) pull(&s);
		   else if(sd[i]=='@'&&s.top>0)
		   {
			   while(s.top>0&&s.data[s.top-1]!= ' '&&s.data[s.top-1]!='\n')
				   pull(&s);
		   }
		   else push(&s,sd[i]);
	   }
	   push(&s,10);
	   
	}pri(s);
	
	return 0;
}