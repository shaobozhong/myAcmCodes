#include <iostream>  
#include <cmath>  
using namespace std;  
#define PI acos(-1.0)  
  
double GetVolume(double r,double R,double h,double H)     
{     
    double u = h/H*(R-r) + r;//中部小圆台上底半径,根据比例可以求  
    return PI/3*(r*r+r*u+u*u)*h;  
}  
int main()  
{  
    int t;  
    double r,R,H,V,s,S,mids,midh,midv,f,l;  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%lf%lf%lf%lf",&r,&R,&H,&V);  
        s=PI*r*r;  
        S=PI*R*R;  
        f=0;l=100;  
        while(l-f>1e-9)  
        {  
            midh=(l+f)/2;  
            midv=GetVolume(r,R,midh,H);  
            if(fabs(midv-V)<=1e-9)  
                break;  
            else if(midv>V)  
                l=midh-1e-9;  
            else  
                f=midh+1e-9;  
        }  
        printf("%.6lf\n",midh);  
    }  
    return 0;  
}