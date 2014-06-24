#include<iostream>
using namespace std;
#define M 100
typedef struct
{
	int top;
	double data[M];
}stack;
typedef struct
{
	int top;
	char data[M];
}stack1;

void push(stack *s,double x)
{
	if (s->top==M) return;
	s->data[s->top++]=x;
}
void push1(stack1 *s,char x)
{
	if (s->top==M) return;
	s->data[s->top++]=x;
}
char pull1(stack1 *s)
{
	char x=0;
	if (s->top==0) return x;
	x=s->data[s->top-1];
	s->top--;
	return x;
}

double pull(stack *s)
{
	double x=0;
	if (s->top==0) return x;
	x=s->data[s->top-1];
	s->top--;
	return x;
}

double calc(double a,char x,double b)
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

bool panduan(char x,char y)
{
	if ((y=='+'||y=='-')&&(x=='*'||x=='/')) return true;
	return false;

}

int main()
{
	stack s1;stack1 s2;

	int n,i,j,k,temp,t;
	double num;
	char str[100];
	cin>>n;
	getchar();
	for(i=1;i<=n;i++)
	{s1.top=0;
	s2.top=0;
	gets(str);
	for(j=0;j<=(int)strlen(str)-1;j++)
	{
		if (str[j]>=48&&str[j]<=57) 
		{
			num=0;
			k=j;
			while(str[k+1]>=48&&str[k+1]<=57) k++;
			temp=k;
			t=1;
			for(;k>=j;k--)
			{
				num+=((int)str[k]-48)*t;
				t*=10;
			}
			j=temp;
			push(&s1,num);
		}
		else if (s2.top>0&&panduan(str[j],s2.data[s2.top-1])) push1(&s2,str[j]); 
		else 
		{
			while(s2.top>0&&!panduan(str[j],s2.data[s2.top-1])) 
			{
				int j,k;
				j=pull(&s1);
				k=pull(&s1);
				push(&s1,calc(k,pull1(&s2),j));
			}
			push1(&s2,str[j]);
		}
	}
	while(s1.top!=1)
	{
		int j,k;
		j=pull(&s1);
		k=pull(&s1);
		push(&s1,calc(k,pull1(&s2),j));
	}
	cout<<s1.data[s1.top-1]<<endl;

	}

	return 0;
}