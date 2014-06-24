#include<stdio.h>
#include<string.h>

int main() 
{
    int sumA=1,sumB=1;
		int i;
	char a[7],b[7];
    while((scanf("%s%s",a,b))!=EOF)
	{
      sumA=1;sumB=1;
	for(i=0;i<=(int)strlen(a)-1;i++)
		sumA*=(int)a[i]-64;
	for(i=0;i<=(int)strlen(b)-1;i++)
		sumB*=(int)b[i]-64;
	if (sumA%47==sumB%47) printf("GO\n");
	else printf("STAY\n");
	}
    return 0;
}

