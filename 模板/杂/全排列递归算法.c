#include<stdio.h>
#include<string.h>

void swap(char *a,char *b)
{
char temp;
temp=*a;
*a=*b;
*b=temp;
}


void sort(char *a,int n)
{
	int i,j;
	for (i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if (a[j]<a[i]) {swap(&a[j],&a[i]); } else break;
		}
	}
   
}


void pailie(int k,int n,char a[])
{   
	int i;
	if (k>n) 
	{
	for(i=1;i<=n;i++)
	printf("%c ",a[i]);
	printf("\n");
	}
    else
	{
		for(i=k;i<=n;i++)
		{
			swap(&a[k],&a[i]);
			pailie(k+1,n,a);
			swap(&a[k],&a[i]);
		}
	}
}

int main()
{
	char a[255]={0};
	int n,i;
while(scanf("%d",&n),n!=0)
{
	for(i=1;i<=n;i++)
	{
		getchar();
		scanf("%c",&a[i]);
	}
	sort(a,n);
    pailie(1,n,a);
   
}
return 0;
}