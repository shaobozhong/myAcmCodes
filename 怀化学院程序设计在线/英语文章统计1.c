#include"stdio.h"
#include"string.h"	
char passege[100][1025];
int main()
{
	int i,j,d=0,c[100],z[100];
	for(i=0;i<100;i++)
	{
		gets(passege[i]);
		if(passege[i][0]=='#'&&passege[i][1]=='#')
			break;
		else d++;
	}
	for(i=0;i<d;i++)
	{
		c[i]=1;
		z[i]=strlen(passege[i]);
		for(j=0;j<strlen(passege[i]);j++)
		{
			if(passege[i][j]==' ')
				c[i]++;
		}
	}
	printf("%d\n",d);
	for(i=0;i<d;i++)
		printf("%d %d\n",c[i],z[i]-1);
	return 0;
}


