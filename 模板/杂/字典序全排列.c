#include<stdio.h>
int n,n_;char a[9];
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

void zidian(int k)
{ 
	//char temp=80;
	
	int q,h,i;
	if (k<=n_)
	{ 
		for(i=0;i<=n-1;i++)
			printf("%c",a[i]);
		printf("\n");
		for(i=n-1;i>=0;i--)
			if (a[i]>a[i-1]) {q=i-1;break;}
			h=q+1;
			for(i=q+2;i<=n-1;i++)
			{if (a[q]<a[i]/*&&temp>a[i]*/) {h=i;/*temp=a[i];*/}
			}
			
			if (q!=-1) swap(&a[q],&a[h]);
			for(i=q+1;i<=q+(n-q-1)/2;i++)
				swap(&a[i],&a[n+q-i]);
			zidian(k+1);
	}
}

int main()
{
	
	int i;
	
	while(scanf("%d",&n)+1)
	{	n_=1;
	for(i=0;i<=n-1;i++)
	{
		n_*=i+1;
		getchar();
		scanf("%c",&a[i]);
	}
    sort();
	zidian(1); 
	}
	return 0;
}