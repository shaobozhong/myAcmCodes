#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;


double x1,y_1,x2,y2;


typedef struct 
{
    double x,y;
    double k;
}Node;

Node *a;

double Area(const Node &one,const Node &two)//¼ÆËãÃæ»ý
{
    double p1x,p1y,p2x,p2y,result;
    p1x=one.x-0;
    p1y=one.y-0;
    p2x=two.x-0;
    p2y=two.y-0;
    result=(p1x*p2y-p2x*p1y)/2;
  return result;
}

int main()
{
    double sum;
    Node one,two;
    int n,i,min,t=0;
    while(cin>>n,n)
    {
		t++;
        a=new Node[n];
        sum=0;
        min=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i].x>>a[i].y;
            if (a[min].x>=a[i].x) 
            {
             if (a[min].x>a[i].x||a[min].y>a[i].y) min=i;
            }
        }
       if (n<3) {cout<<"Figure "<<t<<": Impossible"<<endl;continue;}
        one=a[0];two=a[1];
        for(i=2;i<n;i++)
        {
            sum+=Area(one,two);
            one=two;two=a[i];
        }
        sum+=Area(one,two);
        one=two;
        two=a[0];
        sum+=Area(one,two);
		if (sum!=0)
		{

          printf("Figure %d: %.2f\n",t,-1*sum);
		}
		else 
			cout<<"Figure "<<t<<": Impossible"<<endl;
    }
    return 0;
}