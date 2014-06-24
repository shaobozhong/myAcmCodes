#include<stdio.h>
#include<math.h>

bool a[5000001];


void  shai()
{ 
	int i,j;
for(i=2;i<=5000000;i++)
{
	a[i]=1;
}
 a[1]=0;
for(i=2;i<=sqrt(5000000);i++)
{
	if (a[i]!=0)
	{
		
	for(j=i*i;j<=5000000;j=j+i)
		 a[j]=0;
	}
}

}


int main()
{int n,m,i;
	shai();
scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&n);
	
		if (a[n]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}