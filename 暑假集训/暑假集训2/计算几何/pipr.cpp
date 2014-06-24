#include <iostream>
#include <math.h>
using namespace std;

#define  N 25+5
#define  inf  -999999999999999.0//x为无穷小
#define  eps   1e-11
double up[N][2],low[N][2];
int n;

int deq(double p)//精度要求
{
 return fabs(p) < eps ? 0 : (p > 0 ? 1 :-1);
}

int Cross(double p1[],double p2[])//叉积
{
 double d = p1[0]* p2[1] - p2[0]* p1[1];
 return deq(d);
}

int Direction(double pi[],double pj[],double pk[])//判断pi-pk对pi-pj的方位（顺时针还是逆时针）
{
 double p1[2],p2[2];
 p1[0] = pk[0]-pi[0],p1[1] = pk[1]-pi[1];
 p2[0] = pj[0]-pi[0],p2[1] = pj[1]-pi[1];
 return Cross(p1,p2);
}

bool Intersect(double p1[],double p2[],double p3[],double p4[])//判断p1、p2直线和p3、p4线段是否相交
{
 int d3,d4;

 d3 = Direction(p1,p2,p3);
 d4 = Direction(p1,p2,p4);

 if(d3 *d4 <= 0)
  return true;
 

 return false;
}

double Xnum(double y1,double x1,double ys,double xs,double kq,double kp)//求x值
{
 return (y1-ys + kp * xs - kq * x1)/(kp- kq);
}
double Cpu(double p1[],double p2[])//以p1和p2点位直线的最大x值
{
 int k =0;
 while(k < n && Intersect(p1,p2,up[k],low[k]))//枚举从第1个拐点开始
  k ++;

 if(k ==0)//如果第1个拐点就不满足
  return inf;

 if(k == n)//如果最后一个拐点就满足，说明会到无穷远处
  return up[n-1][0];
//在k-1处的拐点到k处的拐点有交点
 double kq = (p2[1]-p1[1])/(p2[0]-p1[0]);
 double d = inf;
 if(Intersect(p1,p2,up[k-1],up[k]))//如果和上管道有交点
 {
  double kp = (up[k][1]-up[k-1][1])/(up[k][0]-up[k-1][0]);

  d = max(d,  Xnum(p1[1],p1[0],up[k-1][1],up[k-1][0],kq,kp));

 }
//这里为什么到if两个自己想想...
 if(Intersect(p1,p2,low[k-1],low[k]))//如果有下管道有交点
 {
  double kp = (low[k][1]-low[k-1][1])/(low[k][0]-low[k-1][0]);

  d = max(d, Xnum(p1[1],p1[0],low[k-1][1],low[k-1][0],kq,kp));
 }

 return d;
}
int main()
{
 //freopen("F://C++程序//ACM2//read.txt","r",stdin);
 //freopen("F://C++程序//ACM2//write.txt","w",stdout);

 while(scanf("%d",&n), n)
 {
  int i , j;

  for(i = 0; i <n;i++)
  {
   scanf("%lf %lf",&up[i][0],&up[i][1]);
   low[i][0] = up[i][0];
   low[i][1] = up[i][1] -1.0;
  }

  double d = inf;
  bool flag =true;
  for(i = 0; i <n && flag;i++)
  {
   for(j = i+1; j <n && flag;j++)
   {
    d = max(d, Cpu(up[i] ,up[j]));//枚举第1个拐点的上点和第2个拐点的下点
    d = max(d, Cpu(up[i] ,low[j]));//...
    d = max(d, Cpu(low[i], up[j]));//...
    d = max(d, Cpu(low[i], low[j]));//...

    if(deq(d- up[n-1][0]) ==0)//如果是无穷远，退出
    {
     flag =false;
     break;
    }
   }
  }

  if(!flag)
   printf("Through all the pipe.\n");
  else
   printf("%.2lf\n", d);
 }
 return 0;
}

