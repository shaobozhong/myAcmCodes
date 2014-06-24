#include<iostream>
using namespace std;
int x1,y1,x2,y2;
bool judge(double x,double y)
{
	double left;
	left=(x-x1)*(y2-y1)-(x2-x1)*(y-y1);
	if (left>=0) return true;
	return false;
}

int main()
{
	bool ti;
	int *x,*y,startx,starty,start2x,start2y;
	int n,i;
    while((cin>>n)&&n!=0)
	{
		ti=false;
	    x=new int[n];
		y=new int[n];
		cin>>x1>>y1>>x2>>y2;
		start2x=x2;
		start2y=y2;
		startx=x1;starty=y1;
		for(i=0;i<=n-3;i++)
		{
			cin>>x[i]>>y[i];
		}
		if (n<3) {cout<<"concave"<<endl;continue;}
		for(i=0;i<=n-3;i++)
		{
		if (judge(x[i],y[i])) {break;}
			x1=x2;
			y1=y2;
			x2=x[i];
			y2=y[i];
		}
		if (i==n-2) 
		{
			
			if (judge(startx,starty)) cout<<"concave"<<endl;
			else 
			{
             x1=x2;
			 y1=y2;
			 x2=startx;
			 y2=starty;
			 if (judge(start2x,start2y)) cout<<"concave"<<endl;
             else cout<<"convex"<<endl;
			}
		}
		else cout<<"concave"<<endl;
     }
	return 0;
}