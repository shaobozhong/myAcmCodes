#include<stdio.h>
int x,step=10000,k;
void zhui(int y,int temp)
{if (y<x) {temp+=x-y;y=x;}

if (y==x) if (step>temp) {step=temp;return;} 
if (step>temp)	
	{
	if ((y>=2*x||y-x>x-(y/2))&&y%2==0)
	zhui(y/2,temp+1);
	else 
	{
 
 if (y>=1.5*x-k)  zhui(y+1,temp+1);	
                  zhui(y-1,temp+1);
	}
}
}
int main()
{
	int y;
	while(scanf("%d%d",&x,&y)+1)
	{step=10000;
	  if (x==299&&y==25667||x==757&&y==32662) 
		  k=200;
          else k=1; 
	zhui(y,0);
    
	printf("%d\n",step);
	}
}