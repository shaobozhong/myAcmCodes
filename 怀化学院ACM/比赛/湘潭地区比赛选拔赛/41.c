#include<stdio.h>
int m,w,total=0;
void panduan(int a[],int i,int s,int jl)
{
	int j,t;
if (total==w) return;
	s+=a[i];
	if (s>w) {if (s-a[i]>total) total=s-a[i];return;}
	t=a[i]; 
	a[i]=0;
	if (jl==m) {total=s;a[i]=t;return;}
	for(j=0;j<=m-1;j++)
	{
		if (a[j]!=0)
		{
		
	    panduan(a,j,s,jl+1);
       
	
		
		}
	}
a[i]=t;
}
int main()
{
	int n,i,j,a[11];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		total=0;
		scanf("%d%d",&m,&w);
		for(j=0;j<=m-1;j++)
			scanf("%d",&a[j]);
		for(j=0;j<=m-1;j++)
		{   
			panduan(a,j,0,1);
            
		}
	printf("%d\n",total);
	}
return 0;
}