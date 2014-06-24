#include<iostream>
using namespace std;

struct elem
{
	int x,y,r;
	bool la;
};

elem *a;

bool judge(int org,int i)
{
	if ((a[org].x-a[i].x)*(a[org].x-a[i].x)+(a[org].y-a[i].y)*(a[org].y-a[i].y)== (a[org].r+a[i].r)*(a[org].r+a[i].r)) return true;
	return false;
}
int main()
{

	int n,i,org;
	bool la;
	while(cin>>n)
	{
		org=-1;
		a=new elem[n+1];
		for(i=0;i<n;++i)
		{
			cin>>a[i].x>>a[i].y>>a[i].r;
			a[i].la=true;
			if (a[i].x==0 && a[i].y==0) org=i;
		}
        la=true;
		if (org==-1) {puts("ÎÞ·¨Çý¶¯");continue;}
		while(la)
		{
			la=false;
			a[org].la=false;
			la=false;
			for(i=0;i<n;++i)
			{
				if (a[i].la && judge(org,i)) 
				{
					la=true;
					org=i;
					break;
				}
			}
		}
		cout<<a[org].x<<" "<<a[org].y<<endl;
	}
	return 0;
}