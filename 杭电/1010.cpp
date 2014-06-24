#include<stdio.h>

int main()
{
	int count=0;
	char ch;
	while(scanf("%c",&ch)!=EOF)
	{
		
		if (ch=='\n') count++;
	}
	printf("%d\n",count);
	return 0;
}