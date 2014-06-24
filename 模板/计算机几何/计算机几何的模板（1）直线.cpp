#include<iostream>
#include<algorithm>
using namespace std;
//(1)有四点判断直线相交的判断
//算法:两直线向量的差集  
typedef struct
{
	double x,y;
}pot;

typedef struct 
{
	pot start,end;
}line;

bool judge_line_intersection(const line &one,const line &two)//判断直线是否相交其中重合也算是相交（非严格相交）
{
   double p1x,p1y,p2x,p2y,left,right;
   p1x=one.end.x-one.start.x;
   p1y=one.end.y-one.start.y;
   p2x=two.end.x-one.start.x;
   p2y=two.end.y-one.start.y;
   left=p1x*p2y-p2x*p1y;
   p1x=one.end.x-one.start.x;
   p1y=one.end.y-one.start.y;
   p2x=two.start.x-one.start.x;
   p2y=two.start.y-one.start.y;
   right=p1x*p2y-p2x*p1y;
   if (left*right>0) return false;
   return true;
}

bool judge__ssline_intersection(const line &one,const line &two)//判断直线是否严格相交
{
   double p1x,p1y,p2x,p2y,left,right;
   p1x=one.end.x-one.start.x;
   p1y=one.end.y-one.start.y;
   p2x=two.end.x-one.start.x;
   p2y=two.end.y-one.start.y;
   left=p1x*p2y-p2x*p1y;
   p1x=one.end.x-one.start.x;
   p1y=one.end.y-one.start.y;
   p2x=two.start.x-one.start.x;
   p2y=two.start.y-one.start.y;
   right=p1x*p2y-p2x*p1y;
   if (left*right>=0) 
   {
	   if (left!=0||right!=0)  return true;
	   return false;
   }
   return true;
}

void calc_cross(const line &one,const line &two)//求直线交点
{
	bool e1,e2;
	double k1,k2,b1,b2,x,y;
	   e1=false;
	   e2=false;
	   if ((one.end.y-one.start.y)*(two.end.x-two.start.x)-(two.end.y-two.start.y)*(one.end.x-one.start.x)==0) {cout<<"NO"<<endl;return;}//如果直线斜率相等考虑了斜率不存在情况的变形
	   if (one.end.x-one.start.x==0) {e1=true;k1=0;b1=one.start.x;}
	   else {k1=(one.end.y-one.start.y)/(one.end.x-one.start.x); b1=one.start.y-k1*one.start.x;}

      
	   if (two.end.x-two.start.x==0) {e2=true;k2=0;b2=two.start.x;}
	   else {k2=(two.end.y-two.start.y)/(two.end.x-two.start.x);b2=two.start.y-k2*two.start.x;}
	   
	   if (e1)
	   {
		   y=k2*b1+b2;
		   printf("(%.2f,%.2f)\n",b1,y);
		   return;
	   }
        if (e2)
	   {
		   y=k1*b2+b1;
		   printf("(%.2f,%.2f)\n",b2,y);
		   return;
	   }
       
	   x=(b2-b1)/(k1-k2);
	   y=k1*x+b1;
printf("(%.2f,%.2f)\n",x,y);	
return;
}

int main()
{

    line l[2];
	int test,i;
	cin>>test;//用例数
	while(test--)
	{
		for(i=0;i<=1;i++)// 输入两直线
		{
			cin>>l[i].start.x>>l[i].start.y>>l[i].end.x>>l[i].end.y;
		}
       calc_cross(l[0],l[1]); 
	}
	return 0;
}
