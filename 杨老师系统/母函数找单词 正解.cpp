#include <iostream>
using namespace std;
int a[51],b[51];
int main()
{
    int n,i,j,k,sum,f[27];    
    cin>>n;
    while(n--)
    {
        sum=0;
        for(i=0; i<51; i++)
        {
            a[i]=0; b[i]=0;
        }
        for(i=1; i<=26; i++)
            cin>>f[i];
        for(i=1; i<=26; i++)
        {
            if(f[i]>0)
            {
                for(j=0; j<=f[i]; j++)  //初始第一个元素组成的情况
                {
                    if(j*i>50)break;
                    a[j*i]=1;
                }
                break;
            }            
        }
        for(i=i+1; i<=26; i++)
        {
            for(j=0; j<=50; j++)  
            {
                if(a[j]!=0)
                {
                    for(k=0; k<=f[i] && (k*i+j)<=50; k++) 
                    {
                        b[k*i+j]+=a[j];//遍历每种指数的系数情况.
                    }
                }
            }
            for(j=0; j<=50; j++)
            {
                a[j]=b[j];
                b[j]=0;
            }                            
        }        
        for(j=1; j<=50; j++)
            sum+=a[j];
        cout<<sum<<endl;
    }
    return 0;
}