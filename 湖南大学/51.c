#include<stdio.h>
int n,m,min=100000;
struct shop
{
	int b,p;
};


void work(int i,int j,int pr[],struct shop c[],int s)
{ 
	int k;
	if (s>min) return; 
	if (i>n-1) {if (min>s) min=s;return;}
	if (j>m-1) return;
	if (c[j].b==pr[i]) {i++;s+=c[j].p;}
    for(k=j+1;k<=m;k++)
		 if (c[j].b!=n)
		work(i,k,pr,c,s);
}

int main()
{
struct shop a[100000],c[100000];
	int i,j,pr[102],k;
	while(scanf("%d%d",&n,&m)>0&&n!=0||m!=0)
	{
		k=0;
		min=100000;
         for(i=0;i<=n-1;i++)
			 scanf("%d",&pr[i]);
		 for(i=0;i<=m-1;i++)
			 scanf("%d%d",&a[i].b,&a[i].p);
		 for(i=0;i<=m-1;i++)
		 {
			 for(j=0;j<=n-1;j++)
                 if (a[i].b==pr[j]) {c[k].p=a[i].p;c[k].b=a[i].b;k++;break;}
		 }
		 m=k;
		 for(j=0;j<=k-1;j++)
		 work(0,j,pr,c,0);
		  if (min==100000) printf("Impossible\n");
		  else printf("%d\n",min);
	}
	return 0;
}