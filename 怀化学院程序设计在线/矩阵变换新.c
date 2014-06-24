#include<stdio.h>
int main()
{
	int a[10002]={0},x,y,n,m,i,g=0,t=0,temp=0,b[10002];
	scanf("%d%d",&n,&m);
	for(i=0;i<=n*m-1;i++)
		scanf("%d",&a[i]);
	while(scanf("%d%d",&x,&y)>0&&x!=0||y!=0)
	{
		
		for(i=1;i<=g;i++)
		if (b[i]==(x-1)*m+y-1) break;
			if (i>g)
			{	
				g++;
			a[(x-1)*m+y-1]=-1;
            b[g]=(x-1)*m+y-1;
			} 
	}
	for(i=0;i<=n*m-1;i++)
	{
        if (t%m==0) temp=0; 
		if (a[i]!=-1) {printf("%d ",a[i]);t++;temp=1;}
		if (t%m==0&&temp!=0)  printf("\n");
	}
	for(i=1;i<=g;i++)
	{
		printf("0 ");
		t++;
		if (t%m==0) printf("\n");
	}
	return 0;
}