#include<iostream>   
using namespace std;   
  
int main(){   
  
    long long s, count;   
 int i, n;   
 while(scanf("%d",&n)!=EOF){   
     s=1;   
     for(i=0; i<n-1; i++){   
            s=s*2;   
  }   
     s=(n-2)*s+1;   
  
  printf("%lld\n",s);   
 }   
  
    return 0;   
}  
