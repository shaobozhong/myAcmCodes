#include<iostream>
using namespace std;
int n,m,small;


typedef struct
{
	int i;
	int j;
}Ma;

typedef struct sta
{
	struct sta *next;
	int i;
	int j;
}sta;

typedef struct   
{
	sta *top; 
}stack;


void push(stack *s,sta *s1)
{
	s1->next=s->top;
	s->top=s1;
}

void pull(stack *s)
{	
	s->top=s->top->next;
}

void tshort(stack *s,Ma *end,int *ma,int i)
{
	if (s->top->i==end->i&&s->top->j==end->j||i==small) {if (small>i) small=i;return;}
	sta *s1=new sta;
	s1->i=s->top->i;
	s1->j=s->top->j;

	if (ma[(s->top->i-2)*m+s->top->j]!=1) //up
	{s1->i-=1;
	push(s,s1);
	ma[(s->top->i-1)*m+s->top->j]=1;
	tshort(s,end,ma,i+1);
	pull(s);
	ma[(s->top->i-1)*m+s->top->j]=0;
s1->i+=1;
	}
	if (ma[(s->top->i)*m+s->top->j]!=1) //down
	{s1->i+=1;
	ma[(s->top->i-1)*m+s->top->j]=1;
	push(s,s1);

	tshort(s,end,ma,i+1);
	pull(s);
	ma[(s->top->i-1)*m+s->top->j]=0;
	s1->i-=1;
	}
	if (ma[(s->top->i-1)*m+s->top->j-1]!=1) //left
	{s1->j-=1;
	ma[(s->top->i-1)*m+s->top->j]=1;
	push(s,s1);	
	tshort(s,end,ma,i+1);
	pull(s);
	ma[(s->top->i-1)*m+s->top->j]=0;
	s1->j+=1;
	}
	if (ma[(s->top->i-1)*m+s->top->j+1]!=1) //right
	{s1->j+=1;
	ma[(s->top->i-1)*m+s->top->j]=1;
	push(s,s1);
	tshort(s,end,ma,i+1);
	pull(s);
	ma[(s->top->i-1)*m+s->top->j]=0;
	s1->j-=1;
	}
	free(s1);
}


int main()
{
	stack s;
	Ma end;
	sta st;
	int *martrix;
	int i,j;
	cin>>n>>m;
	cin>>st.i>>st.j>>end.i>>end.j;
	small=n*m;
	martrix=new int[n*m+1];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>martrix[(i-1)*m+j];
	s.top=&st;
	tshort(&s,&end,martrix,0);
	cout<<small<<endl;
	return 0;
}