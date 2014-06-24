#include<stdio.h>

void work(int n,int d,int a[])
{
	int i=1,k=0,m=0;
	if (d==1) {printf("%d\n",n);return;}
	i=1;
    do
	{ 
		if (i>n) {i=1;}
		
		
		if (*(a+i)!=1)
		{
			
			k++;
			if (k%d==0) {*(a+i)=1;m++;}
		}
       i++;	
	}	while(m!=n-1);
		for(i=1;i<=n;i++)
			if (*(a+i)!=1) {printf("%d\n",i);break;}
			
}

int main()
{
	int a[65536]={0};
	int n,d;
	scanf("%d%d",&n,&d);
	work(n,d,a);
	return 0;
}