#include<iostream>
#include<limits.h>
using namespace std;
#define SIZE 5001

int a[SIZE],b[SIZE];
int c[SIZE];
int sum;
int n;

void MSort(int low,int mid,int high)
{
    int i,j,k;
    for(i=low,j=low,k=mid+1;j<=mid&&k<=high;i++)
    {
        if(a[j]>a[k])
        {
            b[i] = a[k++];
            sum += mid+1-j;
        }
        else b[i] = a[j++];
    }
    if(j==mid+1)
        for(;k<=high;k++,i++)
            b[i] = a[k];
    if(k==high+1)
        for(;j<=mid;j++,i++)
            b[i] = a[j];
    for(i=low;i<=high;i++)
        a[i] = b[i];
}

void MergeSort(int low,int high)
{
    int mid = (low+high)/2;
    if(low<high)
    {
        MergeSort(low,mid);
        MergeSort(mid+1,high);
        MSort(low,mid,high);
    }
}

int main()
{        
    int i, j, k, pos,best;
    while (scanf("%d", &n)!=EOF)
    {
        for (i=1; i<=n; ++i)
            scanf("%d", &c[i]);
        best=INT_MAX;
        for (j=1; j<=n; ++j)
        {
            pos=0;
            for (k=j; k<=n; ++k)
            {
                ++pos;
                a[pos]=c[k];
            }
            for (k=1; k<j; ++k)
            {
                ++pos;
                a[pos]=c[k];
            }
            sum=0;
            MergeSort(1, n);
            if (sum<best)
                best=sum;
        }
        printf("%d\n", best);
    }
    return 0;
}