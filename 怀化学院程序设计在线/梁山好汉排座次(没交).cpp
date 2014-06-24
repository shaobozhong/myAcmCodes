#include<iostream>
#include<string>
using namespace std;

struct node
{
	int num;
	struct node *next;
};

struct Man
{
	string name;
	int degree;
	struct node *next;
};

	Man m[110];
	int count1;

int find1(const string &str)
{
	int i;
	for(i=0;i<count1;++i)
	{
		if (m[i].name==str) return i;
	}
	return -1;
}

void Topsort()
{
	int i;
	node *p;
	
	int count2=0;

	while(1)
	{
		for(i=0;i<count1;++i)
		{
			if (m[i].degree==0) break;
		}
		if (i==count1) break;
		++count2;
		if (count2<count1) cout<<m[i].name<<" ";
		else cout<<m[i].name<<endl;
		m[i].degree=-1;
		p=m[i].next;
		while(p)
		{
			--(m[p->num].degree);
			p=p->next;
		}

	}
}

int main()
{

	int n;
	string a,b;
	int num1,num2;
	node *q;
	while(scanf("%d",&n),n!=0)
	{
		count1=0;
		while(n--)
		{
			cin>>a>>b;
			num1=find1(a);
			if (num1==-1) {num1=count1;m[count1].degree=0;m[count1].next=NULL;m[count1++].name=a; }
			num2=find1(b);
			if (num2==-1) { num2=count1;m[count1].degree=0;m[count1].next=NULL;m[count1++].name=b;}

			q=new node;
			q->num=num2;
			++(m[num2].degree);
			q->next=m[num1].next;
			m[num1].next=q;
		}

		Topsort();
	}
	return 0;
}