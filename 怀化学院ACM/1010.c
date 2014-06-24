#include <stdio.h>
#include<string.h>
int main()
{ 
	char str[300];
	int k;int len;
	int i; 
	while(scanf("%s",str)!=-1)
	{     
		k=0;    
		len=strlen(str);    
		for(i=len-1;i>=0;i--)    
		{     
			if (str[i]<'p'&&str[i]>='a')  
			{
				k=0;
				break;
			}
			if(str[i]>='p'&&str[i]<='z')      
				k++;     
			else 
				if(str[i]=='C'||str[i]=='D'||str[i]=='E'||str[i]=='I')     
				{      
					if(k>=2)       
						k--;      
					else       
					{       
						k=0;       
						break;      
					}     
				}     
				else 
					if(str[i]=='N')     
					{      
						if(k==0)       
							break;     
					}     
					else     
					{      
						k=0;      
						break;     
					}    
		}    
		if(k==1)     
			printf("YES\n");
		else     
			printf("NO\n");
	}    
	return 0;
}
