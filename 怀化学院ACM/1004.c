
#include<stdio.h>
int main()
{int i,j,n;
while(scanf("%d",&n)+1)
{for (i=1;i<=n/2;i++)
{
if (n%2==0)
{for (j=1;j<=(n/2-i);j++)
printf(" ");
}	
else
{for (j=1;j<=(n/2+1-i);j++)
printf("  ");
}
for (j=1;j<=2*i-1;j++)
printf("* ");
printf("\n");
}

for (i=n-i+1;i>=1;i--)
{
	if (n%2==0)
{for (j=1;j<=(n/2-i);j++)
printf("  ");
}	
else
{for (j=1;j<=(n/2+1-i);j++)
printf(" ");
}
for (j=1;j<=2*i-1;j++)
printf("* ");
printf("\n");
}
printf("\n");
}

return 0;
}
