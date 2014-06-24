#include <cstdio>

#include <cstring>

#include <algorithm>

#include <vector>

#include <cmath>

#include <queue>

#include <string>

#include <map>

#include <iostream>

using namespace std;


const double PI=acos(-1.0);

const double eps=1e-4;

double ta,tb,t1,a,b,t,c;

double t2;

double sqrr(double x) {return x*x*x;}

double f(double x) 

{

       return sqrt(b*b-b*b/(a*a)*x*x);

}

const int per=8000;

double g(double r) //对f做从0到r的积分

{

       double ans=0,x=0;

       double ss=1.0*r/per;

       for(int i=0;i<per;i++)
       {
              ans+=ss*(f(x)+f(x+ss)+4*f(x+0.5*ss))/3;

              x+=ss;
       }

       return ans/2;

}

double s,ff,hh;

double play1()

{

       double l=c,r=a;

       while(r-l>1e-9)

       {

              double now=(l+r)/2;

              double cc=hh-g(now);

              double y=f(now)*(now-c)/2;

              cc+=y;

              if(cc>s) l=now;

              else r=now;

       }

       return l;

}

double play2()

{

       double l=-a,r=c;

       while(r-l>1e-9) 

       {

              double now=(l+r)/2;

              double y=f(now)*(c-now)/2;

              double cc;

              if(now>0) cc=hh-g(now)-y;

              else cc=hh+g(-now)-y;

              if(cc>s) l=now;

              else r=now;

       }

       return l;

}

int main()

{

//     freopen("in.txt","r",stdin);

       int i,j,k,ca=1;

       while(1) 

       {

              scanf("%lf%lf%lf%lf%lf%lf",&ta,&tb,&t1,&a,&b,&t);

              if(ta==0&&tb==0&&t1==0&&a==0&&b==0&&t==0) break;

              t2=t1*sqrt(sqrr(a/ta));

              if(t>t2) 

              {

                     int ft=int(t/t2);

                     t-=ft*t2;

              }

              int flag=0;

              if(t>t2/2) 

              {

                     flag=1;

                     t-=t2/2;

                     t=t2/2-t;

              }

              c=sqrt(a*a-b*b);

              s=t/t2*PI*a*b;

              hh=PI*a*b/4;

              ff=hh-g(c);

              double x;

              if(ff>s) x=play1();

              else x=play2();

              double y=f(x);

              if(flag) y=-y;

              if(fabs(y)<eps) y=0;

              if(fabs(x)<eps) x=0;

              printf("Solar System %d: %.3lf %.3lf\n",ca++,x,y);

       }

       return 0;

}
