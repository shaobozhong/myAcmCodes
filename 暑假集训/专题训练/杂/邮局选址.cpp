#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

#define  M 10001

bool cmp(int a, int b)
{
   return a<b;
}

int cal(int a[], int n)
{
    int sum = 0,i,mid;
    mid = a[n / 2];
    for(i = 0; i < n; i++)
        sum += abs(a[i] - mid);
    return sum;
}

int main()
{
    int x[M],y[M];
    int i, n;
    while(scanf("%d",&n) != EOF)
    {
        for(i = 0; i < n; i++)
            scanf("%d%d",x + i, y + i);
        sort(x ,x + n, cmp);
        sort(y, y + n, cmp);
        printf("%d\n",cal(x, n) + cal(y, n));
    }
    return 0;
}
