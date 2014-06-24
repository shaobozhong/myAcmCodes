#include<iostream>
using namespace std;

typedef struct 
{
	double x1,y1,x2,y2;
}stack;

bool judge(const stack *a,int i,int j)
{
	double left,right,left1,right1; 
  double p1x,p1y,p2x,p2y;
  p1x=a[i].x2-a[i].x1;
  p1y=a[i].y2-a[i].y1;
  p2x=a[j].x1-a[i].x1;
  p2y=a[j].y1-a[i].y1;
  left=p1x*p2y-p1y*p2x;
  p2x=a[j].x2-a[i].x1;
  p2y=a[j].y2-a[i].y1;
  right=p1x*p2y-p1y*p2x;

  p1x=a[j].x2-a[j].x1;
  p1y=a[j].y2-a[j].y1;
  p2x=a[i].x1-a[j].x1;
  p2y=a[i].y1-a[j].y1;
  left1=p1x*p2y-p1y*p2x;
  p2x=a[i].x2-a[j].x1;
  p2y=a[i].y2-a[j].y1;
  right1=p1x*p2y-p1y*p2x;
  if (left*right<=0&&left1*right1<=0) return true;
  return false;//还未判断平行不相交的情况可以分四个点去做
}
int main()
{
	stack *a;
  int n,i,j;
  while(cin>>n,n!=0)
  {
     a=new stack[n];
	 for(i=0;i<n;i++)
	 {
		 cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2;
	 }
	 for(i=0;i<n-1;i++)
	 {
		 for(j=i+1;j<n;j++)
		 {
			 if (judge(a,i,j)) break;
		 }
		 if (j==n) cout<<i+1<<" ";
	 }
	 cout<<n<<endl;

  }
  return 0;
}