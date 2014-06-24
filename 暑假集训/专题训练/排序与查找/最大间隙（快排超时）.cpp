#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

bool cmp(const double a,const double b)
{
    return a<b;
}

int main()
{
    double *a,max,temp;
    int n,i;
  while(scanf("%d",&n)!=EOF)
  {
      max=0;
      a=new double[n]; 
      for(i=0;i<n;i++)
          scanf("%lf",&a[i]);
      sort(a,a+n,cmp);
      for(i=1;i<n;i++)
      {
          temp=a[i]-a[i-1];
       if (max<temp) max=temp;
       if (max>a[n-1]-a[i]) break;
      }
      printf("%g\n",max);
  }
    return 0;
}
