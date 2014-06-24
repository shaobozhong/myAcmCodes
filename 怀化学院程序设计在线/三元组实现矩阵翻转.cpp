#include<iostream>
#include<algorithm>
using namespace std;

typedef struct 
{
	int col,row,data;
}Elem;

bool cmp(const Elem &a,const Elem &b)
{
	if (a.col==b.col)
	{
		return a.row<b.row;
	}
	return a.col<b.col;
}

int main()
{
	int t,co,row,n,i;
	Elem *p,*q;
	cin>>t;
	while(t--)
	{
		cin>>co>>row;
		cin>>n;
        p=new Elem[n+1];
        q=new Elem[n+1];
		for(i=0;i<n;i++)
		{
			cin>>p[i].col>>p[i].row>>p[i].data;
			q[i].col=p[i].col;
			q[i].row=row-p[i].row+1;
			q[i].data=p[i].data;
		}
		sort(q,q+n,cmp);
		for(i=0;i<n;i++)
		{
			cout<<q[i].col<<" "<<q[i].row<<" "<<q[i].data<<endl; 
		}
	}
	return 0;
}