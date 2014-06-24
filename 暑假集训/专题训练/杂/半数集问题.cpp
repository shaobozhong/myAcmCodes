#include <stdio.h>

int a[1000],pre;

void get(int n)
{
 int i,j,k;
 for(i=pre+1; i <= n; i++)
 {
  k = i/2;
  for(a[i]=j=1; j <= k; j++)
   a[i] = a[i] + a[j];
 }
 pre = n;
}
int main(){
 int n;
 pre=1;
 a[0]=1;
 a[1]=1;
 while(scanf("%d",&n)!=EOF)
 {
  if(n>pre)
   get(n);
  printf("%d\n",a[n]);
 }
 return 0;
}


