#include<iostream>
using namespace std;
double a[300000];
int min(int n,double *a)//求最小值并返回数组下标
{
      int i,k=1;double tmp=a[1];
   for(i=2;i<=n;i++)
   {
    if(tmp>a[i]){tmp=a[i];k=i;}
   }
   return k;
}
int max(int n,double *a)//求最大值并返回数组下标
{
int i,k=1;double tmp=a[1];
for(i=2;i<=n;i++)
{
   if(tmp<a[i])
   {
    tmp=a[i],k=i;
   }
}
return k;
}
double gap(int n,double *a)
{
int i,j;
double minx=a[min(n,a)],maxx=a[max(n,a)];
int *count= new int[n+1];
double *low=new double [n+1];//在一个桶里时，表示最左边的值
double *high= new double [n+1];//在一个桶里时，表示最右边的值
for(i=1;i<n;i++)     //初始化
{
   count[i]=0;
   high[i]=minx;
   low[i]=maxx;
}
for(i=1;i<=n;i++)            
{
   int bucket=int((n-1)*(a[i]-minx)/(maxx-minx))+1;//求出下标
   count[bucket]++;
   if(a[i]<low[bucket])low[bucket]=a[i];      //求出最左边的值
   if(high[bucket]<a[i])high[bucket]=a[i];          //求出最右边的值
}
double t=0,left,c;left=high[1]; 
for(i=2;i<n;i++)                                 //扫描一遍求出最大的间隙
{
if(count[i])
{
         c=low[i]-left;
   if(c>t)t=c; 
   left=high[i];
}
}
return t;
}
int main()
{
int n,i;double ret;
while(cin>>n)
{
   for(i=1;i<=n;i++)
   scanf("%lf",&a[i]);
   ret=gap(n,a);
   cout<<ret<<endl;
}
return 0;
}