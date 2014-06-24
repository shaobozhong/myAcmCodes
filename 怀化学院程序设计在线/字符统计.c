#include<stdio.h>
#include<string.h>
void myprocess(char *p, int a[],int n)
{
	int i;
	for(i=0;i<=n;i++)
	{
		if (*(p+i)>='A'&&*(p+i)<='Z') {(*a)++;continue;}
		if (*(p+i)>='a'&&*(p+i)<='z') {(*(a+1))++;continue;}
		if (*(p+i)==' ') {a[2]++;continue;}
		if (*(p+i)>='0'&&*(p+i)<='9') {(*(a+3))++;continue;}
        a[4]++; 
	}
	
}

int main()
{
	char  p[255];
	int a[5]={0},n,i;
	gets(p);
	n=strlen(p)-2;
	myprocess(p,a,n);
	for(i=0;i<=4;i++)
		printf("%d ",*(a+i));
	printf("\n");
	return 0;
}