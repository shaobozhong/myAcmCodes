#include<stdio.h>
int a[900001];
void quik(int s,int t)
{
	int i=s,j=t;
	if (s<t)
	{
		a[0]=a[s];
		do 
		{
			while(j>i&&a[j]>a[0])
				j--;
			if (i<j)
			{
				a[i]=a[j];
				i++;
			}
			while(i<j&&a[i]<a[0])
				i++;
			if (i<j)
			{
				a[j]=a[i];
				j--;
			}
		}while(i<j);
		a[i]=a[0];
		quik(s,j-1);
		quik(j+1,t);
	}
}


int main()
{   
	int n,i;
	while(scanf("%d",&n)+1)
	{
		for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
        quik(1,n);
    for(i=n;i>=n-2;i--)
		printf("%d ",a[i]);
	printf("\n");
	}
return 0;
}