#include<stdio.h>
#include<string.h>

int main()
{
	int temp;
	char str[30];
	char data[201];
	int i;
	while(gets(str),strcmp(str,"ENDOFINPUT")!=0)
	{
		if (strcmp(str,"START")==0)
		{
			while(gets(data),strcmp(data,"END")!=0)
			{
				for(i=0;i<(int)strlen(data);i++)
				{
					if (data[i]>='A'&&data[i]<='Z') 
					{
						temp=data[i]-5;
						if (temp>=65) putchar(temp);
						else 
						{
							putchar(temp+26);
						}
					}
					else 
					{
						putchar(data[i]);
					}
				}
				putchar('\n');
			}
		}
	}
	return 0;
}