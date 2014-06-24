#include "stdio.h"
int main(){
/*****  下行有错误    **********/
       int n,s=0,t=1;
       int k=1;
       scanf("%d",&n);
/*****  下行有错误    **********/
       while(k<=n){
              t=t*k;
              s=s+t;
/*****  下行有错误    **********/
              k=k+1;
       }
       printf("%d\n",s);
       return 1;
}
