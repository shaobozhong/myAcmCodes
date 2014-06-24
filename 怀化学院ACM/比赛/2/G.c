#include   <stdlib.h>   
  #include   <stdio.h>   
  #include   <math.h>   
  typedef   unsigned   __int64   u64;   
  #define   MAX   100   
  #define   MAXN   30   
  u64   len,   dig,   limit;   
  u64   mod(u64   a,   u64   b,   u64   n){   
                  if(!a)return   0;   
                  else   return   (   ((a&dig)*b)%n   +   (mod(a>>len,b,n)<<len)%n   )%n;   
  }   
  u64   by(u64   a,   u64   b,   u64   n){//(a*b)%n   
                  u64   p;   
                  p   =   8,   len   =   61;   
                  while(p<n){   
                                  p<<=4;   
                                  len   -=4;   
                  }   
                  dig   =   ((limit/p)<<1)   -   1;   //动态划分段   
                  return   mod(a,b,n);   
  }   
  u64   random(){   
                  u64   a;   
                  a   =   rand();   
                  a   *=   rand();   
                  a   *=   rand();   
                  a   *=   rand();   
                  return   a;   
  }   
  //////////////////////////////////////////////////////   
  //Miller_Rabin   
  u64   square_multiply(u64   x,   u64   c,   u64   n){//(x^c)%n   
                  u64   z=1;   
                  while(c){   
                                  if(c%2==1)z   =   by(z,x,n);   
                                  x   =   by(x,x,n);   
                                  c=(c>>1);   
                  }   
                  return   z;   
  }   
    
  //素数测试函数,如果n是素数则返回true，否false   
  bool   Miller_Rabin(u64   n)   
  {   
          if(n<2)return   false;   
          if(n==2)return   true;   
          if(!(n&1))return   false;//偶数的情况   
          u64   k   =   0,   i,   j,   m,   a;   
          m   =   n   -   1;   
          while(m%2==0)   
  m=(m>>1),k++;//n-1=2^k*m   
          for(i=0;i<MAX;i++){   
                          a   =   square_multiply(random()%(n-1)+1,   m,   n);//平方乘   
                          if(a==1)   continue;   
                          for(j=0;j<k;j++){   
                                          if(a==n-1)   break;   
                                          a   =   by(a,a,n);   
                          }   
                          if(j<k)   continue;   
                          return   false   ;   
          }   
          return   true;   
  }   
