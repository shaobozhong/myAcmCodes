#include <string>
#include <iostream>
#include <cstdio>
using namespace std;
#define MAX(a,b,c) (a>b?a:b)>c?(a>b?a:b):c
int ctoi(char a)
{
    int b;
    if(a=='A')        b = 0;
    if(a=='C')        b = 1;
    if(a=='G')        b = 2;
    if(a=='T')        b = 3;
    if(a=='-')        b = 4;
    return b;
}
int main(int argc, char* argv[])
{
    int t,j,k,m,n;
    int f1,f2,f3;
    int f[101][101];
    int arr[5][5]=
    {
        { 5,-1,-2,-1,-3},
        { -1,5,-3,-2,-4},
        { -2,-3,5,-2,-2},
        { -1,-2,-2,5,-1},
        { -3,-4,-2,-1,0}
    };
    string a,b;
    cin>>t;
    while(t--)
    {
        j = k = 0;
        memset(f,0,sizeof(f));
        cin>>m>>a;
        cin>>n>>b;
        for(j=0;j<=m;j++)
        {
            for(k=0;k<=n;k++)
            {
                if(j == 0 && k == 0)
                {
                    f[j][k] = 0;
                }
                else if(j==0)
                {
                    f[j][k] = f[j][k-1] + arr[ctoi('-')][ctoi(b[k-1])];
                }
                else if(k==0)
                {
                    f[j][k] = f[j-1][k] + arr[ctoi(a[j-1])][ctoi('-')];
                }
                else
                {
                    f1 = f[j-1][k]   + arr[ctoi(a[j-1])][ctoi( '-')];
                    f2 = f[j][k-1]   + arr[ctoi( '-')][ctoi(b[k-1])];
                    f3 = f[j-1][k-1] + arr[ctoi(a[j-1])][ctoi(b[k-1])];
                    f[j][k] = MAX(f1,f2,f3);
                
                }
            }
        }
        cout<<f[m][n]<<endl;
    }
    return 0;
}