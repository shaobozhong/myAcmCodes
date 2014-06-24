#include<stdio.h>
#include<string.h>

int main()
{
	char s[257],key[17];
	int i,j,slen,keylen;

	while(scanf("%s",s)!=EOF)
	{
		slen=(int)strlen(s);
		while(scanf("%s",key),strcmp(key,"END")!=0)
		{
			if (strcmp(key,"NULL")==0) {printf("0 NULL\n");continue;}
			keylen=(int)strlen(key);
			for(i=0;i<slen;i++)
			{
				for(j=0;j<keylen;j++)
				{
					if (s[i+j]!=key[j]) break;
				}
				if (j>=keylen) break;
			}
			if (i==0||i==slen) printf("0 NULL\n");
			else 
			{
				printf("%d ",i);
				for(j=0;j<i;j++)
				{
					putchar(s[j]);
				}
				putchar('\n');
			}
		}
	}
	return 0;
}