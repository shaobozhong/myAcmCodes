#include <iostream>
using namespace  std;
__int64 a[21];

void getnum()
{  
	__int64 t=20;
    a[2]=21;
  
    for (int i=3;i<=20;++i)
    {
        t*=5;
        a[i]=a[i-1]+t;
    }
}

int main()
{
    int n;
    getnum();
    while (cin>>n&&n)
    {
        if(n==1)
        {
            cout<<"1 1"<<endl;
            continue;
        }
        __int64 res=a[n];
        for (int i=1;i<=n;++i)
        {
            res--;
            res=(res/5)*4;
        }
        cout<<a[n]<<" "<<res+n<<endl;
    }
    return 0;
} 