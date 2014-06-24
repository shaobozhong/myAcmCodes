#include<iostream>
#include<string>
using namespace std;
typedef struct
{
    int g,m,sl;
}aa;
int main()
{
    int i,j,k,t,n,p,v1,v2;
    char s[30];
    aa c[202];
    while(cin>>n&&n!=0)
    {
        for(i=1;i<=n;i++)
        {
            cin>>s>>c[i].g>>c[i].m>>c[i].sl;
            if(strcmp(s,"Canada")==0)
            {
                c[0].g=c[i].g;c[0].m=c[i].m;c[0].sl=c[i].sl;
                i--;
                n--;
            }
        }
        for(i=0;i<=2;i++)
        {
            for(j=0;j<=2;j++)
            {
                for(k=0;k<=2;k++)
                {
                    v1=c[0].g*i+c[0].m*j+c[0].sl*k;
                    for(p=1;p<=n;p++)
                    {
                        v2=c[p].g*i+c[p].m*j+c[p].sl*k;
                        if(v1<=v2) break;
                    }
                    if(p>n) 
                    {
                        cout<<"Canada win"<<endl;
                        break;
                    }
                
                }
                if(p>n) break;
            }
            if(p>n) break;
        }
        if(i>2) cout<<"Canada cannot win"<<endl;
    }
    return 0;
}   