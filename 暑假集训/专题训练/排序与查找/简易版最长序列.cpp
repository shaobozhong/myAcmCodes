#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(const int &a,const int &b)
{
    return a<b;
}

int main()
{
    int a[10000];
    int t,max,count,n,i;
    scanf("%d",&t);
    while(t--)
    {
        max=0;
        cin>>n;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n,cmp);
        count=1;
        for(i=0;i<n;i++)
        {
            if (a[i]==a[i+1]&&i!=n-1) count++;
            else count=1;
            if (max<count) max=count;
        }
        cout<<max<<endl;
    }
    return 0;}
