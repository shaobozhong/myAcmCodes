/*
ID:shaoboz2
PROG: ride
LANG: C
*/
#include<stdio.h>
#include<string.h>

int main() 
{
	FILE *in,*out;
    int sumA=1,sumB=1;
		int i;
	char a[7],b[7];
	in=fopen("ride.in","r");
    out=fopen("ride.out","w");
    fscanf(in,"%s%s",a,b);
	for(i=0;i<=(int)strlen(a)-1;i++)
		sumA*=(int)a[i]-64;
	for(i=0;i<=(int)strlen(b)-1;i++)
		sumB*=(int)b[i]-64;
	if (sumA%47==sumB%47) fprintf(out,"GO\n");
	else fprintf(out,"STAY\n");
    return 0;
}

