#include<stdio.h>
void main()
{
	int n;long a[1000][2]={0};
	int s=0,i,j,t;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	for(j=0;j<2;j++)
		scanf("%d",&a[i][j]);
	for(j=0;j<n-1;j++)
	for(i=0;i<n-1-j;i++)
		if(a[i][0]>a[i+1][0])
		{
		t=a[i][0];
		a[i][0]=a[i+1][0];
		a[i+1][0]=t;
		t=a[i][1];
		a[i][1]=a[i+1][1];
		a[i+1][1]=t;
		}
		else 
		{
			if (a[i][1]<a[i+1][1]&&a[i][0]==a[i+1][0])
			{
				t=a[i][1];
		a[i][1]=a[i+1][1];
		a[i+1][1]=t;
			}

		}
		
	
	
	printf("%d\n",s);
}

