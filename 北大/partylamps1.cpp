#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int n,c,t;
bool f[101];
bool g[101];
int last[101];

bool judge()
{
     for(int i=1; i<=n; i++)
             if(last[i]!=-1&&last[i]!=g[i])
              return false;
     return true;
}

void turn1()
{
     for(int i=1; i<=n; i++)
           g[i]=!g[i];
}

void turn2()
{
     for(int i=1; i<=n; i+=2)
          g[i]=!g[i];
}

void turn3()
{
     for(int i=2; i<=n;i+=2)
             g[i]=!g[i];
}

void turn4()
{
     
     for(int i=0,k=1; k<=n;)
     {
           g[k]=!g[k];
           i++;
           k=3*i+1;
     }
}

int main()
{
    cin>>n;
    cin>>c;
    vector<string> vec;
    string s;
    for(int i=1; i<=n; i++)f[i]=1;
    for(int i=1; i<=n; i++)last[i]=-1;
    while(cin>>t&&t!=-1)
            last[t]=1;   
    while(cin>>t&&t!=-1)
          last[t]=0;
 
    int i1, i2, i3, i4,i;
    for(i1=0; i1<=1; i1++)
    for(i2=0; i2<=1; i2++)
    for(i3=0; i3<=1; i3++)
    for(i4=0; i4<=1; i4++){
              if( c>=(i1+i2+i3+i4)&&(c-(i1+i2+i3+i4))%2==0 )
              {
                      for(i=1; i<=n;i++)
                              g[i]=f[i];
                      if(i1)turn1();
                      if(i2)turn2();
                      if(i3)turn3();
                      if(i4)turn4();
                      
                      if(judge()){
                           for(s="",i=1; i<=n; i++)
                                 s+='0'+g[i];
                           vec.push_back(s);
                      }
              }
    }
    
    sort(vec.begin(),vec.end());
    if(vec.size()==0)cout<<"IMPOSSIBLE"<<endl;
    else{
       for(i=0; i<vec.size(); i++)
                cout<<vec[i]<<endl;
       }       
     
    return 0;
}
