#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	int t,n,i,j,k;
	scanf("%d",&t);
	while(t--)
	{
       scanf("%d",&n);
	   getchar();
	   while(n--)
	   {
		    getline(cin,str);
		    for(i=0;i<str.size();i++)
		   {
			   if (i!=0) putchar(' ');
			   for(j=i+1;j<str.size();j++)
			   {
				   if (str[j]==' ') break;
			   }
			   for(k=j-1;k>=i;k--)
			   {
				   putchar(str[k]);
			   }
			   i=j;
		   }
			putchar('\n');
	   }
	  getline(cin,str);
	   if (t>0) putchar('\n');
	} 
	return 0;
}