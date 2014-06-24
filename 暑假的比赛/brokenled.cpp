#include<iostream>
using namespace std;
int a[]={119,36,93,109,46,107,123,37,127,111};
int digit[200]={0};
int bin[]={1,2,4,8,16,32,64,128}; //2^n
int ans,base,broken;
char t;
int solve()
{
int ret=0,x,i;
x = base | broken;
for(i=0;i<=9;i++)
{
   if((base & a[i])==base && (a[i] & x)==a[i]) ret++;
}
/*for(i=0;i<=9;i++)
{
   if((a[i]|base) == a[i] && (x|a[i])==x )ret++;
}*/
return ret;
}
int main()
{
	char temp;
int i,n,j,c=0;
while(scanf("%d",&n)!=EOF&&(n+1))
{
   for(i=1,getchar(),broken=0;i<=7;i++) //i=0?1
   {
	   cin>>t;
    if(t!='-')
    {
     broken |= bin[t-'a'];
    }
   }
   for(j=1,ans=1;j<=n;j++){
    for(i=0,base=0,getchar();i<=6;i++)
    {
		cin>>t;
     if(t!='-')
     {
      base |= bin[t-'a'];
     }
    }
    ans*=solve();
   }
   printf("Case %d: %d\n",++c,ans);
}
return 0;
}
