#include<stdio.h>
#include<string.h>
int main()
{
	char a[1025];
	int i,k=0,z[1025]={0},le[1025]={0},pa=0;
    while(gets(a))
	{if (a[(int)strlen(a)-1]=='#'||a[(int)strlen(a)-2]=='#') break;
	pa++;k++;
    z[k]=(int)strlen(a);
	le[k]=1;
	for(i=0;i<=(int)strlen(a)-1;i++)
	{
		if (a[i]==' ') le[k]++;
		//if (a[i]>='A'&&a[i]<='z'&&(a[i+1]<'A'||a[i+1]>'z')&&a[i+1]!=39) le[k]++; 
	
	}
    
	}
	printf("%d\n",pa);
	for(i=1;i<=k;i++)
	{
		printf("%d %d\n",le[i],z[i]-1);
	}
	
	return 0;
}