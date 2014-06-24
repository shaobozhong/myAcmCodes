#include<stdio.h>
#include<string.h>
void main()
{
	char a[1001];
	int i;
	gets(a);
	for(i=(int)strlen(a)-2;i>=0;i--)
		printf("%c",a[i]);
	printf("\n");
}