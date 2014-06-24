#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-8;
struct Point
{
    double x,y;//½Ç¶È
};
Point a[50000+10];
int flag;
bool cmp(Point h,Point k)
{
    if(h.x!=k.x) return h.x<k.x;
    return h.y<k.y;
}
void check(int l,int r)
{
    if(l>=r) return ;
    if(flag==0) return ;
    for(int i=l;i<=r;)
    {
        int j=i+1;
        while(j<=r&&a[i].x<a[j].x&&a[j].y<a[i].y) j++;
        check(i+1,j-1);
        if(flag==0) return ;
        if(j==r+1) return ;
        if(a[i].y<a[j].x) i=j;
        else
        {
            flag=0;
            return ;
        }
    }
}
int main()
{
    int ci;scanf("%d",&ci);
    while(ci--)
    {
        int n;scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&a[i].x,&a[i].y);
            if(a[i].x>a[i].y) swap(a[i].x,a[i].y);
        }
        sort(a,a+n,cmp);
        flag=1;
        check(0,n-1);
        if(flag) printf("do not intersect\n");
        else printf("intersect\n");
    }
    return 0;
}