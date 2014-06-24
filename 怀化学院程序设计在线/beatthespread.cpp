#include<stdio.h>
long long lines, s, d, a, b, i;
int main(){
    scanf("%lld", &lines);
    for (i=0;i<lines;++i) {
        scanf("%lld %lld", &s, &d);
  if ( s < d || ( s + d ) % 2 || s < 0 || d < 0) 
  {
   printf("impossible\n");
  } else {
   a = (s + d) / 2;
   b = (s - d) / 2;
   printf("%lld %lld\n", a, b);
  }
    }
    return 0;
}