#include<stdio.h>
int n;char a[9]={0};
void swap(char *a,char *b)
{
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void sort()
{
	int i,j;
	for(i=0;i<=n-2;i++)
		for(j=i+1;j<=n-1;j++)
		{
			if (a[i]>a[j]) swap(&a[i],&a[j]);
		}
}
int main()
{int q,h,i,k,n_;
	
	while(scanf("%d",&n)+1)
	{n_=1;
	for(i=0;i<=n-1;i++)
	{n_*=i+1;
		getchar();
	scanf("%c",&a[i]);
	}
    sort();
	for(k=1;k<=n_;k++)
	{
		for(i=0;i<=n-1;i++)
		printf("%c",a[i]);
		printf("\n");
    for(i=n-1;i>=0;i--)
	if (a[i]>a[i-1]) {q=i-1;break;}
    h=q+1;
		for(i=q+2;i<=n-1;i++)
		{if (a[q]<a[i]) {h=i;}
		}
    
	if (q!=-1) swap(&a[q],&a[h]);
	for(i=q+1;i<=q+(n-q-1)/2;i++)
	swap(&a[i],&a[n+q-i]);
	}
	printf("\n");
	}
return 0;}