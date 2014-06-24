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
	for (i=1;i<=n-1;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if (a[j]<a[i]) swap(&a[j],&a[i]); 
	
		}
   
	}
}


void pailie(int k,int n,char a[])
{   
	int i,j;
	char temp;
	if (k>n) 
	{
	for(i=1;i<=n;i++)
	printf("%c",a[i]);
	printf("\n");
	}
    else
	{
		for(i=k;i<=n;i++)
		
		{   if(i>k){
			temp=a[i];
			for(j=i;j>=k;j--)
				a[j]=a[j-1];
			a[k]=temp;
		}
			pailie(k+1,n,a);
			if(i>k)  
			{ temp=a[k];
			for(j=k;j<=i-1;j++)
				a[j]=a[j+1];
			a[i]=temp;
		}
		}
		
	
		
	}
}

int main()
{
	char a[255]={0};
	int n,i;
while(scanf("%d",&n)+1)
{
	for(i=1;i<=n;i++)
	{
		getchar();
		scanf("%c",&a[i]);
	}
	sort(a,n);
    pailie(1,n,a);
printf("\n");   
}
return 0;
}