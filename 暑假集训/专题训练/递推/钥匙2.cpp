#include<stdio.h>
#include<limits.h>
#include<math.h>
#include<float.h>
__int64 t1[35],t2[35];
__int64 a,b;
int main()
{
 int i,n;
 t1[3]=16;
 t2[3]=18;
 for(i=4;i<=34;i++)
 {
  a=((__int64)pow(2,(double)i-1)-2)*6+((__int64)pow(2,(double)i-2)-1)*4;
  b=((__int64)pow(2,(double)i-1)-2)*9;
  t1[i]=t1[i-1]+t2[i-1]*4+a;
  t2[i]=t1[i-1]*2+t2[i-1]*4+b;
  
 }
 while(scanf("%d",&n)!=EOF)
 printf("%I64d\n",t1[n]*2+t2[n]*4);
 return 0;
}
