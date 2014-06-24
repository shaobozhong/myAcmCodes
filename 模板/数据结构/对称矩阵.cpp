#include<iostream>
using namespace std;

int main()
{
    int *num;
	int i,j,n,m,x=0,y=0;
while(scanf("%d",&n)+1)
{
	num=new int[n*(n+1)/2+1];
	for(i=1;i<=n;i++)
		for(j=0;j<n;j++)
		{
			cin>>m;
			if (j<=i-1) num[i*(i-1)/2+j]=m;
		}
   for(i=0;i<=n*(n+1)/2-1;i++)
	   cout<<num[i]<<" ";
       cout<<endl;
	   cin>>x>>y;
	   if (y<=x) cout<<x*(x-1)/2+y<<endl;
       else cout<<y*(y-1)/2+x<<endl;
       free(num);
}
 
	return 0;
}