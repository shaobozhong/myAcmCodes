#include <iostream>
#include <math.h>
#define MaxNode 1000

int stack[MaxNode];
int top;

struct TPoint
{
    int x;
    int y;
};
TPoint point[MaxNode];

void swap(TPoint point[], int i, int j)
{
    TPoint tmp;
    tmp = point[i];
    point[i] = point[j];
    point[j] = tmp;
}

double multi(TPoint p1, TPoint p2, TPoint p0)
{
    return double(p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

double distance(TPoint p1, TPoint p2)
{
   return sqrt(double(p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
//qsort的比较函数,如果要从小到大排序,则:参数1>参数2时,return1;
int cmp(const void *a, const void *b)
{
    TPoint *c = (TPoint *)a;
    TPoint *d = (TPoint *)b;
    double k = multi(*c, *d, point[0]);
    if(k <= 0) return 1; //k<0说明c在d的逆时针方向,即相对于点p0,c的极角比d大
    else return -1;   
}

void grahamScan(int n)
{ 
	int i;
    //Graham扫描求凸包
    int u=0;     
    //将最左下的点调整到p[0]的位置
    for( i = 1;i <= n - 1;i++)
    {
        if((point[i].y < point[u].y) || (point[i].y == point[u].y && point[i].x < point[u].x))
        u = i;      
    } 
    swap(point, 0, u);
    
    //将p[1]到p[n - 1]按按极角排序，可采用快速排序
    qsort(point + 1, n - 1, sizeof(point[0]), cmp);
    for(i = 0;i <= 2;i++) stack[i] = i;
    top = 2;
    for(i = 3;i <= n - 1;i++)
    {
        while(multi(point[i], point[stack[top]], point[stack[top - 1]]) > 0)
            top--;
        top++;
        stack[top] = i;
    }
}

double length(int n)
{
    //已知多边形各顶点的坐标，求其周长
    double len;
    int i;
    len = 0;
    for(i = 0;i <= n - 1;i++){
        len += (distance(point[stack[i]], point[stack[(i + 1) % n]]));//别忘了模n(处理//最后一个点和第一个点的距离)
    } 
    return len; 
}

int main()
{
    int i, n;
    while(scanf("%d", &n) && n ){
        for(i = 0;i < n;i++)
        scanf("%d%d", &point[i].x, &point[i].y);
        if(n < 2){
            printf("0.00\n");
            continue;       
        }
        if(n == 2){
            printf("%.2lf\n", distance(point[0], point[1]));
            continue;
        }
        grahamScan(n);
        printf("%.2lf\n", length(top + 1));        
    }
    return 0;
}
