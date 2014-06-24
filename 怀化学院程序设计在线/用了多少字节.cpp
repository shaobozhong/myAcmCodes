#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char a[101];
	int sum,step,count,i,t=0;
	sum=0;
	while(gets(a))
	{
		
		if (strcmp(a,"")==0) {t++;printf("  #program %d:%2d\n",t,sum);sum=0;continue;}
		i=0;
		while(i<(int)strlen(a))
		{
			for(;i<(int)strlen(a);i++)
			{
				if (a[i]=='w') 
				{
					step=2;
					break;
				}
				else if (a[i]=='c')
				{
					step=1;
					break;
				}
			}
			count=0;
           for(i=i+1;i<(int)strlen(a);i++)
		   {
			   if (a[i]==',') count++;
			   if (a[i]==';') {i++;sum+=(count+1)*step;break;}
		   }
		}
	}
	t++;printf("  #program %d:%2d\n",t,sum);
	return 0;
}
 
