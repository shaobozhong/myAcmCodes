#include<stdio.h>
#include<string.h>

int main()
{
	char str[1005];
	int i;
	int len;
	while(gets(str))
	{
        len=(int)strlen(str);
		for(i=0;i<len-2;++i)
		{
			if (str[i]=='y')
			{
				if (str[i+1]=='o')
				{
					if (str[i+2]=='u') 
					{
						str[i]='w';
						str[i+1]='e';
						str[i+2]=0;
						i+=2;
					}
				}
			}
		}
		for(i=0;i<len;++i)
		{
			if (str[i]==0) continue;
			putchar(str[i]);
		}
		putchar('\n');
	}
	return 0;
}

