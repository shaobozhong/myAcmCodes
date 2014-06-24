#include <stdio.h> 
int main() 
{ 
int n,i=4,m=5,j; 
while(scanf("%d",&n)+1)
{i=4;m=5;
if (n<=4) {printf("%d\n",n);continue;}
while (m<n) m+=i++; 
j=m-n; 
m=2; 
if (j==1) { m=3; j=i-1; i++; } 
while (m<i-1) 
{ if (m!=j) printf("%d ",m); m++; 
} 
printf("%d\n",i-1); 
}
return 0; 
}