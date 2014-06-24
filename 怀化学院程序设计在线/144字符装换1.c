#include<stdio.h>
#include<string.h>
void main()
{
	int i,j;
	char a[100]={0};
	gets(a);

		for(i=0;i<=(int)strlen(a)-1;i++)
		{
			if (a[i]>='A'&&a[i]<='Z') a[i]+=32;
			else if(a[i]>='a'&&a[i]<='z') a[i]-=32;

		}
		for(j=0;j<=i-1;j++)
			printf("%c",a[j]);
		printf("\n");


}