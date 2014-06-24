#include<stdio.h>
int a[100000]={0},temp=0;
int x,y;
int  min(int i,int j,int k)
{ void zhui(int i,int temp);
  int s;
	if (a[i]==0) zhui(i,temp+1);
	if (a[j]==0) zhui(j,temp+1);
	if (a[k]==0) {if (2*k<x) a[k]=10000;else zhui(k,temp+1);}
s=a[i];
if (s>a[j]) s=a[j];
if (s>a[k]) s=a[k];
return(s);
}

void zhui(int i,int temp)
{   printf("*");
	int small;
	
	if (temp>30||i<0) {a[i]=10000;return;}
	if (i==x) {a[i]=0;return;} 
	small=min(i+1,i-1,i/2);
	a[i]=small+1;
}



int main()
{
while(scanf("%d%d",&x,&y)+1)
{
zhui(y,0);	
printf("%d\n",a[y]);
}
return 0;
}