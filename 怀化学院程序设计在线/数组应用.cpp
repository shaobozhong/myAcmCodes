#include "stdio.h"
/****** 下行有错误    ********/
int f_sum(int *p,int n){
       int i,sum=0;
       for(i=0;i<n;i++)
              sum = sum+*(p+i);
       return sum;
}
 
int main(){
       int n,i;
       int x[10001],sum;
       scanf("%d",&n);
       for(i=0;i<n;i++)
/****** 下行有错误    ********/
              scanf("%d",&x[i]);
/****** 下行有错误    ********/
       sum=f_sum(x,n);      
       printf("%d\n",sum);
       return 1;
}
