#include <stdio.h>
int main()
{
  int x,y,i,j,s,t,total=0;
  scanf("%d%d",&x,&y);
  for(i=x;i<=y;i++)
  {
	  j=i;
	  t=1000;
	  s=0;
	  while(j!=0)
	  {
		  s+=j%10*t;
		  t/=10;
		  j/=10;
	  }
	  if (s==i) total++;

  }
  printf("%d\n",total);
	return 0;
}