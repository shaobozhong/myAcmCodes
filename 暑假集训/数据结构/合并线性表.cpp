#include<iostream>
using namespace std;


int main()
{
  int n,m,i,j;
  int *p,*q,*r,*ph,*qh;
  cin>>n;
  p=new int[n];
  for(i=0;i<=n-1;i++)
	  cin>>p[i];
  cin>>m;
  q=new int[m];
  for(i=0;i<=m-1;i++)
	  cin>>q[i];
  r=new int[n+m];
  i=0;
  ph=p;
  qh=q;
  while(i<=n+m-1)
  {if (p>ph+n-1) {r[i]=*q;q++;i++;continue;}
    if (q>qh+m-1) {r[i]=*p;p++;i++;continue;}
	  if (*p>=*q) {r[i]=*q;q++;}
	  else {r[i]=*p;p++;}
	  i++;
  }
  for(i=0;i<=n+m-1;i++)
	  cout<<r[i]<<" ";
      cout<<endl;
	return 0;
}