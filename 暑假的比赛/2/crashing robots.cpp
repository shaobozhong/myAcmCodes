#include <iostream>
using namespace std;
int arr[110][110];
struct robot 
{
    int x,y;
    int dir;
};
robot r[110];
int find(int x,int y)
{
    int i=0;
    while (1)
    {
        if (r[i].x==x&&r[i].y==y)
        {
            return i;
        }
        i++;
    }
}
int main()
{
    int k;
    int a,b;
    int n,m;
    int i,j;
    int ro,repeat;
    char action,temp;
    int temp_x,temp_y;
    bool index;
    scanf("%d",&k);
    while (k--)
    {
        index=true;
        scanf("%d %d",&a,&b);
        for (i=0;i<b;i++)
        {
            for (j=0;j<a;j++)
            {
                arr[i][j]=0;
            }
        }
        scanf("%d %d",&n,&m);
        for (i=0;i<n;i++)
        {
            scanf("%d %d %c",&temp_x,&temp_y,&temp);
            r[i].x=b-temp_y;
            r[i].y=temp_x-1;
            if (temp=='N')
            {
                r[i].dir=0;
            }
            else if (temp=='E')
            {
                r[i].dir=1;
            }
            else if (temp=='S')
            {
                r[i].dir=2;
            }
            else
            {
                r[i].dir=3;
            }
            arr[r[i].x][r[i].y]=1;
        }
        for (i=0;i<m;i++)
        {
            scanf("%d %c %d",&ro,&action,&repeat);
            if (!index)
            {
                continue;
            }
            if (action=='R')
            {
                r[ro-1].dir=(r[ro-1].dir+repeat%4)%4;
            }
            else if (action=='L')
            {
                r[ro-1].dir=(r[ro-1].dir+4-repeat%4)%4;
            }
            else
            {
                if (r[ro-1].dir==3)//西
                {
                    arr[r[ro-1].x][r[ro-1].y]=0;
                    for (j=1;j<=repeat;j++)
                    {
                        if ((r[ro-1].y-j)<0)
                        {
                            index=false;
                            printf("Robot %d crashes into the wall\n",ro);
                            break;
                        }
                        else if(arr[r[ro-1].x][r[ro-1].y-j]==1)
                        {
                            index=false;
                            printf("Robot %d crashes into robot %d\n",ro,find(r[ro-1].x,r[ro-1].y-j)+1);
                            break;
                        }
                    }
                    if(index)
                    {
                        arr[r[ro-1].x][r[ro-1].y-j+1]=1;
                        r[ro-1].y=r[ro-1].y-j+1;
                    }
                }
                else if (r[ro-1].dir==2)//南
                {
                    arr[r[ro-1].x][r[ro-1].y]=0;
                    for (j=1;j<=repeat;j++)
                    {
                        if ((r[ro-1].x+j)>=b)
                        {
                            index=false;
                            printf("Robot %d crashes into the wall\n",ro);
                            break;
                        }
                        else if(arr[r[ro-1].x+j][r[ro-1].y]==1)
                        {
                            index=false;
                            printf("Robot %d crashes into robot %d\n",ro,find(r[ro-1].x+j,r[ro-1].y)+1);
                            break;
                        }
                    }
                    if(index)
                    {
                        arr[r[ro-1].x+j-1][r[ro-1].y]=1;
                        r[ro-1].x=r[ro-1].x+j-1;
                    }
                }
                else if (r[ro-1].dir==1)//东
                {
                    arr[r[ro-1].x][r[ro-1].y]=0;
                    for (j=1;j<=repeat;j++)
                    {
                        if ((r[ro-1].y+j)>=a)
                        {
                            index=false;
                            printf("Robot %d crashes into the wall\n",ro);
                            break;
                        }
                        else if(arr[r[ro-1].x][r[ro-1].y+j]==1)
                        {
                            index=false;
                            printf("Robot %d crashes into robot %d\n",ro,find(r[ro-1].x,r[ro-1].y+j)+1);
                            break;
                        }
                    }
                    if(index)
                    {
                        arr[r[ro-1].x][r[ro-1].y+j-1]=1;
                        r[ro-1].y=r[ro-1].y+j-1;
                    }
                }
                else//北
                {
                    arr[r[ro-1].x][r[ro-1].y]=0;
                    for (j=1;j<=repeat;j++)
                    {
                        if ((r[ro-1].x-j)<0)
                        {
                            index=false;
                            printf("Robot %d crashes into the wall\n",ro);
                            break;
                        }
                        else if(arr[r[ro-1].x-j][r[ro-1].y]==1)
                        {
                            index=false;
                            printf("Robot %d crashes into robot %d\n",ro,find(r[ro-1].x-j,r[ro-1].y)+1);
                            break;
                        }
                    }
                    if(index)
                    {
                        arr[r[ro-1].x-j+1][r[ro-1].y]=1;
                        r[ro-1].x=r[ro-1].x-j+1;
                    }
                }
            }
        }
        if (index)
        {
            printf("OK\n");
        }
    }
    return 0;
}
