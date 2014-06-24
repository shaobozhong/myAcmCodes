#include <iostream>   
using namespace std;   
const int Max1(250005);   
const int Max2(51);   
int num1[Max1];   
int num2[Max1];   
int V[Max2];   
int M[Max2];   
int main ()   
{   
    int i,j;
    int N;   
    while (cin>>N,N>0)   
    {   
        int sum = 0;    
        for ( i = 1; i <= N; ++ i )   
        {   
            cin>>V[i]>>M[i];   
            sum += V[i] * M[i];    
        }    
        memset(num1,0,4*sum);   
        memset(num2,0,4*sum);   
        int total = sum;    
        sum /= 2;   
        for (i=0;i<=V[1]*M[1];i+=V[1])   
            num1[i] = 1;    
        for(i=2;i<=N;++i)   
        {   
            for(j=0;j<=total;++j)   
            {   
                for(int k=0;k<=V[i]*M[i];k+=V[i])    
                    num2[ j + k ] += num1[j];   
            }     
            for(j=0;j<=total;++j)   
            {   
                num1[j]=num2[j];   
                num2[j]=0;    
            }    
        }   
        for (i=sum;i>=0;--i)   
        {   
            if (num1[i]!=0)   
            {   
                cout<<total-i<<' '<<i<<endl;   
                break;   
            }    
        }   
    }   
    return 0;    
}   
