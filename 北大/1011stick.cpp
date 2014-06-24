#include <iostream>

using namespace std;
int len[64], n, minlen, get;
bool b[64];

int cmp(const void *a, const void *b)
{
 return *(int *)a < *(int *)b ? 1 : -1;
}

bool search(int nowlen, int nowget, int cnt)
{
 if(cnt >= n) return false;
 if(get == nowget) return true;
 int i;
 bool f = false;
 if(nowlen == 0) f = true;
 for(i=cnt; i<n; i++)
 {
  if(!b[i])
  {
   if(len[i]+nowlen == minlen)
   {
    b[i] = true;
    if(search(0, nowget+1, nowget))
     return true;
    b[i] = false;
    return false;
   }
   else if(len[i]+nowlen < minlen)
   {
    b[i] = true;
    if(search(nowlen+len[i], nowget, i+1))  // 5
     return true;
    b[i] = false;
    if(f) return false;       // 8
    while(i+1<n && len[i] == len[i+1]) i++;  // 6
   }
  }
 }
 return false;
}

int main()
{
 int i, tollen;
 while(scanf("%d", &n), n)
 {
  tollen = 0;
  for(i=0; i<n; i++)
  {
   scanf("%d", &len[i]);
   tollen += len[i];
  }
  qsort(len, n, sizeof(int), cmp);   // 3
  for(minlen=len[0]; ; minlen++)    // 2
  {
   if(tollen % minlen) continue;   // 1
   memset(b, 0, sizeof(b));
   get = tollen / minlen;
   if(search(0, 0, 0)) 
   {
    printf("%d\n", minlen);
    break;
   }
  }
 }
 return 0;
}

