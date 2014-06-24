#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

__int64 mm,nn,xx,yy,l;
__int64 c,d,x,y;

__int64 modd(__int64 a, __int64 b)
{
 if(a>=0)
  return a%b;
 else 
  return a%b+b; 
}

__int64 exGcd(__int64 a, __int64 b)
{__int64 r,t;
 if(b==0)
 {
  x=1;
  y=0;
  return a;  
 } 
  r=exGcd(b, a%b);
  t=x;
 x=y;
 y=t-a/b*y;
 return r;
}

int main()
{
 while(scanf("%I64d %I64d %I64d %I64d %I64d",&xx,&yy,&mm,&nn,&l)!=EOF)
 {
 if(mm>nn)  //分情况 
 {
  d=exGcd(mm-nn,l);
  c=yy-xx; 
 }
 else 
 {
  d=exGcd(nn-mm,l);
  c=xx-yy; 
 }
 if(c%d != 0)
 {
  printf("Impossible\n");
  continue;
 }
 l=l/d;
 x=modd(x*c/d,l);   ///取模函数要注意 
 printf("%I64d\n",x);
 } 
 return 0;
} 

