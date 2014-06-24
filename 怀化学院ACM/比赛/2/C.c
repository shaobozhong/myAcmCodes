#include<stdio.h>
struct a
{
int x;
int b;   
};


int main()
{
int i,j,s,n;
struct a b[8002];int c[8002]={0};
  while(scanf("%d",&n)+1)
  {
  b[1].x=0;
  for(i=2;i<=n;i++)
  scanf("%d",&b[i].x);
  for(i=n;i>=1;i--)
  {s=0;
	  for(j=1;j<=n;j++)
	  {
          if (c[j]!=1) s++; 
		  if(s==b[i].x+1) {b[i].b=j;c[j]=1;break;}
	  }
  }
  s=0;
  for(i=1;i<=n;i++)
	  s=s+i;
  if (s%2==0) s=n-2;else s=n-1;
  for (i=1;i<=n;i++)
	  if (b[i].b==s) {printf("%d\n",i);break;}
  for(i=1;i<=n;i++)
  c[i]=0;
  
  }
return 0;
}