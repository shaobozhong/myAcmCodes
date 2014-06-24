#include<stdio.h>
int total,m,w;
void panduan(int a[],int i,int s,int jl)
{
	int j,t;
	if (total==w) return ;
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
	int n,i,j,k,a[11],t;
	
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{total=0;
	scanf("%d%d",&m,&w);
	for(j=0;j<=m-1;j++)
	{
		scanf("%d",&a[j]);
		if (a[j]==w) {printf("%d\n",w);break;}
	}
	if (a[j]==w) continue;
	for(j=0;j<=m-2;j++)
	{
		for(k=0;k<=m-2-j;k++)
			if(a[k]>a[k+1]) 
			{
				t=a[k];
				a[k]=a[k+1];
				a[k+1]=t;
			}
	}
	
	while(a[m-1]>w)
		m--;
	if (a[0]+a[1]>w) {printf("%d\n",a[m-1]);continue;}
	while(a[m-1]+a[0]>w)
		m--;
	if (a[0]+a[m-1]==w) {printf("%d\n",w);continue;}
	for(j=0;j<=m-1;j++)
		panduan(a,j,0,1);
	printf("%d\n",total);
	}
	return 0;
	}