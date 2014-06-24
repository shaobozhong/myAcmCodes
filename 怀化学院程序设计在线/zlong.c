#include<stdio.h>
#include<string.h>

void zlong(char a[])
{
	int i,k=0,j,jl=0;
	char b[255][255];
	int c[255],max=0;
	for(i=0;i<=(int)strlen(a)-1;i++)
	{if (a[i]>='A'&&a[i]<='z')
	{
		k++;
		if (a[i+1]<'A'||a[i]>'z')
		{
			if (max<k) max=k;
			for(j=i-k+1;j<=i;j++)
				b[jl][j-i+k-1]=a[j];
			b[jl][j-i+k-1]='\0';
			c[jl]=k;
			jl++;
			k=0;
			i++;
		}
	}
	}
	for(i=0;i<=jl-1;i++)
	{
		if (c[i]==max) printf("%s ",b[i]);
	}
	printf("\n");
}



int main()
{
	char a[255];
	while(gets(a)&&strlen(a)>0)
	{
	zlong(a);	
	}
}