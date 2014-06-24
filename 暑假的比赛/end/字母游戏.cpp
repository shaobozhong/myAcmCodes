#include<iostream>
#include<string>
using namespace std;
string data[40002];//记录字典
string jilu[40];//记录重复的最高
int main()
{
 int top=0;
 int a[]=
 {
  2,5,4,4,1,
  6,5,5,1,7,
  6,3,5,2,3,
  5,7,2,1,2,
  4,6,6,7,5,7
 };
 string temp,pipei;
 int sum,i,j,k,n,g,b[100],c[100],e[28],max,max1,max2,geshu,xxx;  
 while(cin>>temp,temp!=".")
 {
  top++;
  data[top]=temp;
 }
 while(cin>>pipei)
 {
  max=0;
  for(i=0;i<=28;i++)
   b[i]=0;
  for(i=0;i<pipei.size();i++)
   b[pipei[i]-97]++;
  for(i=1;i<=top;i++)
  {
   max1=0;
   for(j=0;j<=28;j++)
    c[j]=b[j];
   k=pipei.size()-data[i].size();
   if(k==0)//长度能够匹配
   {
    for(j=0;j<data[i].size();j++)
    {
     c[data[i][j]-97]--;
     max1+=a[data[i][j]-97];
     if(c[data[i][j]-97]<0)
     {
      max1=0;
      break;
     }
    }
    if(max1>max)
    {
     geshu=1;
     jilu[geshu]=data[i];
     max=max1;
    }
    else if(max1==max&&max!=0)
    {
     geshu++;
     jilu[geshu]=data[i];
    }
   }
   else if(k>0)
   {
    max1=0;
    for(j=0;j<data[i].size();j++)
    {
     c[data[i][j]-97]--;
     max1+=a[data[i][j]-97];
     if(c[data[i][j]-97]<0)
     {
      max1=0;
      break;
     }
    }
    if(max1>max)
    {
     geshu=1;
     jilu[geshu]=data[i];
     max=max1;
    }
    else if(max1==max&&max!=0)
    {
     geshu++;
     jilu[geshu]=data[i];
    }
    if(max1!=0&&k>2)
    {
     for(g=i+1;g<=top;g++)
     {
      for(xxx=0;xxx<=27;xxx++)
       e[xxx]=c[xxx];
      max2=0;
      if(data[g].size()<=k)
      {
       for(j=0;j<data[g].size();j++)
       {
        e[data[g][j]-97]--;
        max2+=a[data[g][j]-97];
        if(e[data[g][j]-97]<0) 
        {
         max2=0;
         break;
        }
       }
      }
      if(max1+max2>max&&max2!=0)
      {      
       geshu=1;
       jilu[geshu]=data[i];
       jilu[geshu]+=" ";
       jilu[geshu]+=data[g];
       max=max1+max2;
      }
      else if(max1+max2==max&&max2!=0)
      {
       geshu++;
       jilu[geshu]=data[i];
       jilu[geshu]+=" ";
       jilu[geshu]+=data[g];
      }
     }
    }
   }
  }
  cout<<max<<endl;
  if(max>0)
   for(j=1;j<=geshu;j++)
    cout<<jilu[j]<<endl;
 }
 return 0;
}
