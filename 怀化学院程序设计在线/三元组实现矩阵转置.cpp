#include<iostream>
using namespace std;

typedef struct 
{
	int col,row,data;
}Elem;

int main()
{
	int t,co,row,n,i,*num,*cpot;
	Elem *p,*q;
	cin>>t;
	while(t--)
	{
		cin>>co>>row;
		cin>>n;
        p=new Elem[n+1];
		q=new Elem[n+1];
		num=new int[n+1];
		cpot=new int[n+1];
		for(i=0;i<n;i++)
		{
			cin>>p[i].col>>p[i].row>>p[i].data;
		}
		for(i=0;i<=row;i++)
		{
			num[i]=0;
		}
		for(i=0;i<n;i++)
		{
			num[p[i].row]++;
		}
		cpot[0]=0;
		for(i=1;i<=row;i++)
		{
			cpot[i]=cpot[i-1]+num[i-1];
		}
		
		for(i=0;i<n;i++)
		{
			q[cpot[p[i].row]].col=p[i].row;
			q[cpot[p[i].row]].row=p[i].col;
			q[cpot[p[i].row]].data=p[i].data;
			cpot[p[i].row]++;
		}
		for(i=0;i<n;i++)
		{
			cout<<q[i].col<<" "<<q[i].row<<" "<<q[i].data<<endl;
		}
	}
	return 0;
}