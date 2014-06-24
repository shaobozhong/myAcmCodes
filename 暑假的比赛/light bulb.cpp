#include <iostream>
#define MAX 102
#include <cmath>
using namespace std;
typedef struct node
{
    double x,y,z;
    double I;
}Point;//存储各点信息 包括坐标和光照系数
Point data[MAX];
int t,n;
double MM;
void Init()//输入
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%lf%lf%lf%lf",&data[i].x,&data[i].y,&data[i].z,&data[i].I);
}
/*double GetI(Point p,int x,int y)
{
    double dis=pow((p.z*p.z+(p.x-x)*(p.x-x)+(p.y-y)*(p.y-y)),1.5);
    double e;
    e=p.I*p.z/dis;
    return e;
}*/
double GetDis(Point p,int i,int j)//计算距离 即题中的R
{
    return p.z*p.z+(p.x-i)*(p.x-i)+(p.y-j)*(p.y-j);
}
void Process()
{
    int i,j,k;
    MM=-1.0;
    double sum,dis;
    for(i=-100;i<=100;i++)
        for(j=-100;j<=100;j++)
        {
            sum=0;
            for(k=0;k<n;k++)
            {
                dis=GetDis(data[k],i,j);
                sum+=data[k].I*data[k].z/(dis*sqrt(dis));
            }
            if(sum>MM)
                MM=sum;
        }
    printf("%0.2lf\n",MM);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        Init();
        Process();
    }
    return 0;
}