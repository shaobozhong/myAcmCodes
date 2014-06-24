#include<iostream>
using namespace std;

int father[30001],sata[30001],child[30001];

int findf(int x)
{
	while(x!=father[x])
	{
		x=father[x];
	}
	return x;
}

int findc(int x)
{
  while(x!=child[x])
  {
	  x=child[x];
  }
  return x;
}

void move()
{
	int a,b,t2,t1;
	cin>>a>>b;
	t1=findc(a);
	t2=findf(b);
	father[t2]=t1;
	child[t1]=t2;
	sata[t1]+=sata[t2]+1;
	while(t1!=father[t1])
	{	
		t1=father[t1];
		sata[t1]+=sata[t2]+1;
	}
}

void count()
{
	int x;
	cin>>x;
	cout<<sata[x]<<endl;
}

int main()
{
	char op;
    int i,p;
	while(cin>>p)
	{
		for(i=1;i<=30000;i++)
		{
			child[i]=i;
			father[i]=i;
			sata[i]=0;
		}
		while(p--)
		{
           cin>>op;
		   if (op=='M') move();
		   else count();
		} 
	}
	return 0;
}