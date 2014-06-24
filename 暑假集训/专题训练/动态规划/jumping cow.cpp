#include<iostream>
#include<process.h>
using namespace std;

int main()
{
    int n,i,sum,fh,j,a[150000];
    while(cin>>n)
    {
    sum=0;fh=1;             
    for(i=0;i<n;i++)
    cin>>a[i];
    for(i=0;i<n;i++)
    {
                    if (i==n-1&&fh==1) {sum+=a[i];break;}
                    if (i<n-1&&fh==1&&a[i]<=a[i+1]) continue;
                    if (fh==-1&&a[i]>=a[i+1]) continue;
                    for(j=i+1;j<n;j++)
                    {
                                 if (fh==1&&a[i]>a[j]) {sum+=a[i];fh=-1;break;}
                                 if (fh==-1&&a[i]<a[j]) {sum-=a[i];fh=1;break;}
                    }
                    i=j-1;
    }
    cout<<sum<<endl;
    }
    return 0;
}
