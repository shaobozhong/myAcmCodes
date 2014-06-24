#include<iostream>
using namespace std;

int main()
{
	int map[100][100];
	int ccount,rcount,r,c,n,i,j;
	int csum[100],rsum[100];
	while (cin>>n&&n)
	{
		ccount=0;rcount=0;
		memset(rsum,0,sizeof(rsum));
		memset(csum,0,sizeof(csum));
		for(i=1;i<=n;i++)
		{
			
			for(j=1;j<=n;j++)
			{
				scanf("%d",&map[i][j]);
				rsum[i]+=map[i][j];
				
			}
			if (rsum[i]%2!=0) {rcount++;r=i;}
		}
		for(i=1;i<=n;i++)
		{
		
			for(j=1;j<=n;j++)
			{
				csum[i]+=map[j][i];
			}
			if (csum[i]%2!=0) {ccount++;c=i;}
		}
		if (rcount==0&&ccount==0) {puts("OK");continue;};
		if (rcount==1&&ccount==1)
		{
           for(i=1;i<=n;i++)
		   {
			   if (c==i) { printf("Change bit (%d,%d)\n",r,i); break;}
		   }
		   if (i>n) puts("Corrupt");
		}
		else puts("Corrupt");
	}
	return 0;
}