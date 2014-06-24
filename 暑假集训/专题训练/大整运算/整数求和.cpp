#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int resultz[10000],resultx[10000],count1;
int xplus(char *s,char *t,int &count)
{
    int add,k;
    int i,j;
    char  sx[10000],tx[10000],temp[10000];
    count=9999;
    for(i=(int)strlen(s)-1;i>=0;i--)
    {
        temp[count--]=s[i];
        if (s[i-1]=='.') break;
    }

    if (i<0) {count=9999;i=0;}
    for(i=0;i<=9999-count-1;i++)
        sx[i]=temp[9999-i];
    count1=9999;
    for(j=(int)strlen(t)-1;j>=0;j--)
    {
        temp[count1--]=t[j];
        if (t[j-1]=='.') break;
    }
    if (j<0){count1=9999;j=0;}
    for(j=0;j<=9999-count1-1;j++)
        tx[j]=temp[9999-j];
    while(i<j)
    {
        if (i>0)
        {
            for(k=i;k>=1;k--)
        sx[k]=sx[k-1];
        sx[0]='0';
        i++;
        }
        else sx[i++]='0';
    }
    while(j<i)
    {
        if (j>0)
        {
            for(k=j;k>=1;k--)

        tx[k]=tx[k-1];
        tx[0]='0';
        j++;
        }
        else tx[j++]='0';
    }
    sx[i]=0;
    tx[i]=0;
    add=0;
    for(k=0;k<=i-1;k++)
    {
        add+=sx[k]+tx[k]-'0'-'0';
        resultx[i-1-k]=add%10;
        add/=10;
    }
    for(i=j;i>=0;i--)
    {
        if (resultx[i-1]!=0||i==0) break;
    }
    if ((i!=-1&&i!=0)||(i==0&&resultx[i]==0)) resultx[i]=-1;
    return add;
}

void zplus(char *s,char *t,int add,int count)
{
    int i,j,count2;
   int slen=(int)strlen(s);
   int tlen=(int)strlen(t);
   count2=0;
   if (count1!=9999) tlen--;
   if (count!=9999)  slen--;
   for(i=slen+count-10000,j=tlen+count1-10000;i>=0&&j>=0;i--,j--)
   {
       add+=s[i]+t[j]-'0'-'0';
       resultz[count2++]=add%10;
       add=add/10;
   }
    while(i>=0)
    {
       add+=s[i--]-'0';
       resultz[count2++]=add%10;
       add=add/10;
    }
    while(j>=0)
    {
         add+=t[j--]-'0';
       resultz[count2++]=add%10;
       add=add/10;
    }
    if (add==0&&count2!=0) count2--;
    else resultz[count2]=add;
    for(i=count2;i>=0;i--)
        cout<<resultz[i];
}
void plus(char *s,char *t,int &count)
{
    int add,i;
    memset(resultz,0,sizeof(resultz));
    memset(resultx,0,sizeof(resultx));
    add=xplus(s,t,count);
    zplus(s,t,add,count);
    if (resultx[0]!=-1) cout<<".";
        for(i=0;i<=9999;i++)
        {
            if (resultx[i]==-1) break;
            cout<<resultx[i];
        }
        cout<<endl;
}

int main()
{
    int count;
    char s[10000],t[10000]; 
    void plus(char *s,char *t,int &count);
    while(cin>>s>>t)
    {
        plus(s,t,count);
    }
    return 0;
}  