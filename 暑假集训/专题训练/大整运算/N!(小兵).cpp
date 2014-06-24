#include<iostream>
using namespace std;
typedef struct
{
    int wei[100000];  //第n位的值
    int num;   //位数
}aa;    
aa a;
int work(int n)
{
    int i=0,j=0,temp=0,valid=1,carry;
    if(n==0||n==1)
    {
        a.wei[0]=1;
        a.num=1;
        return a.num;
    }
    else
    {
        a.wei[0]=1;
        for(i=2;i<=n;i++)
        {
            carry=0;
            for(j=0;j<valid;j++)
            {
                temp=a.wei[j]*i+carry;
                a.wei[j]=temp%10;
                carry=temp/10;
            }
            while(carry!=0)
            {
                a.wei[valid]=carry%10;
                carry/=10;
                valid++;
            }
        }
        
    }
    a.num=valid;  // 求得阶乘的位数
    return a.num;
}
int main()
{
    int i,n,t;
    while(cin>>n)
    {
        t=work(n);
        for(i=t-1;i>=0;i--) cout<<a.wei[i];
        cout<<endl;
    }
    return 0;
} 