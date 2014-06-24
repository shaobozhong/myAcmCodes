#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	bool a[1000005];
	int i,j,m;
	freopen("G.in","r",stdin);
	m=(int)sqrt(1000004.0);
	memset(a,1,sizeof(a));
	a[1]=0;
	for(i=2;i<=m;i++)
	{
		if(a[i]!=0)
		{
			j=i*i;
		while(j<=1000004)
		{
			a[j]=0;
			j=j+i;
		}
		
		}

	}
	int n;
	while(cin>>n,n!=0)
	{
		if(a[2]==1&&a[n-2]==1)
		{
			printf("%d = %d + %d\n",n,i,n-i);
		    continue;
		}
		for(i=3;i<=n/2+1;i=i+2)
			if(a[i]==1&&a[n-i]==1)
			{
				printf("%d = %d + %d\n",n,i,n-i);
				break;
			}
	}
	return 0;
}