#include<stdio.h>
int step;


void  zhui(int x,int y,int temp)
{ 
	printf("*");
    if (x==y) { if (step>temp) step=temp;}
	if (step>temp&&temp<30)
	{
     if (step>temp+1) zhui(x+1,y,temp+1);
	 if (step>temp+1) zhui(x-1,y,temp+1);	
     if (step>temp+1&&x<y) zhui(2*x,y,temp+1);	
	}

}


int main()
{int x,y;
	 while(scanf("%d%d",&x,&y)+1)
	{
	
     step=100000;
	 zhui(x,y,0);
     printf("%d\n",step);
	}
return 0;
}
