#include<stdio.h>
void main()
{
 int i,j,*pi,*pj;
pi=&i;
pj=&j;
i=5;
j=7;
printf("\n%d\t%d\t%d\t%d",i,j,pi,pj);
printf("\n%d\t%d\t%d\t%d",&i,&i,&j,&j);
}  
  
