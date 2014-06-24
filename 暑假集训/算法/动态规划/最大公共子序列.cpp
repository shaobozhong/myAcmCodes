#include<iostream>
#include<string>
using namespace std;

   int a[1000][1000];


int main()
{
  string s,t;
  int i,j,slen,tlen,max;
   while(cin>>s>>t)
   {
	   slen=(int)s.size();
	   tlen=(int)t.size();
	   max=slen>tlen?slen:tlen; 
       for(i=0;i<=max;i++)
	   {
		   a[i][0]=0;
		   a[0][i]=0;
	   }
	   for(i=1;i<=slen;i++)
	   {
		   max=0;
		   for(j=1;j<=tlen;j++)
		   {
              if (s[i-1]==t[j-1]) max=a[i-1][j-1]+1;
			  else max=a[i-1][j-1];
			  if (max<a[i-1][j]) max=a[i-1][j];
			  if (max<a[i][j-1]) max=a[i][j-1]; 
			  a[i][j]=max;
		   }
	   }
      cout<<a[slen][tlen]<<endl;
   }
	return 0;
}