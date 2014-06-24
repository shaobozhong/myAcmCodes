
#include<iostream>
using namespace std;
typedef struct tnode
{
    double l;
    double r;
}tnode; 

tnode getseg1(double d,double c,double b)
{
    tnode tmp;
    tmp.l=(d+c-360)/b;
    tmp.r=(c-d)/b;
    if(tmp.l<0.0)
        tmp.l=0.0;
    if(tmp.l>60.0)
        tmp.l=60;
    if(tmp.r<0.0)
        tmp.r=0.0;
    if(tmp.r>60.0)
        tmp.r=60.0;
    return tmp;
} 

tnode getseg2(double d,double c,double b)
{
    tnode tmp;
    tmp.l=(d+c)/b;
    tmp.r=(360+c-d)/b;
    if(tmp.l<0.0)
        tmp.l=0.0;
    if(tmp.l>60.0)
        tmp.l=60;
    if(tmp.r<0.0)
        tmp.r=0.0;
    if(tmp.r>60.0)
        tmp.r=60.0;
    return tmp;
} 

tnode operator *(const tnode &a,const tnode &b)
{
    tnode tmp;
    tmp.l=a.l>b.l?a.l:b.l;
    tmp.r=a.r<b.r?a.r:b.r;
    if(tmp.l>tmp.r)
    {
        tmp.l=0.0;
        tmp.r=tmp.l;
    }
    return tmp;
} 

int main()
{
    int h,m,i,j,k;
    double N,sum;
    double c,b;
    tnode tmp[3][2],xtmp;
    while(scanf("%lf",&N)&&N!=-1)
    {
        sum=0;
        for(h=0;h<12;h++)
        {
            for(m=0;m<60;m++)
            {
                c=30*h-5.5*m;
                b=11.0/120; tmp[0][0]=getseg1(N,c,b);
                tmp[0][1]=getseg2(N,c,b);
                c=30*h+0.5*m;b=719.0/120;
                tmp[1][0]=getseg1(N,c,b);
                tmp[1][1]=getseg2(N,c,b);
                c=6*m;b=5.9;
                tmp[2][0]=getseg1(N,c,b);
                tmp[2][1]=getseg2(N,c,b);
                for(i=0;i<2;i++) {
                    for(j=0;j<2;j++) {
                        for(k=0;k<2;k++) {
                            xtmp=tmp[0][i]*tmp[1][j]*tmp[2][k];
                            sum+=xtmp.r-xtmp.l;
                        }
                    }
                }
            }
        }
        printf("%0.3lf\n",100.0*sum/43200);
    }
    return 0;
}
