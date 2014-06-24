#include<stdio.h>
#include<math.h>
int prime(int n)
{
	int i;
	if (n<=1) return 0;
	for(i=2;i<=sqrt(n);i++)
		if (n%i==0) break;
	if (i>sqrt(n)) return 1;
	else return 0;
}

int main()
{
	int x,y,i,sum=0;
scanf("%d%d",&x,&y);
for(i=y;i>=x+2;i--)
if (prime(i)&&prime(i-2)) {sum=2*i-2;break;}
 printf("%d\n",sum);
	return 0;
}