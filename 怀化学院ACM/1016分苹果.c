#include<stdio.h>
int n,m,so;

void fen(int i,int s,int k)
{int j;
	if (s<n&&i<=m)
	{
		for(j=k;j<=n&&j<=n-s;j++)
		{
			s=s+j;
		    if (s==n&&i==m) so++;
			k=j;
			fen(i+1,s,k);
		    s-=j;
		}

	}
}

int main()
{int t,i;
scanf("%d",&t);
for (i=1;i<=t;i++)	
{so=0;
	scanf("%d%d",&n,&m);
	fen(1,0,0);
printf("%d\n",so);
}
return 0;
}