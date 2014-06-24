#include "stdio.h"
int main(){
/*****  下行有错误    **********/
       int n,s,t,m=1;
       int k=2;
       s=1;     //第一项赋值给累加器
/*****  下行有错误    **********/
       scanf("%d",&n);
       while(k<=n){
/*****  下行有错误    **********/
              m=m*k*(-1);
              s=s+m;
              k=k+1;
       }
       printf("%d\n",s);
       return 1;
}
