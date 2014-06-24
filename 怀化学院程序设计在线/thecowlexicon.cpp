#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int _dp[305];
char _str[305];
char _index[601][30];


int main()
{
	int _W,n,i,j,k,l,nen,_temp;
   while (scanf("%d%d",&_W,&n)!=EOF)
   {
	   getchar();
	   gets(_str);
	   for (i=0;i<n;++i)
	   {
		   _dp[i]=i+1;
	   }
       for (i=0;i<_W;++i)
       {
		   gets(_index[i]);
	   }
	   for (i=0;i<n;++i)
	   {
		   for (j=0;j<_W;++j)
		   {
			   nen=(int)strlen(_index[j]);
			   for (k=i,l=0;k<n&&l<nen;++k,++l)
			   {
                   if (_str[k]!=_index[j][l])  --l; 
			   }
			   if (l<nen) continue;
			   if (i==0) _temp=k-nen;
			   else _temp=_dp[i-1]+k-i-nen;
			   if (_dp[k-1]>_temp) _dp[k-1]=_temp;
		   }
		   if (_dp[i+1]>_dp[i]+1) _dp[i+1]=_dp[i]+1;
	   }
	   printf("%d\n",_dp[n-1]);
   }
	return 0;
}
