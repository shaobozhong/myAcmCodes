#include<stdio.h>
#include<string.h>
#include<stdio.h>
int main()
{
    int i;
    int a,b,temp;
    char c[81]={0};
	
	
	while(gets(c))
	{a=1;b=1;
	   for (i=0;i<=(int)strlen(c)-1;i++)
	   {	
		   
		   if (c[i]>='A'&&c[i]<='Z')
		   {  
			   
			   if (a>26) a%=26;
			   c[i]=c[i]+a;
			   if(c[i]>'Z') c[i]=(c[i]-64)%26+64;
			   temp=b;b+=a;a=temp;}
	   }
	   printf("%s\n",c);
	}
	return 0;
}