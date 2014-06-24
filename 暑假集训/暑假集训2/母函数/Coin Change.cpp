#include<iostream>
using namespace std;

int main()
{
   int n;
   int count1;
   int i,j,k,l,m;
   while(scanf("%d",&n)!=EOF)
   {
	   count1=0;
	   for(i=0;i<=100&&i<=n;++i)
	   {
		   for(j=0;i+j<=100&&5*j<=n-i&&j<=n/5;++j)
		   {
			   for(k=0;i+j+k<=100&&10*k<=n-i-5*j&&k<=n/10;++k)
			   {
				   for(l=0;i+j+k+l<=100&&25*l<=n-i-5*j-10*k&&l<=n/25;++l)
				   {
                     
					   m=(n-i-5*j-10*k-25*l);
					   if (m%50==0)
					   {
						   if (i+j+k+l+m/50<=100)
					       ++count1;
					   }
				   }
			   }
		   }
	   }
	   printf("%d\n",count1);
   }
	return 0;
}